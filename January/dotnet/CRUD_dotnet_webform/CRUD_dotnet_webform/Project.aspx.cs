using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Runtime.InteropServices.ComTypes;

namespace CRUD_dotnet_webform
{
    public partial class Project : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                ProjectUpdate.Visible = false;
                ProjectClear.Visible = false;
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        private void BindGrid()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            string query = "SELECT * FROM Project";
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
        protected void HandleProjectSubmit(object sender, EventArgs e)
        {
            int ProjectID = Convert.ToInt32(txtProjectID.Text);
            string ProjectName = txtProjectName.Text;
            string StartDate = txtStartDate.SelectedDate.ToString();
            string EndDate = txtEndDate.SelectedDate.ToString();
            string Status = txtStatus.SelectedValue;

            txtProjectID.Text = "";
            txtProjectName.Text = "";
            txtStartDate.SelectedDate = DateTime.Today;
            txtEndDate.SelectedDate = DateTime.Today;
            txtStatus.SelectedValue = "";

            string query = "INSERT INTO Project VALUES(@ProjectID, @ProjectName, @StartDate, @EndDate, @Status)";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
                    cmd.Parameters.AddWithValue("@ProjectName", ProjectName);
                    cmd.Parameters.AddWithValue("@StartDate", StartDate);
                    cmd.Parameters.AddWithValue("@EndDate", EndDate);
                    cmd.Parameters.AddWithValue("@Status", Status);
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

            string ProjectID = (row.FindControl("lblProjectID") as Label).Text;
            string ProjectName = (row.FindControl("lblProjectName") as Label).Text;
            string StartDate = (row.FindControl("lblStartDate") as Label).Text;
            string EndDate = (row.FindControl("lblEndDate") as Label).Text;
            string Status = (row.FindControl("lblStatus") as Label).Text;

        
            txtProjectID.Text = ProjectID;
            txtProjectName.Text = ProjectName;
            DateTime startDate = DateTime.Parse(StartDate);
            DateTime endDate = DateTime.Parse(EndDate);
            txtStartDate.SelectedDate = startDate;
            txtEndDate.SelectedDate = endDate;
            txtStatus.Text = Status;

            ProjectUpdate.Visible = true;
            ProjectClear.Visible = true;
            departmentSubmit.Visible = false;

            this.BindGrid();
        }
        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int ProjectID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM Project WHERE ProjectID=@ProjectID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
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
        protected void OnRowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            GridViewRow row = GridView.Rows[e.RowIndex];
            int ProjectID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string ProjectName = (row.FindControl("txtProjectName") as TextBox).Text;
            string StartDate = (row.FindControl("txtStartDate") as TextBox).Text;
            string EndDate = (row.FindControl("txtEndDate") as TextBox).Text;
            string Status = (row.FindControl("txtStatus") as TextBox).Text;

            string query = "UPDATE Project SET ProjectID=@ProjectID, ProjectName=@ProjectName, StartDate=@StartDate, EndDate=@EndDate, Status=@Status WHERE ProjectID=@ProjectID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
                    cmd.Parameters.AddWithValue("@ProjectName", ProjectName);
                    cmd.Parameters.AddWithValue("@StartDate", StartDate);
                    cmd.Parameters.AddWithValue("@EndDate", EndDate);
                    cmd.Parameters.AddWithValue("@Status", Status);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }

        protected void HandleProjecttUpdation(object sender, EventArgs e)
        {
            int ProjectID = Convert.ToInt32(txtProjectID.Text);
            string ProjectName = txtProjectName.Text;
            string StartDate = txtStartDate.SelectedDate.ToString();
            string EndDate = txtEndDate.SelectedDate.ToString();
            string Status = txtStatus.SelectedValue;

            txtProjectID.Text = "";
            txtProjectName.Text = "";
            txtStartDate.SelectedDate = DateTime.Now;
            txtEndDate.SelectedDate = DateTime.Now;
            txtStatus.Text = "";

            ProjectUpdate.Visible = false;
            ProjectClear.Visible = false;
            departmentSubmit.Visible = true;

            string query = "UPDATE Project SET ProjectID=@ProjectID, ProjectName=@ProjectName, StartDate=@StartDate, EndDate=@EndDate, Status=@Status WHERE ProjectID=@ProjectID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
                    cmd.Parameters.AddWithValue("@ProjectName", ProjectName);
                    cmd.Parameters.AddWithValue("@StartDate", StartDate);
                    cmd.Parameters.AddWithValue("@EndDate", EndDate);
                    cmd.Parameters.AddWithValue("@Status", Status);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();

        }
        protected void HandleProjecttClearing(object sender, EventArgs e)
        {
            txtProjectID.Text = "";
            txtProjectName.Text = "";
            txtStartDate.SelectedDate = DateTime.Now;
            txtEndDate.SelectedDate = DateTime.Now;
            txtStatus.Text = "";
            ProjectUpdate.Visible = false;
            ProjectClear.Visible = false;
            departmentSubmit.Visible = true;
        }

    }
}