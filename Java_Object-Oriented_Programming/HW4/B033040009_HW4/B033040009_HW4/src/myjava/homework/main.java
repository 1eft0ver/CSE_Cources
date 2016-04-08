package myjava.homework;
import java.util.InputMismatchException;
import java.util.Scanner;
public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		while(true) {
			System.out.println("Choose your Four Star Game type : (1:Permutation 2:Combination 3: Exit)");
			Scanner Keyboard = new Scanner(System.in);
			try {
				int	type = Keyboard.nextInt();
				
				if(type == 1) {
					Permutation newGame = new Permutation();
					newGame.generateWinNums();
					newGame.generateUserNums();
					newGame.checkOfWin();
				}
				
				else if(type == 2){
					Combination newGame = new Combination();
					newGame.generateWinNums();
					newGame.generateUserNums();
					newGame.checkOfWin();
				}
				
				else if(type == 3){
					break;
				}
				
				else {
					System.out.println("Wrong input. You're only allowed to input number 1 ~ 3");
				}
			}
			catch(InputMismatchException exception) {
				System.out.println("Wrong input. You're only allowed to input number 1 ~ 3");
				String buf = Keyboard.nextLine();
			}
		}
	}

}
