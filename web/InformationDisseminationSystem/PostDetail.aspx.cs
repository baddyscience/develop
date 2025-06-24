using System;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using System.Web;

namespace WebInfoSystem
{
    public partial class PostDetail : System.Web.UI.Page
    {
        private int currentPostId = 0;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                SetUserUIState();

                // 获取并验证文章ID
                if (Request.QueryString["postid"] == null || !int.TryParse(Request.QueryString["postid"], out currentPostId))
                {
                    Response.Redirect("Index.aspx");
                }

                // 加载文章内容
                LoadPostDetail();

                // 加载评论
                LoadComments();

                // 加载推荐内容
                LoadRecommendations();

                // 加载分类导航
                LoadCategories();
            }
        }

        private void SetUserUIState()
        {
            if (Session["user"] != null)
            {
                loginLink.Visible = false;
                lblWelcome.Text = "欢迎，" + Session["user"].ToString();
                lnkLogout.Visible = true;
                pnlAddComment.Visible = true; // 已登录用户可发表评论
            }
            else
            {
                loginLink.Visible = true;
                lblWelcome.Text = "游客浏览";
                lnkLogout.Visible = false;
                pnlAddComment.Visible = false; // 未登录用户不可发表评论
            }
        }

        protected void lnkLogout_Click(object sender, EventArgs e)
        {
            Session["user"] = null;
            Response.Redirect("Index.aspx");
        }

        private void LoadPostDetail()
        {
            if (currentPostId == 0) return;

            // 使用Index页面中的相同查询结构
            string sql = @"SELECT p.PostID, p.Title, p.Content, c.CategoryName
                           FROM Post p
                           INNER JOIN Category c ON p.CategoryID = c.CategoryID
                           WHERE p.PostID = @postId";

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@postId", currentPostId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    // 填充文章详情
                    postTitle.InnerText = reader["Title"].ToString();
                    postCategory.InnerText = reader["CategoryName"].ToString();

                    // 直接使用Content字段
                    postContent.InnerText = reader["Content"].ToString();
                }
                else
                {
                    // 文章不存在
                    Response.Redirect("Index.aspx");
                }

                reader.Close();
            }
        }

        private void LoadComments()
        {
            if (currentPostId == 0) return;

            // 使用Index页面中的相同查询结构
            string sql = @"SELECT TOP 10 Username, Content 
                           FROM Comments 
                           WHERE PostID = @postId AND IsApproved = 1
                           ORDER BY CommentID DESC"; // 假设使用CommentID排序

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@postId", currentPostId);

                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                if (dt.Rows.Count > 0)
                {
                    rptComments.DataSource = dt;
                    rptComments.DataBind();
                    lblNoComments.Visible = false;
                }
                else
                {
                    lblNoComments.Visible = true;
                    rptComments.Visible = false;
                }
            }
        }

        private void LoadRecommendations()
        {
            // 使用Index页面中的相同查询结构
            string sql = @"SELECT TOP 5 p.PostID, p.Title, 
                           (SELECT COUNT(*) FROM Comments c WHERE c.PostID = p.PostID AND c.IsApproved=1) AS CommentCount
                           FROM Post p
                           WHERE p.PostID <> @currentPostId
                           ORDER BY NEWID()"; // 随机排序

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@currentPostId", currentPostId);

                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                if (dt.Rows.Count > 0)
                {
                    rptTrending.DataSource = dt;
                    rptTrending.DataBind();
                    lblNoRecommendations.Visible = false;
                }
                else
                {
                    lblNoRecommendations.Visible = true;
                    rptTrending.Visible = false;
                }
            }
        }

        private void LoadCategories()
        {
            // 使用Index页面中的相同查询
            string sql = "SELECT * FROM Category";

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();
                rptCategories.DataSource = reader;
                rptCategories.DataBind();
                reader.Close();
            }
        }

        protected void btnSubmitComment_Click(object sender, EventArgs e)
        {
            if (Session["user"] == null)
            {
                // 用户未登录
                Response.Redirect("UserLogin.aspx?redirect=" + Server.UrlEncode(Request.Url.ToString()));
                return;
            }

            if (currentPostId == 0 || string.IsNullOrWhiteSpace(txtComment.Text))
            {
                return;
            }

            string username = Session["user"].ToString();
            string content = txtComment.Text.Trim();

            // 使用基本字段的Insert语句
            string sql = @"INSERT INTO Comments (PostID, Username, Content, IsApproved) 
                           VALUES (@postId, @username, @content, 1)";

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@postId", currentPostId);
                cmd.Parameters.AddWithValue("@username", username);
                cmd.Parameters.AddWithValue("@content", content);

                conn.Open();
                cmd.ExecuteNonQuery();
            }

            // 重新加载评论列表
            LoadComments();

            // 清空评论框
            txtComment.Text = "";
        }

        protected string FormatContent(object content)
        {
            if (content == null) return string.Empty;
            return HttpUtility.HtmlEncode(content.ToString())
                .Replace("\n", "<br/>")
                .Replace(" ", "&nbsp;");
        }
    }
}