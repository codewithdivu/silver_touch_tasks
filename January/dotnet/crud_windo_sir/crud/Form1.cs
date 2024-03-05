using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace crud
{
    public partial class Form1 : Form
    {
        public int ID = 0;
        public int EditID = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {

            SqlParameter[] parameter = new SqlParameter[6];
            parameter[0] = new SqlParameter("@ID", EditID);
            parameter[1] = new SqlParameter("@Name", txtName.Text);
            parameter[2] = new SqlParameter("@MobileNo", txtMobileNo.Text);
            parameter[3] = new SqlParameter("@Email", txtEmail.Text);
            parameter[4] = new SqlParameter("@Address", txtAddress.Text);
            parameter[5] = new SqlParameter("@OutID", 0);
            parameter[5].Direction = ParameterDirection.Output;

            sqlGet.executeNonQueryRef("SP_AddUpdateStudent", ref parameter, CommandType.StoredProcedure);

            if (parameter[5].Value != null && Convert.ToInt32(parameter[5].Value) > 0)
            {
                clear();
                BindData();
                btnSave.Text = "Save";
                MessageBox.Show("Success", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Failed");
                MessageBox.Show("Failed", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            clear();
        }
        public void clear()
        {
            EditID = 0;
            txtAddress.Text = "";
            txtEmail.Text = "";
            txtName.Text = "";
            txtMobileNo.Text = "";
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (ID == 0)
            {
                MessageBox.Show("Please Select Any Record");
                return;
            }

            sqlGet.executeNonQuery("update tblStudent set Isdeleted=1 where ID=" + ID.ToString(), CommandType.Text);
            BindData();
            clear();
            MessageBox.Show("Record Deleted Successfully");

        }
        public void BindData()
        {
            ID = 0;
            DataSet ds = sqlGet.getDataset("select ID,Name,MobileNo,Email,Address from tblStudent where Isdeleted=0", CommandType.Text);

            dgvStudent.DataSource = null;
            dgvStudent.Rows.Clear();

            if (ds != null && ds.Tables.Count > 0 && ds.Tables[0] != null)
            {
                dgvStudent.DataSource = ds.Tables[0];
                if (ds.Tables[0].Rows.Count > 0)
                {
                    ID = Convert.ToInt32(ds.Tables[0].Rows[0]["ID"]);
                }

            }
            dgvStudent.Columns["ID"].Visible = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BindData();

            string msg = "";
            sqlGet.calculateDiv(1, 0, out msg);

            int a = 0;
        }

        private void dgvStudent_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex == -1)
            {
                return; //check if row index is not selected
            }


            ID = Convert.ToInt32(dgvStudent.Rows[e.RowIndex].Cells["ID"].Value);
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            if (ID == 0)
            {
                MessageBox.Show("Please Select Any Record");
                return;
            }

            DataSet ds = sqlGet.getDataset("select ID,Name,MobileNo,Email,Address from tblStudent where ID=" + ID.ToString(), CommandType.Text);
            if (ds != null && ds.Tables.Count > 0 && ds.Tables[0] != null)
            {
                EditID = Convert.ToInt32(ds.Tables[0].Rows[0]["ID"]);
                txtAddress.Text = Convert.ToString(ds.Tables[0].Rows[0]["Address"]);
                txtEmail.Text = Convert.ToString(ds.Tables[0].Rows[0]["Email"]);
                txtName.Text = Convert.ToString(ds.Tables[0].Rows[0]["Name"]);
                txtMobileNo.Text = Convert.ToString(ds.Tables[0].Rows[0]["MobileNo"]);
            }

            btnSave.Text = "Update";

        }
    }
}
