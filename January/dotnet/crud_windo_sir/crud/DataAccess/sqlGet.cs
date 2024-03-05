using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

public static class sqlGet
{
    public static DataSet getDataset(string cmdName, SqlParameter[] cmpPar, CommandType cmdType)
    {

        
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        try
        {
            foreach (SqlParameter par in cmpPar)
            {
                sqlCmd.Parameters.Add(par);
            }
        }
        catch (Exception ex)
        {
        }

        DataSet ds = new DataSet();

        SqlDataAdapter da = new SqlDataAdapter(sqlCmd);
        sqlConn.Open();
        da.Fill(ds);
        sqlConn.Close();

        return ds;

    }

    public static DataSet getDataset(string cmdName, CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        DataSet ds = new DataSet();

        SqlDataAdapter da = new SqlDataAdapter(sqlCmd);
        sqlConn.Open();
        da.Fill(ds);
        sqlConn.Close();

        return ds;

    }

    public static DataTable getDataTable(string cmdName, SqlParameter[] cmpPar, CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        try
        {
            foreach (SqlParameter par in cmpPar)
            {
                sqlCmd.Parameters.Add(par);
            }
        }
        catch (Exception ex)
        {
        }

        DataTable dt = new DataTable();

        SqlDataAdapter da = new SqlDataAdapter(sqlCmd);
        sqlConn.Open();
        da.Fill(dt);
        sqlConn.Close();

        return dt;

    }

    public static DataTable getDatatable(string cmdName, CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        DataTable dt = new DataTable();

        SqlDataAdapter da = new SqlDataAdapter(sqlCmd);
        sqlConn.Open();
        da.Fill(dt);
        sqlConn.Close();

        return dt;

    }

    public static void executeNonQuery(string cmdName, SqlParameter[] cmpPar, CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        try
        {
            foreach (SqlParameter par in cmpPar)
            {
                sqlCmd.Parameters.Add(par);
            }
        }
        catch (Exception ex)
        {
        }

        sqlConn.Open();
        sqlCmd.ExecuteNonQuery();
        sqlConn.Close();

    }

    public static void executeNonQuery(string cmdName , CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        sqlConn.Open();
        sqlCmd.ExecuteNonQuery();
        sqlConn.Close();

    }

    public static void executeNonQueryRef(string cmdName, ref SqlParameter[] cmpPar, CommandType cmdType)
    {
        string sqlConnstr = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
        SqlConnection sqlConn = new SqlConnection(sqlConnstr);

        SqlCommand sqlCmd = sqlConn.CreateCommand();
        sqlCmd.CommandText = cmdName;
        sqlCmd.CommandType = cmdType;

        try
        {
            foreach (SqlParameter par in cmpPar)
            {
                sqlCmd.Parameters.Add(par);
            }
        }
        catch (Exception ex)
        {
        }

        sqlConn.Open();
        sqlCmd.ExecuteNonQuery();
        sqlConn.Close();

    }
    public static decimal  calculateDiv(decimal a, decimal b,out string  msg) {

        msg = "";
        if (b==0)
        {
            msg = "divide by 0 exception";
            return 0;
        }
        return a / b;
    }

}