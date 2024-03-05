using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication2
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string str = string.Empty;

            if (!IsPostBack)
            {
                labelId.Text = "Vishal";
            }
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            //lbl1.Text = TextBox1.Text;

            string textValue = TextBox1.Text;

            labelId.Text = textValue;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
        
        }

    }
}