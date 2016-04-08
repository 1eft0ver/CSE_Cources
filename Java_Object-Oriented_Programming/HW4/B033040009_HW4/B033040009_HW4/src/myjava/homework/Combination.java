package myjava.homework;

import java.util.ArrayList;

public class Combination extends fourStarGame{
	public void checkOfWin() {
		ArrayList<Integer> _userNums = getUserNums();
		ArrayList<Integer> _winNums = getWinNums(); 
		
		for(int i = 0 ; i < GAME_NUM_COUNT ; ++i) {
			if( _userNums.get(i) != _winNums.get(i)) {
				System.out.println("**You lose!");
				return;
			}
		}
		System.out.println("**You win!");
	}
}
