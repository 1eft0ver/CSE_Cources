package myjava.homework;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ConnectException;
import java.net.Socket;
import java.util.Scanner;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;

public class Client {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Scanner input_int = new Scanner(System.in);
		String address, account, password, query;
		int  port;
		System.out.println("Address:");
		address = input.nextLine();
		System.out.println("Port:");
		port = input_int.nextInt();
		System.out.println("HSQL Database account:");
		account = input.nextLine();
		System.out.println("HSQL Database password:");
		password = input.nextLine();
		try{
			
			Socket clientSocket = new Socket(address, port);
			BufferedReader inputFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			DataOutputStream outputToServer = new DataOutputStream(clientSocket.getOutputStream());
			String receive;
			
			if(clientSocket.isConnected()){
				System.out.println("Connection to database success.");
				outputToServer.writeBytes(account + " " + password + "\n");
			}
			else
				System.out.println("Connection to database fail.");
			
			while(true){
				System.out.println("Enter your SQL query:");
				query = input.nextLine();
				outputToServer.writeBytes(query + "\n");
					
				if(query.equals("end"))
					break;
				else {
					String filePath = "result.csv";
					CSVWriter writer = new CSVWriter(new FileWriter(filePath));
					int counter = 0;
					String[] fields = new String[1000];
					while(true) {
						receive = inputFromServer.readLine();
						try{
							if(receive.equals("endofresult"))
								break;
							
							else if(receive.equals("\0")){
								writer.writeNext(fields);
								counter = 0;
							}
							
							else
								fields[counter++] = receive;
							
						}catch (Exception e) {
							e.printStackTrace();
						    return;
						}
					}
					writer.close();
				}
			}
			clientSocket.close();
			
		} catch(ConnectException e) {
			System.out.println("Socket connect failed!");
			 e.printStackTrace();
		} catch (IOException e) {
	        e.printStackTrace();
		}
	}

}
