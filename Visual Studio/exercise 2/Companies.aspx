<%@ Page Title="Companies" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Companies.aspx.cs" Inherits="Default2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" Runat="Server">
    <h2><%: Title %>.</h2>
    <h3>Company Info.</h3>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [Companiess]"></asp:SqlDataSource>
    <br />
    <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" PageSize="3" CellPadding="4">
        <Columns>
            <asp:CommandField ShowSelectButton="True" />
            <asp:BoundField DataField="Name" HeaderText="Name" SortExpression="Name" />
            <asp:BoundField DataField="Description" HeaderText="Description" SortExpression="Description" />
        </Columns>
</asp:GridView>
    <br />
    <asp:FormView ID="FormView1" runat="server" CellPadding="4" DataKeyNames="CompanyId" DataSourceID="SqlDataSource1" ForeColor="#333333">
        <EditItemTemplate>
            CompanyId:
            <asp:Label ID="CompanyIdLabel1" runat="server" Text='<%# Eval("CompanyId") %>' />
            <br />
            Name:
            <asp:TextBox ID="NameTextBox" runat="server" Text='<%# Bind("Name") %>' />
            <br />
            Description:
            <asp:TextBox ID="DescriptionTextBox" runat="server" Text='<%# Bind("Description") %>' />
            <br />
            Start Date:
            <asp:TextBox ID="Start_DateTextBox" runat="server" Text='<%# Bind("[Start Date]") %>' />
            <br />
            Limit:
            <asp:TextBox ID="LimitTextBox" runat="server" Text='<%# Bind("Limit") %>' />
            <br />
            <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="Update" />
            &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel" />
        </EditItemTemplate>
        <FooterStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
        <InsertItemTemplate>
            Name:
            <asp:TextBox ID="NameTextBox" runat="server" Text='<%# Bind("Name") %>' />
            <br />
            Description:
            <asp:TextBox ID="DescriptionTextBox" runat="server" Text='<%# Bind("Description") %>' />
            <br />
            Start Date:
            <asp:TextBox ID="Start_DateTextBox" runat="server" Text='<%# Bind("[Start Date]") %>' />
            <br />
            Limit:
            <asp:TextBox ID="LimitTextBox" runat="server" Text='<%# Bind("Limit") %>' />
            <br />
            <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="Insert" />
            &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel" />
        </InsertItemTemplate>
        <ItemTemplate>
            CompanyId:
            <asp:Label ID="CompanyIdLabel" runat="server" Text='<%# Eval("CompanyId") %>' />
            <br />
            Name:
            <asp:Label ID="NameLabel" runat="server" Text='<%# Bind("Name") %>' />
            <br />
            Description:
            <asp:Label ID="DescriptionLabel" runat="server" Text='<%# Bind("Description") %>' />
            <br />
            Start Date:
            <asp:Label ID="Start_DateLabel" runat="server" Text='<%# Bind("[Start Date]") %>' />
            <br />
            Limit:
            <asp:Label ID="LimitLabel" runat="server" Text='<%# Bind("Limit") %>' />
            <br />

        </ItemTemplate>
        <PagerStyle BackColor="#FFCC66" ForeColor="#333333" HorizontalAlign="Center" />
        <RowStyle BackColor="#FFFBD6" ForeColor="#333333" />
</asp:FormView>
</asp:Content>

