<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Salary.aspx.cs" Inherits="CRUD_dotnet_webform.Salary" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Salary</title>
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

        .calendar-style {
            border: 1px solid #ccc;
            padding: 5px;
        }

        .btu {
            text-decoration: none;
            margin: 10px;
            padding: 10px;
            font-size: 12px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="departmentForm">
        <h1>Salary CRUD</h1>
        <div class="formContainer">
            <div class="form-group">
                <asp:TextBox ID="txtSalaryID" runat="server" placeholder="Salary ID" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="salary" runat="server" ControlToValidate="txtSalaryID" ErrorMessage="SalaryID is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtEmployeeID" AutoPostBack="true" runat="server" CssClass="dropdown-style">
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="Employee" runat="server" ControlToValidate="txtEmployeeID" ErrorMessage="EmployeeID is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtSalaryAmount" runat="server" placeholder="Salary Amount" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="salaryAmount" runat="server" ControlToValidate="txtSalaryAmount" ErrorMessage="Salary Amount is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <p>Payment Date</p>
                <asp:Calendar ID="txtPaymentDate" runat="server" CssClass="calendar-style"></asp:Calendar>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtPaymentMethod" runat="server" CssClass="dropdown-style">
                    <asp:ListItem Value="">-- Please Select Payment Method --</asp:ListItem>
                    <asp:ListItem>Direct Deposit</asp:ListItem>
                    <asp:ListItem>Cheque</asp:ListItem>
                    <asp:ListItem>Cash</asp:ListItem>
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="paymentMethod" runat="server" ControlToValidate="txtPaymentMethod" ErrorMessage="Payment Method is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:Button ID="departmentSubmit" CssClass="btn" Text="Submit" runat="server" OnClick="HandleSalarySubmit" />
                <asp:Button ID="SalaryUpdate" CssClass="btn" Text="Updation" runat="server"   OnClick="HandleSalaryUpdation" />
                <asp:Button ID="SalaryClear" CssClass="btn" Text="Clear" runat="server"   OnClick="HandleSalaryClearing" />
            </div>
        </div>
        <div style="margin-top: 20px; margin-bottom: 40px;">
            <asp:GridView ID="GridView" runat="server" AutoGenerateColumns="false" EmptyDataText="No records have been added." OnRowDataBound="OnRowDataBound"
                DataKeyNames="SalaryID" OnRowEditing="OnRowEditing"
                PageSize="5" AllowPaging="true" OnPageIndexChanging="OnPaging" OnRowDeleting="OnRowDeleting">
                <Columns>
                    <asp:TemplateField HeaderText="SalaryID">
                        <ItemTemplate>
                            <asp:Label ID="lblSalaryID" runat="server" Text='<%# Eval("SalaryID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtSalaryID" runat="server" Text='<%# Eval("SalaryID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="EmployeeID">
                        <ItemTemplate>
                            <asp:Label ID="lblEmployeeID" runat="server" Text='<%# Eval("EmployeeID") %>'></asp:Label>
                        </ItemTemplate>
                      <%--  <EditItemTemplate>
                            <asp:TextBox ID="txtEmployeeID" runat="server" Text='<%# Eval("EmployeeID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>--%>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="SalaryAmount">
                        <ItemTemplate>
                            <asp:Label ID="lblSalaryAmount" runat="server" Text='<%# Eval("SalaryAmount") %>'></asp:Label>
                        </ItemTemplate>
                     <%--   <EditItemTemplate>
                            <asp:TextBox ID="txtSalaryAmount" runat="server" Text='<%# Eval("SalaryAmount") %>' type="number" Width="140"></asp:TextBox>
                        </EditItemTemplate>--%>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="PaymentDate">
                        <ItemTemplate>
                            <asp:Label ID="lblPaymentDate" runat="server" Text='<%# Eval("PaymentDate") %>'></asp:Label>
                        </ItemTemplate>
                       <%-- <EditItemTemplate>
                            <asp:TextBox ID="txtPaymentDate" runat="server" Text='<%# Eval("txtPaymentDate") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>--%>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="PaymentMethod">
                        <ItemTemplate>
                            <asp:Label ID="lblPaymentMethod" runat="server" Text='<%# Eval("PaymentMethod") %>'></asp:Label>
                        </ItemTemplate>
                        <%--<EditItemTemplate>
                            <asp:DropDownList ID="txtPaymentMethod" runat="server" CssClass="dropdown-style">
                                <asp:ListItem Value="">-- Please Select Payment Method --</asp:ListItem>
                                <asp:ListItem>Direct Deposit</asp:ListItem>
                                <asp:ListItem>Cheque</asp:ListItem>
                                <asp:ListItem>Cash</asp:ListItem>
                            </asp:DropDownList>
                        </EditItemTemplate>--%>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Link" ShowEditButton="true" ControlStyle-CssClass="btn btu" />
                    <asp:CommandField ButtonType="Link" ShowDeleteButton="true" ControlStyle-BackColor="Red" ControlStyle-CssClass="btn btu" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>
