<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PostDetail.aspx.cs" Inherits="WebInfoSystem.PostDetail" %>

<!DOCTYPE html>
<html>
<head runat="server">
    <title>文章详情 | 漫游篝火</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" />
    <style>
        body {
            background: #f8f9fa;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif;
        }

        .navbar-custom {
            background-color: #343a40;
        }

        .main-container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 15px;
        }

        .post-detail-container {
            background-color: white;
            border-radius: 8px;
            box-shadow: 0 2px 12px rgba(0, 0, 0, 0.05);
            padding: 30px;
            margin-bottom: 30px;
        }

        .post-header {
            margin-bottom: 25px;
            padding-bottom: 20px;
            border-bottom: 1px solid #eee;
        }

        .post-category {
            background-color: #e6f1ff;
            color: #1d7dfa;
            font-size: 14px;
            padding: 5px 12px;
            border-radius: 20px;
            display: inline-block;
            margin-bottom: 15px;
            font-weight: 500;
        }

        .post-title {
            font-size: 32px;
            font-weight: 700;
            margin-bottom: 20px;
            line-height: 1.3;
            color: #1d2129;
        }

        .post-content {
            font-size: 18px;
            line-height: 1.8;
            color: #333;
        }

        .comments-section {
            margin-top: 40px;
        }

        .section-title {
            font-size: 22px;
            font-weight: 600;
            margin-bottom: 25px;
            padding-bottom: 10px;
            border-bottom: 2px solid #f0f2f5;
            position: relative;
        }

        .section-title::after {
            content: "";
            position: absolute;
            left: 0;
            bottom: -2px;
            width: 60px;
            height: 2px;
            background: #1d7dfa;
        }

        .comment-box {
            background-color: #f8f9fa;
            border-radius: 8px;
            padding: 20px;
            margin-bottom: 20px;
        }

        .comment-header {
            display: flex;
            align-items: center;
            margin-bottom: 15px;
        }

        .comment-author {
            font-weight: 600;
            font-size: 16px;
            margin-right: 15px;
            color: #1d2129;
        }

        .comment-content {
            font-size: 16px;
            line-height: 1.6;
            color: #4e5969;
        }

        .add-comment-section {
            background-color: white;
            border-radius: 8px;
            box-shadow: 0 2px 12px rgba(0, 0, 0, 0.05);
            padding: 25px;
            margin-top: 30px;
        }

        .sidebar-card {
            background-color: white;
            border-radius: 8px;
            box-shadow: 0 2px 12px rgba(0, 0, 0, 0.05);
            margin-bottom: 30px;
            overflow: hidden;
        }

        .sidebar-title {
            font-size: 18px;
            font-weight: 600;
            padding: 15px 20px;
            border-bottom: 1px solid #f0f2f5;
            margin: 0;
        }

        .sidebar-content {
            padding: 20px;
        }

        .recommend-list {
            list-style: none;
            padding: 0;
            margin: 0;
        }

        .recommend-item {
            padding: 15px 0;
            border-bottom: 1px solid #f0f2f5;
        }

        .recommend-item:last-child {
            border-bottom: none;
        }

        .recommend-title {
            font-weight: 500;
            font-size: 16px;
            color: #1d2129;
            margin-bottom: 8px;
            display: block;
            text-decoration: none;
        }

        .recommend-title:hover {
            color: #1d7dfa;
            text-decoration: underline;
        }

        .recommend-meta {
            color: #86909c;
            font-size: 13px;
            display: flex;
        }

        .preserve-line-breaks {
            white-space: pre-line;
        }

        .btn-comment {
            background-color: #1d7dfa;
            color: white;
            border: none;
            font-weight: 500;
            padding: 8px 20px;
        }

        .btn-comment:hover {
            background-color: #0d6efd;
        }
        
        .search-container {
            flex-grow: 1;
            max-width: 400px;
            margin: 0 20px;
        }
        
        .search-box {
            position: relative;
        }
        
        .search-input {
            width: 100%;
            height: 36px;
            padding: 0 36px 0 16px;
            border-radius: 18px;
            border: none;
            outline: none;
            background-color: rgba(255, 255, 255, 0.25);
            color: white;
            transition: all 0.3s ease;
        }
        
        .search-input::placeholder {
            color: rgba(255, 255, 255, 0.7);
        }
        
        .search-input:focus {
            background-color: rgba(255, 255, 255, 0.35);
        }
        
        .search-icon {
            position: absolute;
            right: 10px;
            top: 50%;
            transform: translateY(-50%);
            color: rgba(255, 255, 255, 0.7);
            cursor: pointer;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <!-- 顶部导航栏 -->
        <nav class="navbar navbar-expand-lg navbar-dark navbar-custom mb-4">
            <div class="container">
                <a class="navbar-brand fw-bold" href="Index.aspx">漫游篝火</a>
                <div class="search-container">
                    <div class="search-box">
                        <input type="text" class="search-input" placeholder="搜索文章、用户或关键词" />
                        <div class="search-icon">🔍</div>
                    </div>
                </div>
                <div class="d-flex align-items-center">
                    <asp:Label ID="lblWelcome" runat="server" CssClass="me-3 text-white fw-semibold" />
                    <asp:LinkButton ID="lnkLogout" runat="server" Text="退出" OnClick="lnkLogout_Click" CssClass="btn btn-sm btn-outline-light" />
                    <asp:HyperLink ID="loginLink" runat="server" NavigateUrl="Userlogin.aspx" CssClass="btn btn-sm btn-outline-light ms-2">登录</asp:HyperLink>
                </div>
            </div>
        </nav>

        <div class="main-container">
            <div class="row">
                <!-- 主内容区域 (8列) -->
                <div class="col-lg-8">
                    <div class="post-detail-container">
                        <!-- 文章头部信息 -->
                        <div class="post-header">
                            <div class="post-category" id="postCategory" runat="server"></div>
                            <h1 class="post-title" id="postTitle" runat="server"></h1>
                        </div>
                        
                        <!-- 文章内容 -->
                        <div class="post-content preserve-line-breaks" id="postContent" runat="server"></div>
                        
                        <!-- 评论区域 -->
                        <div class="comments-section">
                            <h3 class="section-title">留言</h3>
                            
                            <!-- 已审核评论列表 -->
                            <asp:Repeater ID="rptComments" runat="server">
                                <ItemTemplate>
                                    <div class="comment-box">
                                        <div class="comment-header">
                                            <div class="comment-author"><%# Eval("Username") %></div>
                                        </div>
                                        <div class="comment-content preserve-line-breaks"><%# FormatContent(Eval("Content")) %></div>
                                    </div>
                                </ItemTemplate>
                            </asp:Repeater>
                            
                            <asp:Label ID="lblNoComments" runat="server" Text="暂无评论" Visible="false" CssClass="text-muted"></asp:Label>
                            
                            <!-- 添加新评论（仅对已登录用户显示） -->
                            <asp:Panel ID="pnlAddComment" runat="server" Visible="false" CssClass="add-comment-section">
                                <h4 class="section-title">发表评论</h4>
                                <div class="mb-3">
                                    <asp:TextBox ID="txtComment" runat="server" TextMode="MultiLine" Rows="4" 
                                        CssClass="form-control" placeholder="请输入评论内容..."></asp:TextBox>
                                    <asp:RequiredFieldValidator ID="rfvComment" runat="server" ControlToValidate="txtComment" 
                                        ErrorMessage="评论内容不能为空！" Display="Dynamic" ForeColor="Red"></asp:RequiredFieldValidator>
                                </div>
                                <div class="text-end">
                                    <asp:Button ID="btnSubmitComment" runat="server" Text="提交评论" 
                                        CssClass="btn btn-comment" OnClick="btnSubmitComment_Click" />
                                </div>
                            </asp:Panel>
                        </div>
                    </div>
                </div>
                
                <!-- 右侧边栏 (4列) -->
                <div class="col-lg-4">
                    <!-- 热门文章 -->
                    <div class="sidebar-card">
                        <h4 class="sidebar-title">浏览热度 🔥</h4>
                        <div class="sidebar-content">
                            <asp:Repeater ID="rptTrending" runat="server">
                                <HeaderTemplate>
                                    <ul class="recommend-list">
                                </HeaderTemplate>
                                <ItemTemplate>
                                    <li class="recommend-item">
                                        <a href='PostDetail.aspx?postid=<%# Eval("PostID") %>' class="recommend-title"><%# Eval("Title") %></a>
                                        <div class="recommend-meta">
                                            <span class="recommend-comments">💬 <%# Eval("CommentCount") %></span>
                                        </div>
                                    </li>
                                </ItemTemplate>
                                <FooterTemplate>
                                    </ul>
                                </FooterTemplate>
                            </asp:Repeater>
                            <asp:Label ID="lblNoRecommendations" runat="server" Visible="false" 
                                Text="暂无推荐文章" CssClass="text-muted"></asp:Label>
                        </div>
                    </div>
                    
                    <!-- 分类导航 -->
                    <div class="sidebar-card">
                        <h4 class="sidebar-title">栏目分类</h4>
                        <div class="sidebar-content">
                            <asp:Repeater ID="rptCategories" runat="server">
                                <HeaderTemplate>
                                    <ul class="recommend-list">
                                </HeaderTemplate>
                                <ItemTemplate>
                                    <li class="recommend-item">
                                        <a href='Index.aspx?categoryid=<%# Eval("CategoryID") %>' class="recommend-title"><%# Eval("CategoryName") %></a>
                                    </li>
                                </ItemTemplate>
                                <FooterTemplate>
                                    </ul>
                                </FooterTemplate>
                            </asp:Repeater>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </form>
</body>
</html>