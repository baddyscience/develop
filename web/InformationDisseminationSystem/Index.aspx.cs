using System;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using System.Web;

namespace WebInfoSystem
{
    public partial class Index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // 设置用户界面状态
                SetUserUIState();

                // 加载分类数据
                LoadCategories();

                // 加载文章内容
                LoadPosts();

                // 加载热门文章（浏览热度）
                LoadTrendingPosts();
            }
        }

        private void SetUserUIState()
        {
            if (Session["user"] != null)
            {
                loginLink.Visible = false;
                lblWelcome.Text = "欢迎，" + Session["user"].ToString();
                lnkLogout.Visible = true;
            }
            else
            {
                loginLink.Visible = true;
                lblWelcome.Text = "游客浏览";
                lnkLogout.Visible = false;
            }
        }

        protected void lnkLogout_Click(object sender, EventArgs e)
        {
            Session["user"] = null;
            Response.Redirect("Index.aspx");
        }

        private void LoadCategories()
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand("SELECT * FROM Category", conn);
                conn.Open();

                // 绑定下拉框
                ddlFilterCategory.DataSource = cmd.ExecuteReader();
                ddlFilterCategory.DataTextField = "CategoryName";
                ddlFilterCategory.DataValueField = "CategoryID";
                ddlFilterCategory.DataBind();
                ddlFilterCategory.Items.Insert(0, new System.Web.UI.WebControls.ListItem("全部栏目", "0"));

                // 重新执行查询绑定导航分类
                conn.Close();
                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                rptCategories.DataSource = reader;
                rptCategories.DataBind();
                reader.Close();
            }
        }

        private void LoadPosts()
        {
            // 使用原始SQL查询，不添加新字段
            string sql = "SELECT Post.PostID, Title, Content, CategoryName FROM Post " +
                         "INNER JOIN Category ON Post.CategoryID = Category.CategoryID";

            if (ddlFilterCategory.SelectedValue != "0")
            {
                sql += " WHERE Post.CategoryID=@cat";
            }

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                if (ddlFilterCategory.SelectedValue != "0")
                {
                    cmd.Parameters.AddWithValue("@cat", ddlFilterCategory.SelectedValue);
                }

                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                rptPosts.DataSource = dt;
                rptPosts.DataBind();
            }
        }

        // 加载热门文章（浏览热度）
        private void LoadTrendingPosts()
        {
            // 使用SQL查询获取评论数最多的文章
            string sql = @"SELECT TOP 10 p.PostID, p.Title, 
                                  (SELECT COUNT(*) FROM Comments c WHERE c.PostID = p.PostID AND c.IsApproved=1) AS CommentCount
                           FROM Post p
                           ORDER BY CommentCount DESC";

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand(sql, conn);
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                if (dt.Rows.Count > 0)
                {
                    rptTrending.DataSource = dt;
                    rptTrending.DataBind();
                    lblNoTrending.Visible = false;
                }
                else
                {
                    rptTrending.Visible = false;
                    lblNoTrending.Visible = true;
                }
            }
        }

        protected void ddlFilterCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            LoadPosts();
        }

        // 获取评论数据（最多3条）
        public DataTable GetTopComments(object postIdObj)
        {
            int postId = Convert.ToInt32(postIdObj);
            DataTable dt = new DataTable();
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                // 只获取基本的用户名和内容
                SqlCommand cmd = new SqlCommand("SELECT TOP 3 Username, Content FROM Comments WHERE PostID=@pid AND IsApproved=1", conn);
                cmd.Parameters.AddWithValue("@pid", postId);
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
            }
            return dt;
        }

        // 获取评论数量
        public int GetCommentsCount(object postIdObj)
        {
            int postId = Convert.ToInt32(postIdObj);
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnStr"].ConnectionString))
            {
                SqlCommand cmd = new SqlCommand("SELECT COUNT(*) FROM Comments WHERE PostID=@pid AND IsApproved=1", conn);
                cmd.Parameters.AddWithValue("@pid", postId);
                conn.Open();
                return (int)cmd.ExecuteScalar();
            }
        }

        // 内容格式化方法
        protected string FormatContent(object content)
        {
            if (content == null) return string.Empty;
            return HttpUtility.HtmlEncode(content.ToString())
                              .Replace("\n", "<br/>")
                              .Replace(" ", "&nbsp;");
        }
    }
}