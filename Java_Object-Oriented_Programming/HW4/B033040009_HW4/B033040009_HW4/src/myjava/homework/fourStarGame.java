package myjava.homework;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class fourStarGame {
	public static final int GAME_RANGE = 10;
	public static final int GAME_NUM_COUNT = 4;
	private ArrayList<Integer> userNums;
	private ArrayList<Integer> winNums;
	
	public fourStarGame() {
		userNums = new ArrayList<Integer>();
		winNums = new ArrayList<Integer>();
	}
	
	public void generateUserNums() {
		System.out.print("Input four user numbers : ");
		Scanner input = new Scanner(System.in);
		int count = 0;
		while(count < GAME_NUM_COUNT) {
			try {
			int temp = input.nextInt();
			userNums.add(temp);
			++count;
			}
			catch(InputMismatchException exception) {
				System.out.println("Wrong input, try again.");
				String buf = input.nextLine();
				count = 0;
				System.out.print("Input four user numbers : ");
			}
		}
		
	}
	
	public void generateWinNums() {
		boolean[] exist = new boolean[GAME_RANGE]; 
		Arrays.fill(exist, Boolean.FALSE);
		
		int count = 0;
		while(count < GAME_NUM_COUNT) {
			Random rand = new Random();
			int temp = rand.nextInt(10);
			if(exist[temp] == false) {
				winNums.add(temp);
				exist[temp] = Boolean.TRUE;
				++count;
			}			
		}
		
		System.out.print("Win numbers : ");
		for(int i = 0; i < GAME_NUM_COUNT ; ++i) 
			System.out.printf("%d ", winNums.get(i));
		System.out.println("");
	}
	
	public ArrayList<Integer> getUserNums() {
		return userNums;
	}

	public ArrayList<Integer> getWinNums() {
		return winNums;
	}
}
