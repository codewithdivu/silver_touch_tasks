<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Task.aspx.cs" Inherits="CRUD_dotnet_webform.Task" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Task</title>
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
            margin-bottom: 10px;
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
        .btu{
            text-decoration:none;
            margin:15px;
            padding:7px;
            font-size:12px;
        }
        .errorClass{
            margin-bottom:0;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="departmentForm">
        <h1>Task CRUD</h1>
        <div class="formContainer">
            <div class="form-group">
                <asp:TextBox ID="txtTaskID" runat="server" placeholder="Task ID" type="number"></asp:TextBox> 
                <asp:RequiredFieldValidator ID="task" runat="server" ControlToValidate="txtTaskID" ErrorMessage="TaskID is required."   
                ForeColor="Red" Font-Size="Smaller" CssClass="errorClass"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:TextBox ID="txtTaskName" runat="server" placeholder="Task Name" type="text"></asp:TextBox>
                <asp:RequiredFieldValidator ID="name" runat="server" ControlToValidate="txtTaskName" ErrorMessage="Task Name is required."   
                ForeColor="Red" Font-Size="Smaller"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtProjectID" runat="server" CssClass="dropdown-style">
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="project" runat="server" ControlToValidate="txtProjectID" ErrorMessage="Project is required."  ForeColor="Red" Font-Size="Smaller"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtAssignedTo" runat="server" CssClass="dropdown-style">
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="assignedto" runat="server" ControlToValidate="txtAssignedTo" ErrorMessage="Employee is required."  ForeColor="Red" Font-Size="Smaller"></asp:RequiredFieldValidator>
            </div>
            <div class="form-group">
                <asp:DropDownList ID="txtPriority" runat="server" CssClass="dropdown-style">
                    <asp:ListItem Value="">--Select Priority--</asp:ListItem>
                    <asp:ListItem>Low</asp:ListItem>
                    <asp:ListItem>Medium</asp:ListItem>
                    <asp:ListItem>High</asp:ListItem>
                </asp:DropDownList>
                <asp:RequiredFieldValidator ID="priority" runat="server" ControlToValidate="txtPriority" ErrorMessage="Priority is required."  ForeColor="Red" Font-Size="Smaller"></asp:RequiredFieldValidator>                     
            </div>
            <div class="form-group">
                <asp:Button ID="departmentSubmit" CssClass="btn" Text="Submit" runat="server"  OnClick="HandleTaskSubmit" />
                <asp:Button ID="departmentUpdate" runat="server" CssClass="btn" Text="Updation" OnClick="HandleUpdateTask" />
                <asp:Button ID="departmentClear" runat="server" CssClass="btn" Text="Clear" OnClick="HandleClearTask" />
            </div>
        </div>
        <div style="margin-top: 20px;margin-bottom:40px;">
            <asp:GridView ID="GridView" runat="server" AutoGenerateColumns="false" EmptyDataText="No records have been added." OnRowDataBound="OnRowDataBound"
                DataKeyNames="TaskID" OnRowEditing="OnRowEditing"
                PageSize="5" AllowPaging="true" OnPageIndexChanging="OnPaging" 
                OnRowDeleting="OnRowDeleting">
                <Columns>
                    <asp:TemplateField HeaderText="TaskID">
                        <ItemTemplate>
                            <asp:Label ID="lblTaskID" runat="server" Text='<%# Eval("TaskID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtTaskID" runat="server" Text='<%# Eval("TaskID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="TaskName">
                        <ItemTemplate>
                            <asp:Label ID="lblTaskName" runat="server" Text='<%# Eval("TaskName") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtTaskName" runat="server" Text='<%# Eval("TaskName") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="ProjectID">
                        <ItemTemplate>
                            <asp:Label ID="lblProjectID" runat="server" Text='<%# Eval("ProjectID") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtProjectID" runat="server" Text='<%# Eval("ProjectID") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="AssignedTo">
                        <ItemTemplate>
                            <asp:Label ID="lblAssignedTo" runat="server" Text='<%# Eval("AssignedTo") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtAssignedTo" runat="server" Text='<%# Eval("AssignedTo") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Priority">
                        <ItemTemplate>
                            <asp:Label ID="lblPriority" runat="server" Text='<%# Eval("Priority") %>'></asp:Label>
                        </ItemTemplate>
                        <EditItemTemplate>
                            <asp:TextBox ID="txtPriority" runat="server" Text='<%# Eval("Priority") %>' Width="140"></asp:TextBox>
                        </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Link" ShowEditButton="true"   ControlStyle-CssClass="btn btu" />
                    <asp:CommandField ButtonType="Link" ShowDeleteButton="true" ControlStyle-BackColor="Red"  ControlStyle-CssClass="btn btu" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>

