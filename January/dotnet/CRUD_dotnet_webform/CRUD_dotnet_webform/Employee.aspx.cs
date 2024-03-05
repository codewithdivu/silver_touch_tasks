using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CRUD_dotnet_webform
{
    public partial class Employee : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                BindDepartment();
                employeeUpdate.Visible = false;
                employeeClear.Visible = false;
            }
            GridView.EditIndex = -1;
            BindGrid();
        }
        private void BindGrid()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            string query = "SELECT * FROM Employee";
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlDataAdapter sda = new SqlDataAdapter(query, con))
                {
                    using (DataTable dt = new DataTable())
                    {
                        sda.Fill(dt);
                        GridView.DataSource = dt;
                        GridView.DataBind();
                    }
                }
            }
        }
        protected void OnRowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow && e.Row.RowIndex != GridView.EditIndex)
            {
                (e.Row.Cells[6].Controls[0] as LinkButton).Attributes["onclick"] = "return confirm('Do you want to delete this row?');";
            }
        }
        protected void HandleEmployeeSubmit(object sender, EventArgs e)
        {
            int EmployeeID = Convert.ToInt32(txtEmployeeID.Text);
            int DepartmentID = Convert.ToInt32(txtDepartmentID.SelectedValue);
            string Name = txtName.Text;
            string Gender = txtGender.SelectedValue;
            string DateOfBirth = txtDateOfBirth.Text;


            txtEmployeeID.Text = "";
            txtDepartmentID.SelectedValue = "-1";
            txtName.Text = "";
            txtDateOfBirth.Text = "";
            RadioButtonList radiobhai = (RadioButtonList)FindControl("txtGender");
            foreach (ListItem item in radiobhai.Items)
            {
                if (item.Selected)
                {
                    item.Selected = false;
                    break;
                }
            }

            string query = "INSERT INTO Employee VALUES(@EmployeeID, @Name, @DepartmentID, @Gender, @DateOfBirth)";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@EmployeeID", EmployeeID);
                    cmd.Parameters.AddWithValue("@DepartmentID", DepartmentID);
                    cmd.Parameters.AddWithValue("@Name", Name);
                    cmd.Parameters.AddWithValue("@Gender", Gender);
                    cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            this.BindGrid();
        }
        protected void OnRowEditing(object sender, GridViewEditEventArgs e)
        {
            GridViewRow row = GridView.Rows[e.NewEditIndex];
            string EmployeeID = (row.FindControl("lblEmployeeID") as Label).Text;
            string Name = (row.FindControl("lblName") as Label).Text;
            string DepartmentID = (row.FindControl("lblDepartmentID") as Label).Text;
            string Gender = (row.FindControl("lblGender") as Label).Text;
            string DateOfBirth = (row.FindControl("lblDateOfBirth") as Label).Text;

            txtEmployeeID.Text = EmployeeID;
            txtName.Text = Name;
            txtDepartmentID.SelectedValue = DepartmentID;
            txtGender.SelectedValue = Gender;
            txtDateOfBirth.Text = DateOfBirth;

            employeeUpdate.Visible = true;
            employeeClear.Visible = true;
            departmentSubmit.Visible = false;
            this.BindGrid();
        }
        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int EmployeeID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM Employee WHERE EmployeeID=@EmployeeID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@EmployeeID", EmployeeID);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            this.BindGrid();
        }
        protected void OnPaging(object sender, GridViewPageEventArgs e)
        {
            GridView.PageIndex = e.NewPageIndex;
            this.BindGrid();
        }
        protected void HandleEmployeeUpdation(object sender, EventArgs e)
        {
            int EmployeeID = Convert.ToInt32(txtEmployeeID.Text);
            int DepartmentID = Convert.ToInt32(txtDepartmentID.SelectedValue);
            string Name = txtName.Text;
            string Gender = txtGender.SelectedValue;
            string DateOfBirth = txtDateOfBirth.Text;

            txtEmployeeID.Text = "";
            txtDepartmentID.SelectedValue = "-1";
            txtName.Text = "";
            RadioButtonList radiobhai = (RadioButtonList)FindControl("txtGender");
            foreach (ListItem item in radiobhai.Items)
            {
                if (item.Selected)
                {
                    item.Selected = false;
                    break; 
                }
            }

            txtDateOfBirth.Text = "";
            employeeUpdate.Visible = false;
            employeeClear.Visible = false;
            departmentSubmit.Visible = true;



            string query = "UPDATE Employee SET DepartmentID=@DepartmentID, Name=@Name, Gender=@Gender, Email=@DateOfBirth WHERE EmployeeID=@EmployeeID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@EmployeeID", EmployeeID);
                    cmd.Parameters.AddWithValue("@DepartmentID", DepartmentID);
                    cmd.Parameters.AddWithValue("@Name", Name);
                    cmd.Parameters.AddWithValue("@Gender", Gender);
                    cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        private void BindDepartment()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            SqlConnection con = new SqlConnection(constr);
            string com = "select -1 as DepartmentID, '--Select Department--' as DepartmentName, 'oman' as Location, -1 as ManagerID, 8888 as Budget union all Select * from Department";
            SqlDataAdapter adpt = new SqlDataAdapter(com, con);
            DataTable dt = new DataTable();
            adpt.Fill(dt);
            txtDepartmentID.DataSource = dt;
            txtDepartmentID.DataTextField = "DepartmentName";
            txtDepartmentID.DataValueField = "DepartmentID";
            txtDepartmentID.DataBind();

        }

        protected void HandleEmployeeClear(object sender, EventArgs e)
        {
            txtEmployeeID.Text = "";
            txtDepartmentID.SelectedValue = "-1";
            txtName.Text = "";
            txtGender.SelectedValue = "";
            txtDateOfBirth.Text = "";
            employeeUpdate.Visible = false;
            employeeClear.Visible = false;
            departmentSubmit.Visible = true;

            GridView.EditIndex = -1;
            this.BindGrid();
        }

    }
}