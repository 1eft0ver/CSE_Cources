package myjava.homework;

import java.util.InputMismatchException;
import java.util.Scanner;

import org.omg.CORBA.SystemException;

public class Sword extends Human implements Skill{
	public Sword() {
		setHp(100);
		setAtack(30);
	}
		
	public int skill_act() {
		setAtack(getAttack() * 2);
		System.out.printf("Now, your damage: %d\n", getAttack());
		return 2;
	}


	public int skill_act1() {
		setHp(1);
		setAtack(0);
		int damage = (int)(Math.random() * 350 + 100) ;
		System.out.printf("Power!!! Role's damage: %d\n", damage);
		return  damage;
	}

	public int action() {
		System.out.print("choose(default for the attack) (1)attack (2)defend (3)attack*2 (4) Powerful attack: ");
		Scanner input = new Scanner(System.in);
		int choice = 1;
		boolean error = false;
		String line = null;
		do{
			error = false;
			try {
			int temp = input.nextInt();
			choice = temp;
					
				if(choice < 1 || choice > 4) {
					System.out.println("Choice out of range.Attack as default"); 
					choice = 1;
				}
			}
			catch(InputMismatchException exception) {
				System.out.print("Invalid input. Re-enter choice(1)attack (2)defend (3)attack*2 (4) Powerful attack: "); 
				 input.next();
				 error = true;
			}
		}while(error);
		
		
		switch (choice) {
		
		case 1:
			System.out.printf("Role's damage: %d\n", getAttack());
			return 0;
			
		case 2:
			System.out.println("defend all the damage");
			return 1;
		
		case 3:
			int value = skill_act();
			return value;
			
		case 4:
			value = skill_act1();
			return value;
		
		default:
			return -1;
		}
	}
}
