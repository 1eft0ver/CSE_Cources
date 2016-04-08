package myjava.homework.part2;
import java.util.Random;

public class Race {
	private int kind = 0;
	public Race(int _kind) {
		kind = _kind;
	}
	
	public void start() {
		Random rand = new Random();
		int myCardNum = rand.nextInt(13) + 1;
		int comCardNum = rand.nextInt(13) + 1;
		int myCardSuitRank = rand.nextInt(4) + 1;
		int comCardSuitRank = rand.nextInt(4) + 1;
		String myCard = "", comCard = "";
		
		if(myCardNum == comCardNum && myCardSuitRank == comCardSuitRank) {
			while(myCardNum == comCardNum && myCardSuitRank == comCardSuitRank){
				myCardNum = rand.nextInt(13) + 1;
				myCardSuitRank = rand.nextInt(4) + 1;
			}
		}
		
		if(myCardSuitRank == 4) 
			myCard = "_Spade_";
		else if(myCardSuitRank == 3)
			myCard = "_Heart_";
		else if(myCardSuitRank == 2)
			myCard = "_Diamond_";
		else if(myCardSuitRank == 1)
			myCard = "_Club_";
		
		if(comCardSuitRank == 4) 
			comCard = "_Spade_";
		else if(comCardSuitRank == 3)
			comCard = "_Heart_";
		else if(comCardSuitRank == 2)
			comCard = "_Diamond_";
		else if(comCardSuitRank == 1)
			comCard = "_Club_";
		
		if(myCardNum <= 9)
			myCard += Integer.toString(myCardNum + 1);
		else if(myCardNum == 10)
			myCard += 'J';
		else if(myCardNum == 11)
			myCard += 'Q';
		else if(myCardNum == 12)
			myCard += 'K';
		else if(myCardNum == 13)
			myCard += 'A';
		
		if(comCardNum <= 9)
			comCard += Integer.toString(comCardNum + 1);
		else if(comCardNum == 10)
			comCard += 'J';
		else if(comCardNum == 11)
			comCard += 'Q';
		else if(comCardNum == 12)
			comCard += 'K';
		else if(comCardNum == 13)
			comCard += 'A';
		
		if(kind == RaceKind.BIG){
			System.out.printf("Your hand is %s\n", myCard);
			System.out.printf("Com's hand is %s\n", comCard);
			
			if(myCardNum > comCardNum) {
				System.out.printf("%s is bigger than %s\n", myCard, comCard);
				System.out.println("So, you win!");
			}
			else if (myCardNum < comCardNum) {
				System.out.printf("%s is smaller than %s\n", myCard, comCard);
				System.out.println("So, Com win!");
			}
			else {
				if(myCardSuitRank > comCardSuitRank){
					System.out.printf("%s is bigger than %s\n", myCard, comCard);
					System.out.println("So, you win!");
				}
				else if(myCardSuitRank < comCardSuitRank){
					System.out.printf("%s is smaller than %s\n", myCard, comCard);
					System.out.println("So, Com win!");
				}
					
			}
		}
		
		else if(kind == RaceKind.SMALL){
			System.out.printf("Your hand is %s\n", myCard);
			System.out.printf("Com's hand is %s\n", comCard);
			
			if(myCardNum > comCardNum) {
				System.out.printf("%s is bigger than %s\n", myCard, comCard);
				System.out.println("So, Com win!");
			}
			else if (myCardNum < comCardNum) {
				System.out.printf("%s is smaller than %s\n", myCard, comCard);
				System.out.println("So, You win!");
			}
			else {
				if(myCardSuitRank > comCardSuitRank){
					System.out.printf("%s is bigger than %s\n", myCard, comCard);
					System.out.println("So, Com win!");
				}
				else if(myCardSuitRank < comCardSuitRank){
					System.out.printf("%s is smaller than %s\n", myCard, comCard);
					System.out.println("So, You win!");
				}
					
			}
		}
	}
}
