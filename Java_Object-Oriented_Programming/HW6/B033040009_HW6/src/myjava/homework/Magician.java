package myjava.homework;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Magician extends Human implements Skill {
	public Magician() {
		setHp(50);
		setAtack(20);
	}
	
	public int skill_act() {
		System.out.printf("Role's damage: %d\n", (int)(getAttack() * 3.5));
		return (int) (getAttack() * 3.5);
	}

	public int skill_act1() {
		int treatment_amount =  (int )(Math.random() * 30 + 1) ;
		System.out.printf("HP increase: %d\n", treatment_amount);
		setHp( getHp() + treatment_amount);
		return 1;
	}

	public int action() {
		System.out.print("choose(default for the defense) (1) defend (2)fire (3) treatment: ");
		Scanner input = new Scanner(System.in);
		int choice = 1;
		boolean error = false;
		
		do{
			error = false;
			try {
			int temp = input.nextInt();
			choice = temp;
				
				if(choice < 1 || choice > 3) {
					System.out.print("Choice out of range. Defend as default.\n "); 
					choice = 1;
				}
			}
			catch(InputMismatchException exception) {
				System.out.print("Invalid input. Re-enter choice(1) defend (2)fire (3) treatment: "); 
				 input.next();
				 error = true;
			}
		}while(error);
		
		switch (choice) {
		
		case 1:
			System.out.println("defend all the damage.");
			return 0;
			
		case 2:
			int value = skill_act();
			return value;
		
		case 3:
			skill_act1();
			return 1;
		}
		return  -1;
	}

}
