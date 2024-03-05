<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td>FIRST_NAME
                    </td>
                    <td>
                        <asp:TextBox ID="txtFIRST_NAME" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>LAST_NAME
                    </td>
                    <td>
                        <asp:TextBox ID="txtLAST_NAME" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>EMPLOYEE_CODE
                    </td>
                    <td>
                        <asp:TextBox ID="txtEMPLOYEE_CODE" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>WORKING_HOURS
                    </td>
                    <td>
                        <asp:TextBox ID="txtWORKING_HOURS" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>EMAIL
                    </td>
                    <td>
                        <asp:TextBox ID="txtEMAIL" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>MOBILE_NO
                    </td>
                    <td>
                        <asp:TextBox ID="txtMOBILE_NO" runat="server" Width="400"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:Button ID="btnAdd" runat="server" Text="Add" OnClick="btnAdd_Click" />
                    </td>
                </tr>
            </table>
        </div>
        <div style="margin-top: 100px;">
            <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="false" EmptyDataText="No records has been added." OnRowDataBound="OnRowDataBound"
                DataKeyNames="ID" OnRowEditing="OnRowEditing" OnRowCancelingEdit="OnRowCancelingEdit"
                PageSize="10" AllowPaging="true" OnPageIndexChanging="OnPaging" OnRowUpdating="OnRowUpdating"
                OnRowDeleting="OnRowDeleting">
                <Columns>
                    <asp:TemplateField HeaderText="FIRST_NAME" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblFIRST_NAME" runat="server" Text='<%# Eval("FIRST_NAME") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtFIRST_NAME" runat="server" Text='<%# Eval("FIRST_NAME") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="LAST_NAME" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblLAST_NAME" runat="server" Text='<%# Eval("LAST_NAME") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtLAST_NAME" runat="server" Text='<%# Eval("LAST_NAME") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="EMPLOYEE_CODE" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblEMPLOYEE_CODE" runat="server" Text='<%# Eval("EMPLOYEE_CODE") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtEMPLOYEE_CODE" runat="server" Text='<%# Eval("EMPLOYEE_CODE") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="WORKING_HOURS" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblWORKING_HOURS" runat="server" Text='<%# Eval("WORKING_HOURS") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtWORKING_HOURS" runat="server" Text='<%# Eval("WORKING_HOURS") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="EMAIL" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblEMAIL" runat="server" Text='<%# Eval("EMAIL") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtEMAIL" runat="server" Text='<%# Eval("EMAIL") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="MOBILE_NO" ItemStyle-Width="150">
                        <ItemTemplate>
                            <asp:Label ID="lblMOBILE_NO" runat="server" Text='<%# Eval("MOBILE_NO") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtMOBILE_NO" runat="server" Text='<%# Eval("MOBILE_NO") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Link" ShowEditButton="true" ShowDeleteButton="true"
                        ItemStyle-Width="150" />
                </Columns>
            </asp:GridView>
        </div>
        <div style="margin-top: 100px;">
            <table>
                <tr>
                    <td>State</td>
                    <td>
                        <asp:DropDownList runat="server" ID="ddlState" AutoPostBack="true" CausesValidation="true" OnSelectedIndexChanged="ddlState_SelectedIndexChanged">
                        </asp:DropDownList>
                    </td>
                </tr>
                 <tr>
                    <td>City</td>
                    <td>
                        <asp:DropDownList runat="server" ID="ddlCity">
                        </asp:DropDownList>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
