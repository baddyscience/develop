<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Index.aspx.cs" Inherits="WebInfoSystem.Index" %>
<!DOCTYPE html>
<html>
<head runat="server">
    <title>信息浏览 | 漫游篝火</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" />
    <style>
        .preserve-line-breaks {
            white-space: pre-line; 
        }

        body {
            background: #f8f9fa;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif;
        }

        .navbar-custom {
            background-color: #343a40;
        }

        .post-card {
            transition: box-shadow 0.3s ease;
            margin-bottom: 15px;
            border: 1px solid #eaeaea;
            border-radius: 4px;
        }

        .post-card:hover {
            box-shadow: 0 2px 12px rgba(0,0,0,0.08);
        }

        .comment-box {
            background-color: #f8f9fa;
            border-left: 3px solid #dee2e6;
            margin-top: 10px;
            padding: 10px;
            border-radius: 0 0 4px 4px;
        }
        
        .main-container {
            max-width: 1000px;
            margin: 0 auto;
            padding: 0 15px;
        }
        
        .header-container {
            position: sticky;
            top: 0;
            z-index: 100;
            background: white;
            box-shadow: 0 1px 2px rgba(0,0,0,0.1);
        }
        
        .nav-links {
            display: flex;
            padding: 12px 0;
            border-bottom: 1px solid #e4e6eb;
            margin-bottom: 16px;
            overflow-x: auto;
            background: white;
        }
        
        .nav-link-item {
            padding: 0 16px;
            font-size: 16px;
            white-space: nowrap;
            color: #4e5969;
            position: relative;
            cursor: pointer;
        }
        
        .nav-link-item.active {
            color: #1d7dfa;
            font-weight: 500;
        }
        
        .nav-link-item.active:after {
            content: "";
            position: absolute;
            bottom: -1px;
            left: 16px;
            right: 16px;
            height: 2px;
            background: #1d7dfa;
        }
        
        .post-title {
            font-size: 18px;
            font-weight: 600;
            margin-bottom: 8px;
            color: #1d2129;
            line-height: 1.5;
        }
        
        .post-content {
            font-size: 15px;
            color: #4e5969;
            line-height: 1.6;
            margin-bottom: 10px;
            max-height: 60px;
            overflow: hidden;
            text-overflow: ellipsis;
            display: -webkit-box;
            -webkit-line-clamp: 2;
            -webkit-box-orient: vertical;
        }
        
        .post-footer {
            display: flex;
            align-items: center;
            font-size: 13px;
            color: #86909c;
        }
        
        .post-footer-item {
            margin-right: 20px;
            display: flex;
            align-items: center;
        }
        
        .post-footer-icon {
            margin-right: 4px;
        }
        
        .comment-count {
            color: #1d7dfa;
            margin-left: 5px;
        }
        
        .post-category {
            background-color: #e6f1ff;
            color: #1d7dfa;
            font-size: 12px;
            padding: 2px 8px;
            border-radius: 2px;
            display: inline-block;
            margin-bottom: 8px;
        }
        
        .btn-comment {
            background-color: #eff5ff;
            color: #1d7dfa;
            border: none;
            border-radius: 4px;
            padding: 4px 10px;
            font-size: 13px;
        }
        
        .btn-comment:hover {
            background-color: #dee9f9;
        }
        
        .no-content {
            text-align: center;
            padding: 40px 0;
            color: #86909c;
        }
        
        /* 侧边栏样式 */
        .sidebar-title {
            font-size: 18px;
            font-weight: 600;
            padding-bottom: 8px;
            border-bottom: 2px solid #e4e6eb;
            margin-bottom: 15px;
            color: #1d2129;
        }
        
        .trending-list {
            list-style-type: none;
            padding-left: 0;
        }
        
        .trending-item {
            padding: 12px 0;
            border-bottom: 1px solid #e4e6eb;
        }
        
        .trending-item:hover {
            background-color: #f8f9fa;
            cursor: pointer;
        }
        
        .trending-title {
            font-size: 15px;
            color: #1d2129;
            margin-bottom: 5px;
            line-height: 1.4;
        }
        
        .trending-comments {
            display: flex;
            align-items: center;
            font-size: 13px;
            color: #86909c;
        }
        
        .trending-comments::before {
            content: "🔥";
            margin-right: 6px;
            color: #ff6b6b;
        }
        
        .trending-rank {
            display: inline-block;
            width: 22px;
            height: 22px;
            line-height: 22px;
            text-align: center;
            background-color: #f8f9fa;
            border-radius: 4px;
            margin-right: 8px;
            font-size: 13px;
            font-weight: bold;
            color: #86909c;
        }
        
        .trending-rank.top {
            background-color: #ff6b6b;
            color: white;
        }
        
        /* 搜索框样式 */
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
    .post-title a {
            text-decoration: none;
            color: #1d2129;
            display: block;
        }
        
        .post-title a:hover {
            color: #1d7dfa;
        }
        
        .post-content a {
            text-decoration: none;
            color: #4e5969;
        }
        
        .post-content a:hover {
            color: #1d7dfa;
        }
        
        .post-card-link {
            display: block;
            text-decoration: none;
            color: inherit;
        }
        
        .post-card-link:hover {
            text-decoration: none;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <!-- 顶部导航栏 -->
        <div class="header-container">
            <nav class="navbar navbar-expand-lg navbar-dark navbar-custom">
                <div class="container">
                    <!-- 品牌Logo -->
                    <a class="navbar-brand fw-bold" href="#">漫游篝火</a>
                    
                    <!-- 搜索栏 -->
                    <div class="search-container">
                        <div class="search-box">
                            <input type="text" class="search-input" placeholder="搜索文章、用户或关键词" />
                            <div class="search-icon">🔍</div>
                        </div>
                    </div>
                    
                    <!-- 用户操作区 -->
                    <div class="d-flex align-items-center">
                        <asp:Label ID="lblWelcome" runat="server" CssClass="me-3 text-white fw-semibold" />
                        <asp:LinkButton ID="lnkLogout" runat="server" Text="退出" OnClick="lnkLogout_Click" CssClass="btn btn-sm btn-outline-light" />
                        <asp:HyperLink ID="loginLink" runat="server" NavigateUrl="Userlogin.aspx" CssClass="btn btn-sm btn-outline-light ms-2">登录</asp:HyperLink>
                    </div>
                </div>
            </nav>
            
            <!-- 分类导航 -->
            <div class="main-container">
                <div class="nav-links">
                    <div class="nav-link-item <%# ddlFilterCategory.SelectedValue == "0" ? "active" : "" %>" onclick="document.getElementById('<%= ddlFilterCategory.ClientID %>').value = '0'; __doPostBack('<%= ddlFilterCategory.ClientID %>', '');">
                        推荐
                    </div>
                    <asp:Repeater ID="rptCategories" runat="server">
                        <ItemTemplate>
                            <div class="nav-link-item <%# Eval("CategoryID").ToString() == ddlFilterCategory.SelectedValue ? "active" : "" %>" 
                                 onclick="document.getElementById('<%= ddlFilterCategory.ClientID %>').value = '<%# Eval("CategoryID") %>'; __doPostBack('<%= ddlFilterCategory.ClientID %>', '');">
                                <%# Eval("CategoryName") %>
                            </div>
                        </ItemTemplate>
                    </asp:Repeater>
                </div>
            </div>
        </div>
        
        <!-- 隐藏的下拉框（保持原功能不变） -->
        <div style="display: none;">
            <asp:DropDownList ID="ddlFilterCategory" runat="server" AutoPostBack="true" OnSelectedIndexChanged="ddlFilterCategory_SelectedIndexChanged" />
        </div>

        <div class="main-container">
            <div class="row">
                <!-- 主内容区域 (8列) -->
                <div class="col-lg-8">
                    <asp:Repeater ID="rptPosts" runat="server">
                        <ItemTemplate>
                            <div class="post-card bg-white">
                                <div class="p-3">
                                    <!-- 分类标签 -->
                                    <div class="post-category"><%# Eval("CategoryName") %></div>
                                    
                                    <!-- 标题 -->
                                    <h3 class="post-title">
                                            <a href='PostDetail.aspx?postid=<%# Eval("PostID") %>'><%# Eval("Title") %></a>
                                        </h3>
                                    
                                    <!-- 内容预览 -->
                                    <div class="post-content preserve-line-breaks"><%# FormatContent(Eval("Content")) %></div>
                                    
                                    <!-- 底部信息 -->
                                    <div class="post-footer">
                                        <!-- 只显示评论信息，不显示作者和时间 -->
                                        <div class="post-footer-item">
                                            <a href='CommentSubmit.aspx?postid=<%# Eval("PostID") %>' class="d-flex align-items-center">
                                                <span class="post-footer-icon">💬</span>
                                                <span>评论</span>
                                                <span class="comment-count">(<%# GetCommentsCount(Eval("PostID")) %>)</span>
                                            </a>
                                        </div>
                                    </div>
                                </div>
                                
                                <!-- 留言区（最多显示3条） -->
                                <asp:Repeater ID="rptComments" runat="server" DataSource='<%# GetTopComments(Eval("PostID")) %>'>
                                    <HeaderTemplate>
                                        <div class="comment-box">
                                            <h6 class="text-secondary">留言：</h6>
                                    </HeaderTemplate>
                                    <ItemTemplate>
                                        <div class="pt-2">
                                            <strong class="text-dark"><%# Eval("Username") %>:</strong>
                                            <p class="mb-1 preserve-line-breaks"><%# FormatContent(Eval("Content")) %></p>
                                        </div>
                                    </ItemTemplate>
                                    <FooterTemplate>
                                        </div>
                                    </FooterTemplate>
                                </asp:Repeater>
                            </div>
                        </ItemTemplate>
                        <FooterTemplate>
                            <asp:Panel ID="pnlNoData" runat="server" Visible='<%# rptPosts.Items.Count == 0 %>' CssClass="no-content">
                                <div class="fs-5">暂无内容</div>
                                <div class="text-muted mt-2">当前栏目没有找到任何信息</div>
                            </asp:Panel>
                        </FooterTemplate>
                    </asp:Repeater>
                </div>
                
                <!-- 右侧边栏 (4列) -->
                <div class="col-lg-4">
                    <div class="card shadow-sm">
                        <div class="card-body">
                            <div class="sidebar-title">浏览热度 🔥</div>
                            <asp:Repeater ID="rptTrending" runat="server">
                                <HeaderTemplate>
                                    <ul class="trending-list">
                                </HeaderTemplate>
                                <ItemTemplate>
                                    <li class="trending-item">
                                        <a href='PostDetail.aspx?postid=<%# Eval("PostID") %>' style="text-decoration: none; color: inherit;">
                                        <div class="d-flex align-items-start">
                                            <span class="trending-rank <%# Container.ItemIndex < 3 ? "top" : "" %>"><%# Container.ItemIndex + 1 %></span>
                                            <div>
                                                 <div class="trending-title"><%# Eval("Title") %></div>
                                                    <div class="trending-comments"><%# Eval("CommentCount") %> 条评论</div>
                                                </div>
                                        </div>
                                    </li>
                                </ItemTemplate>
                                <FooterTemplate>
                                    </ul>
                                </FooterTemplate>
                            </asp:Repeater>
                            <asp:Label ID="lblNoTrending" runat="server" Visible="false" CssClass="text-muted text-center">暂无热门文章</asp:Label>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </form>
</body>
</html>