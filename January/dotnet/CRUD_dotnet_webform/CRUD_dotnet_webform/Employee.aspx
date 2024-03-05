<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Employee.aspx.cs" Inherits="CRUD_dotnet_webform.Employee" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Employee</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f5f5f5;
            height: 100vh;
        }

        .departmentForm {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
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

        .dropdown-style {
            width: 100%;
            padding: 5px;
            border: 1px solid #ccc;
            border-radius: 4px;
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

        #genderlabel {
            font-size: 15px;
        }

        #txtGender {
            font-size: 15px;
        }

            #txtGender input[type="radio"] {
                transform: scale(2);
                margin-right: 10px;
                margin-bottom: 10px;
                margin-left: 10px;
                margin-top: 10px;
            }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="departmentForm">
        <h1>Employee CRUD</h1>
        <div class="formContainer">
            <div class="form-group">
                <asp:TextBox ID="txtEmployeeID" runat="server" placeholder="Employee ID" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="employee" runat="server" ControlToValidate="txtEmployeeID" ErrorMessage="EmployeeID is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtName" runat="server" placeholder="Employee Name" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="employeename" runat="server" ControlToValidate="txtName" ErrorMessage="Employee Name is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtDepartmentID" runat="server" CssClass="dropdown-style" AutoPostBack="true">
                </asp:DropDownList>
               <asp:RequiredFieldValidator ID="depa" runat="server" ControlToValidate="txtDepartmentID" ErrorMessage="Department is required."
    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:Label ID="genderlabel" Text="Gender" ForeColor="#999999" runat="server"></asp:Label>
                <asp:RadioButtonList ID="txtGender" runat="server">
                    <asp:ListItem Text="Male" Value="Male"></asp:ListItem>
                    <asp:ListItem Text="Female" Value="Female"></asp:ListItem>
                </asp:RadioButtonList>
                <asp:RequiredFieldValidator ID="gender" runat="server" ControlToValidate="txtGender" ErrorMessage="Gender is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtDateOfBirth" runat="server" placeholder="Email" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="dateofbirth" runat="server" ControlToValidate="txtDateOfBirth" ErrorMessage="Email is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
                <asp:RegularExpressionValidator ID="RegexValidatorEmail" runat="server"
                    ControlToValidate="txtDateOfBirth"
                    ErrorMessage="Please enter a valid email address."
                    ValidationExpression="^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
                    Display="Dynamic" CssClass="errorClass" ForeColor="Red" Font-Size="Smaller">
                </asp:RegularExpressionValidator>
            </div>
            <div class="form-group">
                <asp:Button ID="departmentSubmit" CssClass="btn" Text="Submit" runat="server" OnClick="HandleEmployeeSubmit" />
                <asp:Button ID="employeeUpdate" runat="server" CssClass="btn" Text="Updation" OnClick="HandleEmployeeUpdation" />
                <asp:Button ID="employeeClear" runat="server" OnClick="HandleEmployeeClear" Text="Clear" CssClass="btn btn-danger" />
            </div>
        </div>
        <div style="margin-top: 20px; margin-bottom: 40px;">
            <asp:GridView ID="GridView" runat="server" AutoGenerateColumns="false" EmptyDataText="No records have been added." OnRowDataBound="OnRowDataBound"
                DataKeyNames="EmployeeID" OnRowEditing="OnRowEditing" PageSize="5" AllowPaging="true" OnPageIndexChanging="OnPaging" OnRowDeleting="OnRowDeleting">
                <Columns>
                    <asp:TemplateField HeaderText="EmployeeID">
                        <ItemTemplate>
                            <asp:Label ID="lblEmployeeID" runat="server" Text='<%# Eval("EmployeeID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtEmployeeID" runat="server" Text='<%# Eval("EmployeeID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Name">
                        <ItemTemplate>
                            <asp:Label ID="lblName" runat="server" Text='<%# Eval("Name") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtName" runat="server" Text='<%# Eval("Name") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="DepartmentID">
                        <ItemTemplate>
                            <asp:Label ID="lblDepartmentID" runat="server" Text='<%# Eval("DepartmentID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtDepartmentID" runat="server" Text='<%# Eval("DepartmentID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Gender">
                        <ItemTemplate>
                            <asp:Label ID="lblGender" runat="server" Text='<%# Eval("Gender") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtGender" runat="server" Text='<%# Eval("Gender") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Email">
                        <ItemTemplate>
                            <asp:Label ID="lblDateOfBirth" runat="server" Text='<%# Eval("Email") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtDateOfBirth" runat="server" Text='<%# Eval("Email") %>' Width="140"></asp:TextBox>
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


