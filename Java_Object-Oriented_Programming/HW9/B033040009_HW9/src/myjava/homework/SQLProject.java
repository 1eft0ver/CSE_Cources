package myjava.homework;

import java.sql.*;
import java.util.*; 

public class SQLProject {
	private static Connection con = null; //Database objects
	private Statement stat1 = null; //執行,傳入之sql為完整字串 
	private Statement stat2 = null; 
	private ResultSet rs1 = null; //結果集 
	private ResultSet rs2 = null;
	private PreparedStatement pst = null; 
	  //執行,傳入之sql為預儲之字申,需要傳入變數之位置 
	  //先利用?來做標示 
	private String selectSQL_students = "select * from students"; 
	private String selectSQL_grades = "select * from grades "; 
	
	public void Query1_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_students + " order by birthmonth"); 
	      System.out.println("Query 1 result:");
		  System.out.println("");
		  System.out.println(String.format("%13s%13s", "id", "birthmonth"));
		  System.out.println("");
	      while(rs1.next()) { 
	    	if(rs1.getString("sex").equals("M"))
	    		System.out.println(String.format("%13s%13s", rs1.getString("id"), rs1.getInt("birthmonth")));
	      } 
	      System.out.println("");
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	public void Query2_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_grades + " order by id"); 
	      System.out.println("Query 2 result:");
		  System.out.println("");
	      System.out.println(String.format("%13s%13s%13s", "id", "math", "chinese")); 
	      System.out.println("");
	      while(rs1.next()) { 
	    	  if(rs1.getInt("math") >= 90 && rs1.getInt("chinese") >= 80)
	    		  System.out.println(String.format("%13s%13s%13s", rs1.getString("id"), rs1.getInt("math"), rs1.getInt("chinese")));
	      } 
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	public void Query3_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_grades); 
	      System.out.println("Query 3 result:");
		  System.out.println("");
	      System.out.println(String.format("%13s%13s%13s", "c_max", "m_min", "e_avg")); 
	      System.out.println("");
	      
	      float count = 0;
	      int c_max = 0;
	      int m_min = 100;
	      float e_sum = 0;
	      while(rs1.next()) { 
	    	  if(rs1.getInt("chinese") > c_max)
	    		  c_max = rs1.getInt("chinese");
	    	  if(rs1.getInt("math") < m_min)
	    		  m_min = rs1.getInt("math");
	    	  e_sum += rs1.getInt("english");
	    	  ++count;
	      } 
	      System.out.println(String.format("%13s%13s%13.4f", c_max, m_min, e_sum/count)); 
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	public void Query4_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      stat2 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_grades + " order by english desc");
	      rs2 = stat2.executeQuery(selectSQL_students + " order by id");
	      System.out.println("Query 4 result:");
		  System.out.println("");
	      System.out.println(String.format("%13s%13s%13s", "id", "sex", "english")); 
	      System.out.println("");
	      while(rs1.next()) { 
	    	  if(rs1.getInt("english") > 50) {
	    		  String target_name = rs1.getString("id");
	    		  rs2.first();
	    		  
	    		  while(rs2.next()) {
	    			  if(rs2.getString("id").equals(target_name)) {
	    				  System.out.println(String.format("%13s%13s%13s", rs2.getString("id"), rs2.getString("sex"), rs1.getInt("english")));
	    				  break;
	    			  }
	    		  }
	    		  
	    	  }
	      } 
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	public void Query5_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_grades + " order by id"); 
	      System.out.println("Query 5 result:");
		  System.out.println("");
	      System.out.println(String.format("%13s%13s", "id", "grade_avg")); 
	      System.out.println("");
	      while(rs1.next()) { 
	    	  float avg = (float) ((rs1.getInt("math") + rs1.getInt("chinese") + rs1.getInt("english"))/3.0);
	    	  System.out.println(String.format("%13s%13.4f", rs1.getString("id"), avg));
	      } 
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	public void Query6_result() { 
	    try { 
	      stat1 = con.createStatement(); 
	      rs1 = stat1.executeQuery(selectSQL_students + " order by birthmonth"); 
	      System.out.println("Query 6 result:");
		  System.out.println("");
	      System.out.println(String.format("%13s%13s", "birthmonth", "count")); 
	      System.out.println("");
	      
	      int month_iterator = 1;
	      int current_combo = 0;
	      while(rs1.next()) { 
	    	  if(rs1.getInt("birthmonth") == month_iterator) {
	    		  ++current_combo;
	    	  }
	    	  else if(rs1.getInt("birthmonth") != month_iterator && current_combo == 0) {
	    		  ++month_iterator;
	    	  }
	    	  else{
	    		  if(current_combo > 1) {
	    			  System.out.println(String.format("%13s%13s", month_iterator, current_combo));
	    		  }
	    		  month_iterator = rs1.getInt("birthmonth");
	    		  current_combo = 1;
	    	  }
	      } 
	    } catch(SQLException e) { 
	      System.out.println("DropDB Exception :" + e.toString()); 
	    } finally { 
	      Close(); 
	    } 
	}
	
	private void Close() { 
	    try { 
	      if(rs1!=null) { 
	        rs1.close(); 
	        rs1 = null; 
	      } if(rs2!=null) { 
		        rs2.close(); 
		        rs2 = null; 
		      } 
	      if(stat1!=null) { 
	        stat1.close(); 
	        stat1 = null; 
	      } 
	      if(pst!=null) { 
	        pst.close(); 
	        pst = null; 
	      } 
	    } 
	    catch(SQLException e) { 
	      System.out.println("Close Exception :" + e.toString()); 
	    } 
	} 
	   
	
	public static void main(String[] args) throws SQLException {
		String account, password;
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter useraccount:");
		account = input.nextLine();
		System.out.println("Please enter password:");
		password = input.nextLine();
		input.close();
		
		try { 
		      Class.forName("com.mysql.jdbc.Driver"); //註冊driver 
		      con = DriverManager.getConnection( 	  //取得connection
		      "jdbc:mysql://localhost/java_db?useUnicode=true&characterEncoding=Big5&useSSL=true", 
		      account, password); 
		      System.out.println("Connection establish");     
		      System.out.println("");  
		} catch(ClassNotFoundException e) { 
			  System.out.println("DriverClassNotFound :"+e.toString());  //有可能會產生sqlexception 
		} catch(SQLException x) { 
		      System.out.println("Exception :"+x.toString()); 
		}
		
		/* 確認能否讀取到Table列表
			DatabaseMetaData dmd = con.getMetaData();
		    ResultSet rs1 = dmd.getSchemas();
		    String[] types = { "TABLE" };
		    ResultSet resultSet = dmd.getTables(null, "java_db", "%", types);

		    while (resultSet.next()) {
		      String tableName = resultSet.getString(3);

		      String tableCatalog = resultSet.getString(1);
		      String tableSchema = resultSet.getString(2);
		      System.out.println(tableName);
		    }
		*/
		
		SQLProject sql = new SQLProject();
		sql.Query1_result();
		sql.Query2_result();
		sql.Query3_result();
		sql.Query4_result();
		sql.Query5_result();
		sql.Query6_result();
	}
	
	

}
