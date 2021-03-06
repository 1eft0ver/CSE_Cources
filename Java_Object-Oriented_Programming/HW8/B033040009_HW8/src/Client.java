import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ConnectException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
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
		if(args.length > 4 || args.length < 4) {
			System.out.println("Invalid arguments. You have to input arguments as the format : java Client <A quentity> <B quentity> <IP address> <port>");
		}
		else if(isInteger(args[0]) == false || isInteger(args[1]) == false || isInteger(args[3]) == false ) {
			System.out.println("Invalid arguments. Some of your input(except IP address) is not an integer type value.");
		}
		else {
			int request_A = Integer.parseInt(args[0]);
			int request_B = Integer.parseInt(args[1]);
			String IP = args[2];
			int port = Integer.parseInt(args[3]);
			String receive;
			
			System.out.printf("Ip : %s    Port : %d\n", IP, port );
			System.out.printf("Resource requirement : < A : %d B : %d >\n", request_A, request_B);
			System.out.printf("Connecting...\n\n");
			
			try{
				Socket clientSocket = new Socket(IP, port);
				BufferedReader inputFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
				DataOutputStream outputToServer = new DataOutputStream(clientSocket.getOutputStream());
				String strToServer = Integer.toString(request_A) +  " " + Integer.toString(request_B)  + "\n";
				outputToServer.writeBytes(strToServer);
				receive = inputFromServer.readLine();
				System.out.printf("%s\n", receive);
				clientSocket.close();
			} catch(ConnectException e) {
				System.out.println("Socket連線有問題！");
				 e.printStackTrace();
			} catch (IOException e) {
		        e.printStackTrace();
			}
		}

	}

}
