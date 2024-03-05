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
    public partial class Department : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                departmentUpdate.Visible = false;
                departmentClear.Visible = false;
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        private void BindGrid()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            string query = "SELECT * FROM Department";
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
        protected void HandleDepartmentSubmit(object sender, EventArgs e)
        {
            int DepartmentID = Convert.ToInt32(txtDepartmentID.Text);
            string DepartmentName = txtDepartmentName.Text;
            string Location = txtLocation.Text;
            int ManagerID = Convert.ToInt32(txtManagerID.Text);
            int Budget = Convert.ToInt32(txtBudget.Text);

            txtDepartmentID.Text = "";
            txtDepartmentName.Text = "";
            txtLocation.Text = "";
            txtManagerID.Text = "";
            txtBudget.Text = "";

            string query = "INSERT INTO Department VALUES(@DepartmentID, @DepartmentName, @Location, @ManagerID, @Budget)";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@DepartmentID", DepartmentID);
                    cmd.Parameters.AddWithValue("@DepartmentName", DepartmentName);
                    cmd.Parameters.AddWithValue("@Location", Location);
                    cmd.Parameters.AddWithValue("@ManagerID", ManagerID);
                    cmd.Parameters.AddWithValue("@Budget", Budget);
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

            string DepartmentID = (row.FindControl("lblDepartmentID") as Label).Text;
            string DepartmentName = (row.FindControl("lblDepartmentName") as Label).Text;
            string Location = (row.FindControl("lblLocation") as Label).Text;
            string ManagerID = (row.FindControl("lblManagerID") as Label).Text;
            string Budget = (row.FindControl("lblBudget") as Label).Text;

            
            //int DepartmentID1 = int.Parse(DepartmentID);
            //string DepartmentID2 = DepartmentID1.ToString("0.##");
            txtDepartmentID.Text = DepartmentID;
            txtDepartmentName.Text = DepartmentName;
            txtLocation.Text = Location;
            txtManagerID.Text = ManagerID;
            decimal decimalValue = decimal.Parse(Budget);
            int intValue = (int)decimalValue; 
            string formattedValue = intValue.ToString();
            txtBudget.Text = formattedValue;

            departmentUpdate.Visible = true;
            departmentClear.Visible = true;
            departmentSubmit.Visible = false;

            this.BindGrid();

        }
        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int DepartmentID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM Department WHERE DepartmentID=@DepartmentID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@DepartmentID", DepartmentID);
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
        protected void HandleDepartmentUpdation(object sender, EventArgs e)
        {
            int DepartmentID = Convert.ToInt32(txtDepartmentID.Text);
            string DepartmentName = txtDepartmentName.Text;
            string Location = txtLocation.Text;
            int ManagerID = Convert.ToInt32(txtManagerID.Text);
            int Budget = Convert.ToInt32(txtBudget.Text);

            txtDepartmentID.Text = "";
            txtDepartmentName.Text = "";
            txtLocation.Text = "";
            txtManagerID.Text = "";
            txtBudget.Text = "";
            departmentUpdate.Visible = false;
            departmentClear.Visible = false;
            departmentSubmit.Visible = true;

            string query = "UPDATE Department SET DepartmentID=@DepartmentID, DepartmentName=@DepartmentName, Location=@Location, ManagerID=@ManagerID, Budget=@Budget WHERE DepartmentID=@DepartmentID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@DepartmentID", DepartmentID);
                    cmd.Parameters.AddWithValue("@DepartmentName", DepartmentName);
                    cmd.Parameters.AddWithValue("@Location", Location);
                    cmd.Parameters.AddWithValue("@ManagerID", ManagerID);
                    cmd.Parameters.AddWithValue("@Budget", Budget);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        protected void HandleDepartmentClear(object sender, EventArgs e)
        {
            txtDepartmentID.Text = "";
            txtDepartmentName.Text = "";
            txtLocation.Text = "";
            txtManagerID.Text = "";
            txtBudget.Text = "";
            departmentUpdate.Visible = false;
            departmentClear.Visible = false;
            departmentSubmit.Visible = true;
        }
    }
}