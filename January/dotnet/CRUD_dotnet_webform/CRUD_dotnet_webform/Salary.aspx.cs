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
    public partial class Salary : System.Web.UI.Page
    {
        private object txtPaymentDatee;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                BindEmployee();
                SalaryUpdate.Visible = false;
                SalaryClear.Visible = false;
            }
            GridView.EditIndex = -1;
            BindGrid();
        }

        private void BindGrid()
        {
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            string query = "SELECT * FROM Salary";
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
        protected void HandleSalarySubmit(object sender, EventArgs e)
        {
            int SalaryID = Convert.ToInt32(txtSalaryID.Text);
            int EmployeID = Convert.ToInt32(txtEmployeeID.SelectedValue);
            int SalaryAmount = Convert.ToInt32(txtSalaryAmount.Text);
            string PaymentDate = txtPaymentDate.SelectedDate.ToString();
            string PaymentMethod = txtPaymentMethod.SelectedValue;

            txtSalaryID.Text = "";
            txtEmployeeID.Text = "-1";
            txtSalaryAmount.Text = "";
            txtPaymentDate.SelectedDate = DateTime.Today;
            txtPaymentMethod.SelectedValue = "";

            string query = "INSERT INTO Salary VALUES(@SalaryID, @EmployeID, @SalaryAmount, @PaymentDate, @PaymentMethod)";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@SalaryID", SalaryID);
                    cmd.Parameters.AddWithValue("@EmployeID", EmployeID);
                    cmd.Parameters.AddWithValue("@SalaryAmount", SalaryAmount);
                    cmd.Parameters.AddWithValue("@PaymentDate", PaymentDate);
                    cmd.Parameters.AddWithValue("@PaymentMethod", PaymentMethod);
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

            string SalaryID = (row.FindControl("lblSalaryID") as Label).Text;
            string EmployeeID = (row.FindControl("lblEmployeeID") as Label).Text;
            string SalaryAmount = (row.FindControl("lblSalaryAmount") as Label).Text;
            string PaymentDate = (row.FindControl("lblPaymentDate") as Label).Text;
            string PaymentMethod = (row.FindControl("lblPaymentMethod") as Label).Text;

            txtSalaryID.Text = SalaryID;
            txtEmployeeID.SelectedValue = EmployeeID;
            decimal decimalValue = decimal.Parse(SalaryAmount);
            int intValue = (int)decimalValue;
            string formattedValue = intValue.ToString();
            txtSalaryAmount.Text = formattedValue;

            DateTime paymentDate = DateTime.Parse(PaymentDate);
            txtPaymentDate.SelectedDate = paymentDate;
            txtPaymentMethod.Text = PaymentMethod;

            SalaryUpdate.Visible = true;
            SalaryClear.Visible = true;
            departmentSubmit.Visible = false;

            this.BindGrid();

        }

        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int SalaryID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM Salary WHERE SalaryID=@SalaryID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@SalaryID", SalaryID);
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
            txtEmployeeID.DataSource = dt;
            txtEmployeeID.DataTextField = "Name";
            txtEmployeeID.DataValueField = "EmployeeID";
            txtEmployeeID.DataBind();
        }
        protected void OnRowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            GridViewRow row = GridView.Rows[e.RowIndex];
            int SalaryID = Convert.ToInt32(GridView.DataKeys[e.RowIndex].Values[0]);
            int EmployeeID = Convert.ToInt32((row.FindControl("txtEmployeeID") as TextBox).Text);
            double SalaryAmount = Convert.ToDouble((row.FindControl("txtSalaryAmount") as TextBox).Text);
            string PaymentDate = (row.FindControl("txtPaymentDate") as Calendar).SelectedDate.ToString();
            string PaymentMethod = (row.FindControl("txtPaymentMethod") as DropDownList).SelectedValue;

            string query = "UPDATE Salary SET SalaryID=@SalaryID, EmployeeID=@EmployeeID, SalaryAmount=@SalaryAmount, PaymentDate=@PaymentDate, PaymentMethod=@PaymentMethod WHERE SalaryID=@SalaryID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@SalaryID", SalaryID);
                    cmd.Parameters.AddWithValue("@EmployeeID", EmployeeID);
                    cmd.Parameters.AddWithValue("@SalaryAmount", SalaryAmount);
                    cmd.Parameters.AddWithValue("@PaymentDate", PaymentDate);
                    cmd.Parameters.AddWithValue("@PaymentMethod", PaymentMethod);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }

        protected void HandleSalaryUpdation(object sender, EventArgs e)
        {
            int SalaryID = Convert.ToInt32(txtSalaryID.Text);
            int EmployeeID = Convert.ToInt32(txtEmployeeID.SelectedValue);
            int SalaryAmount = Convert.ToInt32(txtSalaryAmount.Text);
            DateTime PaymentDate = txtPaymentDate.SelectedDate;
            string PaymentMethod = txtPaymentMethod.SelectedValue;


            txtSalaryID.Text = "";
            txtEmployeeID.SelectedValue = "-1";
            txtSalaryAmount.Text = "";
            txtPaymentDate.SelectedDate = DateTime.Today;
            txtPaymentMethod.SelectedValue = "";

            SalaryUpdate.Visible = false;
            SalaryClear.Visible = false;
            departmentSubmit.Visible = true;


            string query = "UPDATE Salary SET SalaryID=@SalaryID, EmployeeID=@EmployeeID, SalaryAmount=@SalaryAmount, PaymentDate=@PaymentDate, PaymentMethod=@PaymentMethod WHERE SalaryID=@SalaryID";
            string constr = ConfigurationManager.ConnectionStrings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@SalaryID", SalaryID);
                    cmd.Parameters.AddWithValue("@EmployeeID", EmployeeID);
                    cmd.Parameters.AddWithValue("@SalaryAmount", SalaryAmount);
                    cmd.Parameters.AddWithValue("@PaymentDate", PaymentDate);
                    cmd.Parameters.AddWithValue("@PaymentMethod", PaymentMethod);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView.EditIndex = -1;
            this.BindGrid();
        }
        protected void HandleSalaryClearing(object sender, EventArgs e)
        {
            txtSalaryID.Text = "";
            txtEmployeeID.SelectedValue = "-1";
            txtSalaryAmount.Text = "";
            txtPaymentDate.SelectedDate = DateTime.Today;
            txtPaymentMethod.SelectedValue = "";

            SalaryUpdate.Visible = false;
            SalaryClear.Visible = false;
            departmentSubmit.Visible = true;
        }
    }
}