<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebApplication2._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <style type="text/css">
        .row {
            margin-top: 20px;
        }
    </style>

    <div class="jumbotron">
    </div>

    <div class="row">
        <div class="col-md-4">
            <asp:TextBox ID="TextBox1" runat="server" OnTextChanged="TextBox1_TextChanged" AutoPostBack="true"></asp:TextBox>
            <asp:RequiredFieldValidator ID="user" runat="server" ControlToValidate="TextBox1"
                ErrorMessage="Please enter a user name" ForeColor="Red"></asp:RequiredFieldValidator>
            <asp:Label ID="lbl1" runat="server"></asp:Label>
        </div>
        <div class="col-md-4">
            <asp:Label ID="labelId" runat="server"></asp:Label>
        </div>
        <div class="col-md-4">
            <asp:Button ID="Button2" runat="server" Text="Submit" Style="width: 61px" />
        </div>
    </div>

    <script type="text/javascript">

        function test() {
            alert('test;')
        }

    </script>

</asp:Content>
