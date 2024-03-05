<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="CRUD_dotnet_webform._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
       <h1 style="margin-bottom:40px">Comapany Database</h1>
    <main style="display: grid; grid-template-columns: repeat(auto-fill, minmax(300px, 1fr)); grid-gap: 20px;">
        <div class="box" onclick="location.href='Department';" style="border: 2px solid #000; border-radius: 5px; padding: 20px; width: 100%; text-align: center; cursor: pointer; transition: background-color 0.3s;">
            <h2 style="margin-bottom: 1.5rem">Department</h2>
            <p>Here you can find Department CRUD</p>
        </div>
        <div class="box" onclick="location.href='Employee';" style="border: 2px solid #000; border-radius: 5px; padding: 20px; width: 100%; text-align: center; cursor: pointer; transition: background-color 0.3s;">
            <h2 style="margin-bottom: 1.5rem">Employee</h2>
            <p>Here you can find Employee CRUD</p>
        </div>
        <div class="box" onclick="location.href='Task';" style="border: 2px solid #000; border-radius: 5px; padding: 20px; width: 100%; text-align: center; cursor: pointer; transition: background-color 0.3s;">
            <h2 style="margin-bottom: 1.5rem">Task</h2>
            <p>Here you can find Task CRUD</p>
        </div>
        <div class="box" onclick="location.href='Project';" style="border: 2px solid #000; border-radius: 5px; padding: 20px; width: 100%; text-align: center; cursor: pointer; transition: background-color 0.3s;">
            <h2 style="margin-bottom: 1.5rem">Project</h2>
            <p>Here you can find Project CRUD</p>
        </div>
        <div class="box" onclick="location.href='Salary';" style="border: 2px solid #000; border-radius: 5px; padding: 20px; width: 100%; text-align: center; cursor: pointer; transition: background-color 0.3s;">
            <h2 style="margin-bottom: 1.5rem">Salary</h2>
            <p>Here you can find Salary CRUD</p>
        </div>
    </main>

</asp:Content>
