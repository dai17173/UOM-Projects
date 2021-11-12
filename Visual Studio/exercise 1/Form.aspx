<%@ Page Title="Form" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Form.aspx.cs" Inherits="Default2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" Runat="Server">
    <h2><%: Title %>.</h2>
    <table class="nav-justified">
        <tr>
            <td colspan="2">&nbsp;</td>
        </tr>
        <tr>
            <td>Όνομα :</td>
            <td>
                <asp:TextBox ID="txtName" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="ValidatorName" runat="server" ControlToValidate="txtName" ErrorMessage="Πρέπει να συμπληρώσετε το όνομα σας" ForeColor="Red">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>Επίθετο :</td>
            <td>
                <asp:TextBox ID="txtSurname" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="ValidatorSurname" runat="server" ControlToValidate="txtSurname" ErrorMessage="Πρέπει να συμπληρώσετε το επίθετο σας" ForeColor="Red">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td style="height: 22px">Αριθμός Ταυτότητας :</td>
            <td style="height: 22px">
                <asp:TextBox ID="txtId" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="ValidatorId" runat="server" ControlToValidate="txtId" ErrorMessage="Πρέπει να συμπληρώσετε την ταυτότητα σας" ForeColor="Red">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>Email :</td>
            <td>
                <asp:TextBox ID="txtEmail" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="ValidatorEmail" runat="server" ControlToValidate="txtEmail" ErrorMessage="Πρέπει να συμπληρώσετε το email σας" ForeColor="Red">*</asp:RequiredFieldValidator>
                <asp:RegularExpressionValidator ID="RegValidatorEmail" runat="server" ControlToValidate="txtEmail" ErrorMessage="Συμπληρώστε σωστό email" ForeColor="Red" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*">**</asp:RegularExpressionValidator>
            </td>
        </tr>
        <tr>
            <td style="height: 22px"></td>
            <td style="height: 22px"></td>
        </tr>
        <tr>
            <td style="height: 24px">Αναχώρηση :</td>
            <td style="height: 24px">
                <asp:DropDownList ID="ListAnaxwrisis" runat="server">
                    <asp:ListItem Selected="True">Επιλέξτε Διαδρομή</asp:ListItem>
                    <asp:ListItem>Θεσσαλονίκη</asp:ListItem>
                    <asp:ListItem>Σέρρες</asp:ListItem>
                    <asp:ListItem>Δράμα</asp:ListItem>
                    <asp:ListItem>Καβάλα</asp:ListItem>
                    <asp:ListItem>Αθήνα</asp:ListItem>
                </asp:DropDownList>
                <asp:CompareValidator ID="CoValidatorAnaxwrisis" runat="server" ControlToValidate="ListAnaxwrisis" ErrorMessage="Πρέπει&nbsp;να&nbsp;επιλέξετε&nbsp;το σημείο της αναχώρησης" ForeColor="Red" Operator="NotEqual" ValueToCompare="Επιλέξτε Διαδρομή">*</asp:CompareValidator>
            </td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td>
                &nbsp;</td>
        </tr>
        <tr>
            <td style="height: 22px">Προορισμός :</td>
            <td style="height: 22px">
                <asp:DropDownList ID="ListProorismou" runat="server">
                    <asp:ListItem Selected="True">Επιλέξτε Διαδρομή</asp:ListItem>
                    <asp:ListItem>Θεσσαλονίκη</asp:ListItem>
                    <asp:ListItem>Σέρρες</asp:ListItem>
                    <asp:ListItem>Δράμα</asp:ListItem>
                    <asp:ListItem>Καβάλα</asp:ListItem>
                    <asp:ListItem>Αθήνα</asp:ListItem>
                </asp:DropDownList>
                <asp:CompareValidator ID="CoValidatorProorismou" runat="server" ControlToValidate="ListProorismou" ErrorMessage="Πρέπει&nbsp;να&nbsp;επιλέξετε&nbsp;τον&nbsp;προορισμό" ForeColor="Red" Operator="NotEqual" ValueToCompare="Επιλέξτε Διαδρομή">*</asp:CompareValidator>
            </td>
        </tr>
        <tr>
            <td style="height: 22px">&nbsp;</td>
            <td style="height: 22px">&nbsp;</td>
        </tr>
        <tr>
            <td style="vertical-align: top; height: 27px;">Μήνας Μετακίνησης :</td>
            <td style="height: 27px">
                <asp:DropDownList ID="listMina" runat="server">
                    <asp:ListItem Selected="True">Επιλέξτε Μήνα</asp:ListItem>
                    <asp:ListItem>Ιανουάριος</asp:ListItem>
                    <asp:ListItem>Φεβρουάριος</asp:ListItem>
                    <asp:ListItem>Μάρτιος</asp:ListItem>
                    <asp:ListItem>Απρίλιος</asp:ListItem>
                    <asp:ListItem>Μάιος</asp:ListItem>
                    <asp:ListItem>Ιούνιος</asp:ListItem>
                    <asp:ListItem>Ιούλιος</asp:ListItem>
                </asp:DropDownList>
                <asp:CompareValidator ID="CoValidatorMina" runat="server" ControlToValidate="listMina" ErrorMessage="Πρέπει&nbsp;να&nbsp;επιλέξετε έναν μήνα" ForeColor="Red" Operator="NotEqual" ValueToCompare="Επιλέξτε Μήνα">*</asp:CompareValidator>
            </td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td style="height: 22px"></td>
            <td style="height: 22px"></td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td><a href="About.aspx" style="color: #FF0000">Όροι Xρήσης</a></td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td>
                <asp:CheckBox ID="CheckBox1" runat="server" Text="Αποδέχομαι τους όρους" />
            </td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td style="height: 28px"></td>
            <td style="height: 28px">
                <asp:Button ID="Button1" runat="server" Text="Υποβολή" OnClick="Button1_Click" />
            </td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
    </table>
    <p>
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" ForeColor="Red" HeaderText="ΠΡΟΣΟΧΗ" />
        <p>
        <asp:CustomValidator ID="CustomValidator1" runat="server" ForeColor="Red" OnServerValidate="CustomValidator1_ServerValidate">Παρακαλώ πατήστε το Checkbox!</asp:CustomValidator>
        <p>
            &nbsp;</asp:Content>

