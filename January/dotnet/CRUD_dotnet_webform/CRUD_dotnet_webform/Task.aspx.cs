using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Threading.Tasks;

namespace CRUD_dotnet_webform
{
    public partial class Task : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                BindEmployee();
                BindProject();
                departmentUpdate.Visible = false;
                departmentClear.Visible = false;
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        private void BindGrid()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            string query = "SELECT * FROM Task";
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
        protected void HandleTaskSubmit(object sender, EventArgs e)
        {
            int TaskID = Convert.ToInt32(txtTaskID.Text);
            string TaskName = txtTaskName.Text;
            int ProjectID = Convert.ToInt32(txtProjectID.SelectedValue);
            int AssignedTo = Convert.ToInt32(txtAssignedTo.SelectedValue);
            string Priority = txtPriority.SelectedValue;

            txtTaskID.Text = "";
            txtTaskName.Text = "";
            txtPriority.SelectedValue = "";
            txtProjectID.SelectedValue = "-1";
            txtAssignedTo.SelectedValue = "-1";


            string query = "INSERT INTO Task VALUES(@TaskID, @TaskName, @ProjectID, @AssignedTo, @Priority)";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@TaskID", TaskID);
                    cmd.Parameters.AddWithValue("@TaskName", TaskName);
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
                    cmd.Parameters.AddWithValue("@AssignedTo", AssignedTo);
                    cmd.Parameters.AddWithValue("@Priority", Priority);
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

            string TaskID = (row.FindControl("lblTaskID") as Label).Text;
            string TaskName = (row.FindControl("lblTaskName") as Label).Text;
            string ProjectID = (row.FindControl("lblProjectID") as Label).Text;
            string AssignedTo = (row.FindControl("lblAssignedTo") as Label).Text;
            string Priority = (row.FindControl("lblPriority") as Label).Text;

            txtTaskName.Text = TaskName;
            txtTaskID.Text = TaskID;
            txtAssignedTo.SelectedValue = AssignedTo;
            txtPriority.SelectedValue = Priority;
            txtProjectID.SelectedValue = ProjectID;

            departmentUpdate.Visible = true;
            departmentClear.Visible = true;
            departmentSubmit.Visible = false;

            this.BindGrid();
        }
        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int TaskID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM Task WHERE TaskID=@TaskID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@TaskID", TaskID);
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
        private void BindEmployee()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            SqlConnection con = new SqlConnection(constr);
            string com = "select -1 as EmployeeID, '--Select Employee--' as Name, 3 as DepartmentID ,'Male' as Gender, '2023-01-10' as DateOfBirth union all Select * from Employee";
            SqlDataAdapter adpt = new SqlDataAdapter(com, con);
            DataTable dt = new DataTable();
            adpt.Fill(dt);
            txtAssignedTo.DataSource = dt;
            txtAssignedTo.DataTextField = "Name";
            txtAssignedTo.DataValueField = "EmployeeID";
            txtAssignedTo.DataBind();
        }
        private void BindProject()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            SqlConnection con = new SqlConnection(constr);
            string com = "select -1 as ProjectID, '--Select Project--' as ProjectName, '2023-01-10' as StartDate, '2023-01-10' as EndDate, 'Active' as Status union all Select * from Project";
            SqlDataAdapter adpt = new SqlDataAdapter(com, con);
            DataTable dt = new DataTable();
            adpt.Fill(dt);
            txtProjectID.DataSource = dt;
            txtProjectID.DataTextField = "ProjectName";
            txtProjectID.DataValueField = "ProjectID";
            txtProjectID.DataBind();
        }
        protected void HandleUpdateTask(object sender, EventArgs e)
        {
            int TaskID = Convert.ToInt32(txtTaskID.Text);
            string TaskName = txtTaskName.Text;
            int ProjectID = Convert.ToInt32(txtProjectID.Text);
            int AssignedTo = Convert.ToInt32(txtAssignedTo.Text);
            string Priority = txtPriority.Text;

            txtTaskID.Text = "";
            txtTaskName.Text = "";
            txtPriority.SelectedValue = "";
            txtProjectID.SelectedValue = "-1";
            txtAssignedTo.SelectedValue = "-1";
            departmentUpdate.Visible = false;
            departmentClear.Visible = false;
            departmentSubmit.Visible = true;


            string query = "UPDATE Task SET TaskID=@TaskID, TaskName=@TaskName, ProjectID=@ProjectID, AssignedTo=@AssignedTo, Priority=@Priority WHERE TaskID=@TaskID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@TaskID", TaskID);
                    cmd.Parameters.AddWithValue("@TaskName", TaskName);
                    cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
                    cmd.Parameters.AddWithValue("@AssignedTo", AssignedTo);
                    cmd.Parameters.AddWithValue("@Priority", Priority);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        protected void HandleClearTask(object sender, EventArgs e)
        {
            txtTaskID.Text = "";
            txtTaskName.Text = "";
            txtPriority.SelectedValue = "";
            txtProjectID.SelectedValue = "-1";
            txtAssignedTo.SelectedValue = "-1";
            departmentUpdate.Visible = false;
            departmentClear.Visible = false;
            departmentSubmit.Visible = true;
        }
    }
}