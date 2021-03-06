package myjava.homework;

/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
*/
import java.util.InputMismatchException;
import java.util.Scanner;

public class Keypad {
	
	//private BufferedReader br;
	private Scanner input;
	// initializes 
	public Keypad () {
		//br = new BufferedReader(new InputStreamReader(System.in));
		input = new Scanner(System.in);
	}
	
	/*
	 *  This function may throw some Exception if the user enters non-integer input.
	 *  You must use try...catch to deal with it.
	 */
	public int getInput() {
		try {
			int temp = input.nextInt();
			return temp;
			}
			catch(InputMismatchException exception) {
				String buf = input.nextLine();
				return -1;
			}
	}
	
}
