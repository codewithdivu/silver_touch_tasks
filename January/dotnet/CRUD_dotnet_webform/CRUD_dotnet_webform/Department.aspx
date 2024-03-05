<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Department.aspx.cs" Inherits="CRUD_dotnet_webform.Department" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Department</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f5f5f5;
        }

        .departmentForm {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
        }

        .formContainer {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            width: 400px;
            margin-bottom: 20px;
        }

        .form-group {
            margin-bottom: 20px;
        }

            .form-group input[type="text"],
            .form-group input[type="number"] {
                width: 100%;
                padding: 10px;
                border: 1px solid #ccc;
                border-radius: 4px;
                box-sizing: border-box;
            }

                .form-group input[type="text"]:focus,
                .form-group input[type="number"]:focus {
                    outline: none;
                    border-color: #007bff;
                }

        .btn {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            border-radius: 4px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

            .btn:hover {
                background-color: #0056b3;
            }

        #GridView {
            width: 100%;
            border-collapse: collapse;
            border: 1px solid #ddd;
            margin-top: 20px;
        }

            #GridView th,
            #GridView td {
                padding: 8px;
                text-align: left;
            }

            #GridView th {
                background-color: #007bff;
                color: #fff;
            }

            #GridView tr:nth-child(even) {
                background-color: #f2f2f2;
            }

            #GridView tr:hover {
                background-color: #ddd;
            }

            #GridView tr.selected {
                background-color: #007bff;
                color: #fff;
            }

        .btu {
            text-decoration: none;
            margin: 15px;
            padding: 7px;
            font-size: 12px;
        }

        .errorClass {
            margin-bottom: 0;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="departmentForm">
        <h1>Department CRUD</h1>

        <div class="formContainer">
            <div class="form-group">
                <asp:TextBox ID="txtDepartmentID" runat="server" placeholder="Department ID" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="department" runat="server" ControlToValidate="txtDepartmentID" ErrorMessage="DepartmentID is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtDepartmentName" runat="server" placeholder="Department Name" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="departmentname" runat="server" ControlToValidate="txtDepartmentName" ErrorMessage="Department Name is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtLocation" runat="server" placeholder="Location" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="locationerror" runat="server" ControlToValidate="txtLocation" ErrorMessage="Location is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtManagerID" runat="server" placeholder="Manager ID" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="manager" runat="server" ControlToValidate="txtManagerID" ErrorMessage="Manager is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtBudget" runat="server" placeholder="Budget" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="budgeterror" runat="server" ControlToValidate="txtBudget" ErrorMessage="Budget is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:Button ID="departmentSubmit" CssClass="btn" Text="Submit" runat="server" OnClick="HandleDepartmentSubmit" />
                <asp:Button ID="departmentUpdate" runat="server" CssClass="btn" Text="Updation" OnClick="HandleDepartmentUpdation" />
                <asp:Button ID="departmentClear" runat="server" CssClass="btn" Text="clear" OnClick="HandleDepartmentClear" />
            </div>
        </div>

        <div style="margin-top: 20px;">
            <asp:GridView ID="GridView" runat="server" AutoGenerateColumns="false" EmptyDataText="No records have been added."
                DataKeyNames="DepartmentID"
                PageSize="5" AllowPaging="true"
                OnRowEditing="OnRowEditing" OnRowDeleting="OnRowDeleting"
                OnPageIndexChanging="OnPaging" OnRowDataBound="OnRowDataBound">
                <Columns>
                    <asp:TemplateField HeaderText="DepartmentID">
                        <ItemTemplate>
                            <asp:Label ID="lblDepartmentID" runat="server" Text='<%# Eval("DepartmentID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtDepartmentID" runat="server" Text='<%# Eval("DepartmentID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="DepartmentName">
                        <ItemTemplate>
                            <asp:Label ID="lblDepartmentName" runat="server" Text='<%# Eval("DepartmentName") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtDepartmentName" runat="server" Text='<%# Eval("DepartmentName") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Location">
                        <ItemTemplate>
                            <asp:Label ID="lblLocation" runat="server" Text='<%# Eval("Location") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtLocation" runat="server" Text='<%# Eval("Location") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="ManagerID">
                        <ItemTemplate>
                            <asp:Label ID="lblManagerID" runat="server" Text='<%# Eval("ManagerID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtManagerID" runat="server" Text='<%# Eval("ManagerID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Budget">
                        <ItemTemplate>
                            <asp:Label ID="lblBudget" runat="server" Text='<%# Eval("Budget") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtBudget" runat="server" Text='<%# Eval("Budget") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Link" ShowEditButton="true" ControlStyle-CssClass="btn btu" />
                    <asp:CommandField ButtonType="Link" ShowDeleteButton="true" ControlStyle-BackColor="Red" ControlStyle-CssClass="btn btu" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>

