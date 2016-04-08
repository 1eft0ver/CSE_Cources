package myjava.homework.part2;
import java.util.Scanner;

public class BigOrSmall {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		String instruction;
		while(true) {
			System.out.println("What game you want? (You can input big or small to play, or input exit to quit)");
			instruction = keyboard.next();
			if(instruction.equals("big")) {
				Race game = new Race(RaceKind.BIG);
				game.start();
			}
			
			else if(instruction.equals("small")) {
				Race game = new Race(RaceKind.SMALL);
				game.start();
			}
			
			else if(instruction.equals("exit")) {
				System.out.println("Game Over!!!");
				break;
			}
			
			else {
				System.out.println("You have error input. The game is failed!");
			}
		}
	}
}
