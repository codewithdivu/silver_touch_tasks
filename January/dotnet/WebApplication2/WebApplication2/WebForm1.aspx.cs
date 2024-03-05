using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
                BindStateDropdown();
            }
        }

        protected void btnAdd_Click(object sender, EventArgs e)
        {
            string FIRST_NAME = txtFIRST_NAME.Text;
            string LAST_NAME = txtLAST_NAME.Text;
            string EMPLOYEE_CODE = txtEMPLOYEE_CODE.Text;
            int WORKING_HOURS = Convert.ToInt32(txtWORKING_HOURS.Text);
            string EMAIL = txtEMAIL.Text;
            string MOBILE_NO = txtMOBILE_NO.Text;

            txtFIRST_NAME.Text = "";
            txtLAST_NAME.Text = "";
            txtEMPLOYEE_CODE.Text = "";
            txtWORKING_HOURS.Text = "";
            txtEMAIL.Text = "";
            txtMOBILE_NO.Text = "";

            string query = "INSERT INTO EMPLOYEE_MASTER VALUES(@FIRST_NAME, @LAST_NAME, @EMPLOYEE_CODE, @WORKING_HOURS, @EMAIL, @MOBILE_NO)";
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@FIRST_NAME", FIRST_NAME);
                    cmd.Parameters.AddWithValue("@LAST_NAME", LAST_NAME);
                    cmd.Parameters.AddWithValue("@EMPLOYEE_CODE", EMPLOYEE_CODE);
                    cmd.Parameters.AddWithValue("@WORKING_HOURS", WORKING_HOURS);
                    cmd.Parameters.AddWithValue("@EMAIL", EMAIL);
                    cmd.Parameters.AddWithValue("@MOBILE_NO", MOBILE_NO);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            this.BindGrid();
        }

        private void BindGrid()
        {
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            string query = "SELECT * FROM EMPLOYEE_MASTER";
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlDataAdapter sda = new SqlDataAdapter(query, con))
                {
                    using (DataTable dt = new DataTable())
                    {
                        sda.Fill(dt);
                        GridView1.DataSource = dt;
                        GridView1.DataBind();
                    }
                }
            }
        }

        protected void OnRowEditing(object sender, GridViewEditEventArgs e)
        {
            GridView1.EditIndex = e.NewEditIndex;
            this.BindGrid();
        }

        protected void OnRowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            GridViewRow row = GridView1.Rows[e.RowIndex];
            int ID = Convert.ToInt32(GridView1.DataKeys[e.RowIndex].Values[0]);
            string FIRST_NAME = (row.FindControl("txtFIRST_NAME") as TextBox).Text;
            string LAST_NAME = (row.FindControl("txtLAST_NAME") as TextBox).Text;
            string EMPLOYEE_CODE = (row.FindControl("txtEMPLOYEE_CODE") as TextBox).Text;
            string WORKING_HOURS = (row.FindControl("txtWORKING_HOURS") as TextBox).Text;
            string EMAIL = (row.FindControl("txtEMAIL") as TextBox).Text;
            string MOBILE_NO = (row.FindControl("txtMOBILE_NO") as TextBox).Text;

            string query = "UPDATE EMPLOYEE_MASTER SET FIRST_NAME=@FIRST_NAME, LAST_NAME=@LAST_NAME, EMPLOYEE_CODE=@EMPLOYEE_CODE, WORKING_HOURS=@WORKING_HOURS, EMAIL=@EMAIL, MOBILE_NO=@MOBILE_NO WHERE ID=@ID";
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ID", ID);
                    cmd.Parameters.AddWithValue("@FIRST_NAME", FIRST_NAME);
                    cmd.Parameters.AddWithValue("@LAST_NAME", LAST_NAME);
                    cmd.Parameters.AddWithValue("@EMPLOYEE_CODE", EMPLOYEE_CODE);
                    cmd.Parameters.AddWithValue("@WORKING_HOURS", WORKING_HOURS);
                    cmd.Parameters.AddWithValue("@EMAIL", EMAIL);
                    cmd.Parameters.AddWithValue("@MOBILE_NO", MOBILE_NO);

                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            GridView1.EditIndex = -1;
            this.BindGrid();
        }

        protected void OnRowCancelingEdit(object sender, EventArgs e)
        {
            GridView1.EditIndex = -1;
            this.BindGrid();
        }

        protected void OnRowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int ID = Convert.ToInt32(GridView1.DataKeys[e.RowIndex].Values[0]);
            string query = "DELETE FROM EMPLOYEE_MASTER WHERE ID=@ID";
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            using (SqlConnection con = new SqlConnection(constr))
            {
                using (SqlCommand cmd = new SqlCommand(query))
                {
                    cmd.Parameters.AddWithValue("@ID", ID);
                    cmd.Connection = con;
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            this.BindGrid();
        }

        protected void OnRowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow && e.Row.RowIndex != GridView1.EditIndex)
            {
                (e.Row.Cells[6].Controls[2] as LinkButton).Attributes["onclick"] = "return confirm('Do you want to delete this row?');";
            }
        }

        protected void OnPaging(object sender, GridViewPageEventArgs e)
        {
            GridView1.PageIndex = e.NewPageIndex;
            this.BindGrid();
        }

        private void BindStateDropdown()
        {
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            SqlConnection con = new SqlConnection(constr);
            string com = "select -1 as StateId, '--select--' as StateName  union all Select * from GM_State";
            SqlDataAdapter adpt = new SqlDataAdapter(com, con);
            DataTable dt = new DataTable();
            adpt.Fill(dt);
            ddlState.DataSource = dt;
            ddlState.DataTextField = "StateName";
            ddlState.DataValueField = "StateId";
            ddlState.DataBind();
        }
       
        protected void ddlState_SelectedIndexChanged(object sender, EventArgs e)
        {
            BindCityDropdown(ddlState.SelectedValue);
        }

        private void BindCityDropdown(string StateId)
        {
            string constr = ConfigurationManager.AppSettings["ConnectionString"].ToString();
            SqlConnection con = new SqlConnection(constr);
            string com = "Select * from GM_City WHERE StateId = " + Convert.ToInt32(StateId);
            SqlDataAdapter adpt = new SqlDataAdapter(com, con);
            DataTable dt = new DataTable();
            adpt.Fill(dt);
            ddlCity.DataSource = dt;
            ddlCity.DataTextField = "CityName";
            ddlCity.DataValueField = "Cityid";
            ddlCity.DataBind();
        }

    }
}