import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
	public static boolean isInteger(String str) {
		Scanner sc = new Scanner(str);
		if(sc.hasNextInt() == false) {
			sc.close();
			return false;
		}
		else{
			sc.close();
			return true;
		}
	}
	
	public static void main(String[] args) throws Exception {
		if(args.length > 3 || args.length < 3) {
			System.out.println("Invalid arguments. You have to input arguments as the format : java Server <A quentity> <B quentity> <port>");
		}
		else if(isInteger(args[0]) == false || isInteger(args[1]) == false || isInteger(args[2]) == false ) {
			System.out.println("Invalid arguments. Some of your input is not an integer type value.");
		}
		else {			
			int A_quantity = Integer.parseInt(args[0]);
			int B_quantity = Integer.parseInt(args[1]);
			int port = Integer.parseInt(args[2]);
			System.out.printf("Port : %d\n",  port);
			System.out.printf("Resource : < A : %d B : %d >\n", A_quantity, B_quantity);
			System.out.println("Listening");
			
			ServerSocket welcomeSocket = new ServerSocket(port);			
			int client_counter = 1;
				while (true) { 
					
					int client_request_A ;
					int client_request_B ;
					Socket connectionSocket = welcomeSocket.accept();
				    BufferedReader inputFromClient =  new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
				    DataOutputStream outputToClient = new DataOutputStream(connectionSocket.getOutputStream());
				    
				    String client_sentence = inputFromClient.readLine();
				    Scanner sc = new Scanner(client_sentence);
				    client_request_A = sc.nextInt();
				    client_request_B = sc.nextInt();
				    sc.close();
					    if(client_request_A > A_quantity || client_request_B > B_quantity) {
					    	outputToClient.writeBytes("[Error] : Resource quantity insyfficient!\n");
					    	System.out.printf("[Client_%d] : resource insufficient! Error...\n", client_counter);
					    	System.out.printf("補貨 -> A : 0 B : 0\n");
					    }
					    else {
					    	
					    	A_quantity -= client_request_A;
					    	B_quantity -= client_request_B;
					    	outputToClient.writeBytes("Service finished!\n");
					    	
					    	System.out.printf("[Client_%d] : 取走商品 -> A : %d B : %d\n", client_counter, client_request_A, client_request_B);
					    	System.out.printf("             商品個數 : < A : %d , B : %d >\n",  A_quantity,  B_quantity);
					    	
					    	A_quantity += client_request_A;
					    	B_quantity += client_request_B;
					    	System.out.printf("補貨 -> A : %d B : %d\n", client_request_A, client_request_B);
					    	System.out.printf("             商品個數 : < A : %d , B : %d >\n",  A_quantity,  B_quantity);
					    	
					    	}
				++client_counter;
		        }
				
		}
	}

}