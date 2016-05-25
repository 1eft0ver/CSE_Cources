package myjava.homework;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.Scanner;

import org.hsqldb.*;

public class Server {
	private static Connection con = null;
	private static java.sql.Statement stat = null;
	private static ResultSet rs = null;
	private static ResultSetMetaData rsmd = null;
	private static String account, password;
	public static void main(String[] args) throws IOException{
		ServerSocket ss = new ServerSocket(6666);
		System.out.println("Ready to accept connection...");
		while(true) {
			Socket connectionSocket = ss.accept();
			BufferedReader inputFromClient =  new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
		    DataOutputStream outputToClient = new DataOutputStream(connectionSocket.getOutputStream());
		    if(connectionSocket.isConnected()){
		    	System.out.println("Client has Connected.");
		    	String user_info = inputFromClient.readLine();
		    	Scanner split = new Scanner(user_info);
		    	account = split.next();
		    	password = split.next();
		    	/*
		    	System.out.print("SQL account:");
		    	System.out.println(account);
		    	System.out.print("SQL password:");
		    	System.out.println(password);
		    	*/
		    }
		    else
		    	System.out.println("Unconnected.");
		    System.out.println("Ready to catch SQL query...");
		    while(true) {
			    String query = inputFromClient.readLine();
			    System.out.print("[SQL query] :");
			    System.out.println(query);
			    if(query.equals("end"))
			    	break;
			    else {
			    	//url: jdbc:hsqldb:hsql://localhost:9001/java_db
					
					try {
					     Class.forName("org.hsqldb.jdbc.JDBCDriver" );
					     con = DriverManager.getConnection("jdbc:hsqldb:hsql://127.0.0.1:9001/"
					                + "java_db",    // filenames
					                account,           // username
					                password); 
					     stat = con.createStatement();
					     rs = stat.executeQuery(query); 
					     rsmd = rs.getMetaData();
					     int columnsNumber = rsmd.getColumnCount();
					     while(rs.next()) { 
					    	 
					    	 for(int i = 1 ; i <= columnsNumber; i++)
					    		 outputToClient.writeBytes(rs.getString(i) + "\n");
					    	      //System.out.print(String.format("%13s", rs.getString(i))); //Print one element of a row
					    	 
					    	 outputToClient.writeBytes("\0" + "\n");
						 } 
					     outputToClient.writeBytes("endofresult" + "\n");
					     /*
					     DatabaseMetaData md = con.getMetaData();
					     String[] type = {"TABLE"};
					     ResultSet rs = md.getTables(null, null, "%", type);
					     while (rs.next()) {
					       System.out.println(rs.getString(3));
					     }
					      */					     
					 } catch (SQLException e) {
						 System.out.println("SQLException");
						 e.printStackTrace();
					     return;
					 } catch (ClassNotFoundException e) {
						 System.out.println("ClassNotFoundException");
						 e.printStackTrace();
					     return;
					 }
						
			    }
			}
		    
		}
		
		
		
		
		
	}

}
