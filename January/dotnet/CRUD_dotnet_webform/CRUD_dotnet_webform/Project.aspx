<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Project.aspx.cs" Inherits="CRUD_dotnet_webform.Project" %>


<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Project</title>
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

        .calendar-style {
            border: 1px solid #ccc;
            padding: 5px;
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
    </style>
</head>
<body>
    <form id="form1" runat="server" class="departmentForm">
        <h1>Project CRUD</h1>
        <div class="formContainer">
            <div class="form-group">
                <asp:TextBox ID="txtProjectID" runat="server" placeholder="Project ID" type="number"></asp:TextBox>
                <asp:RequiredFieldValidator ID="project" runat="server" ControlToValidate="txtProjectID" ErrorMessage="ProjectID is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtProjectName" runat="server" placeholder="Project Name" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="projectname" runat="server" ControlToValidate="txtProjectName" ErrorMessage="ProjectName is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <p>Start Date</p>
                <asp:Calendar ID="txtStartDate" runat="server" CssClass="calendar-style"></asp:Calendar>
            </div>
            <div class="form-group">
                <p>End Date</p>
                <asp:Calendar ID="txtEndDate" runat="server" CssClass="calendar-style"></asp:Calendar>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtStatus" runat="server" CssClass="dropdown-style">
                    <asp:ListItem Value="">-- Please Select Status --</asp:ListItem>
                    <asp:ListItem>Active</asp:ListItem>
                    <asp:ListItem>Inactive</asp:ListItem>
                    <asp:ListItem>Completed</asp:ListItem>
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="status" runat="server" ControlToValidate="txtStatus" ErrorMessage="Status is required."
                    ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:Button ID="departmentSubmit" CssClass="btn" Text="Submit" runat="server" OnClick="HandleProjectSubmit" />
                <asp:Button ID="ProjectUpdate" runat="server" CssClass="btn" Text="Updation" OnClick="HandleProjecttUpdation" />
                <asp:Button ID="ProjectClear" runat="server" CssClass="btn" Text="Clear" OnClick="HandleProjecttClearing" />
            </div>
        </div>
        <div style="margin-top: 20px; margin-bottom: 50px;">
            <asp:GridView ID="GridView" runat="server" AutoGenerateColumns="false" EmptyDataText="No records have been added." OnRowDataBound="OnRowDataBound"
                DataKeyNames="ProjectID" OnRowEditing="OnRowEditing"                 PageSize="5" AllowPaging="true" OnPageIndexChanging="OnPaging" OnRowDeleting="OnRowDeleting">
                <Columns>
                    <asp:TemplateField HeaderText="ProjectID">
                        <ItemTemplate>
                            <asp:Label ID="lblProjectID" runat="server" Text='<%# Eval("ProjectID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtProjectIDD" runat="server" Text='<%# Eval("ProjectID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="ProjectName">
                        <ItemTemplate>
                            <asp:Label ID="lblProjectName" runat="server" Text='<%# Eval("ProjectName") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtProjectName" runat="server" Text='<%# Eval("ProjectName") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="StartDate">
                        <ItemTemplate>
                            <asp:Label ID="lblStartDate" runat="server" Text='<%# Eval("StartDate") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtStartDate" runat="server" Text='<%# Eval("StartDate") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="EndDate">
                        <ItemTemplate>
                            <asp:Label ID="lblEndDate" runat="server" Text='<%# Eval("EndDate") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtEndDate" runat="server" Text='<%# Eval("EndDate") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Status">
                        <ItemTemplate>
                            <asp:Label ID="lblStatus" runat="server" Text='<%# Eval("Status") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtStatus" runat="server" Text='<%# Eval("Status") %>' Width="140"></asp:TextBox>
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
