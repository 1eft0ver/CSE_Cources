package myjava.homework;

import java.util.ArrayList;

public class Permutation extends fourStarGame{
	public void checkOfWin() {
		ArrayList<Integer> _userNums = getUserNums();
		ArrayList<Integer> _winNums = getWinNums(); 
		
		for(int i = 0 ; i < GAME_NUM_COUNT ; ++i) {
			//System.out.printf("%d\n",_userNums.get(i));
			
			if( _winNums.contains(_userNums.get(i)) != true) {
				System.out.println("**You lose!");
				return;
			}
		}
		System.out.println("**You win!");
	}
}
