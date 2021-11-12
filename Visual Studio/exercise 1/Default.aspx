<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div page="Eikones">

        <br />
        <br />

        <table class="nav-justified">
            <tr>
                <td style="height: 22px">
                    <asp:Image ID="Image1" runat="server" Height="520px" ImageUrl="~/Pictures/bali.jpg" Width="600px" />
                </td>
                <td style="height: 22px">
                    <asp:Image ID="Image2" runat="server" Height="520px" ImageUrl="~/Pictures/bali2.jpg" Width="600px" />
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Image ID="Image3" runat="server" Height="520px" ImageUrl="~/Pictures/bali3.jpg" Width="600px" />
                </td>
                <td>
                    <asp:Image ID="Image4" runat="server" Height="520px" ImageUrl="~/Pictures/bali4.jpg" Width="600px" />
                </td>
            </tr>
        </table>
    </div>

    <br />

    <div class="jumbotron">
        <h1>ASP.NET</h1>
        <p class="lead">ASP.NET is a free web framework for building great Web sites and Web applications using HTML, CSS, and JavaScript.</p>
        <p><a href="http://www.asp.net" class="btn btn-primary btn-lg">Learn more &raquo;</a></p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>Getting started</h2>
            <p>
                ASP.NET Web Forms lets you build dynamic websites using a familiar drag-and-drop, event-driven model.
            A design surface and hundreds of controls and components let you rapidly build sophisticated, powerful UI-driven sites with data access.
            </p>
            <p>
                <a class="btn btn-default" href="http://go.microsoft.com/fwlink/?LinkId=301948">Learn more &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>Get more libraries</h2>
            <p>
                NuGet is a free Visual Studio extension that makes it easy to add, remove, and update libraries and tools in Visual Studio projects.
            </p>
            <p>
                <a class="btn btn-default" href="http://go.microsoft.com/fwlink/?LinkId=301949">Learn more &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>Web Hosting</h2>
            <p>
                You can easily find a web hosting company that offers the right mix of features and price for your applications.
            </p>
            <p>
                <a class="btn btn-default" href="http://go.microsoft.com/fwlink/?LinkId=301950">Learn more &raquo;</a>
            </p>
        </div>
    </div>
</asp:Content>
