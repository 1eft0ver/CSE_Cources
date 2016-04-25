package myjava.homework;
import java.util.InputMismatchException;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		while(true){
			int monster_hp =  (int )(Math.random() * 150 + 150) ;
			System.out.printf("Monster's Hp: %d\n", monster_hp);
			System.out.print("Choose your character(By default Sword) (1)Sword (2)Magician: ");
			Scanner input = new Scanner(System.in);
			int choice = 1;
			boolean error = false;
			String line = null;
			
			do{
				error = false;
				try {
				int temp = input.nextInt();
				choice = temp;
					
					if(choice < 1 || choice > 2) {
						System.out.println("Choice out of range. Choose Sword as default "); 
						choice = 1;
					}
				}
				catch(InputMismatchException exception) {
					System.out.print("Invalid input. Re-enter choice(1)Sword (2)Magician: "); 
					 input.next();
					 error = true;
				}
			}while(error);
			
			
			if(choice == 1) { //Sword
				System.out.println("Role Hp:100");
				Human player = new Sword();
				do{
					int value = player.action();
					if(value == 0) { //attack
						int monster_damage =  (int)(Math.random() * 41 ) ;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						player.setHp( player.getHp() - monster_damage);
						monster_hp = monster_hp - player.getAttack();
							if(player.getHp() < 0)
								player.setHp(0);
							if(monster_hp < 0)
								monster_hp = 0;
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					else if(value == 1){ //defend
						int monster_damage =  (int)(Math.random() * 41 ) ;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					else if(value == 2){ //attack*2
						int monster_damage =  (int)(Math.random() * 41 ) ;
						player.setHp( player.getHp() - monster_damage);
						if(player.getHp() < 0)
							player.setHp(0);
						if(monster_hp < 0)
							monster_hp = 0;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					else if(value >= 100 && value <= 450){ //Power
						int monster_damage =  (int)(Math.random() * 41 ) ;
						monster_hp = monster_hp - value;
						if(player.getHp() < 0)
							player.setHp(0);
						if(monster_hp < 0)
							monster_hp = 0;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					
				}while(player.getHp() > 0 && monster_hp > 0);
				
					if(player.getHp() <= 0 && monster_hp <= 0)
						System.out.println("Deuce\n\n\n");
					
					else if(player.getHp() > 0) 
						System.out.println("Win\n\n\n");
					
					else if (monster_hp > 0) 
						System.out.println("Lose\n\n\n");
			}
			
			else if(choice == 2) { //magician
				System.out.println("Role Hp:50");
				Human player = new Magician();;
				do{
					int value = player.action();
					if(value == 0) { //defend
						int monster_damage =  (int)(Math.random() * 41 ) ;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					else if(value == 1){ //treatment
						int monster_damage =  (int)(Math.random() * 41 ) ;
						player.setHp( player.getHp() - monster_damage);
						if(player.getHp() < 0)
							player.setHp(0);
						if(monster_hp < 0)
							monster_hp = 0;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					else if(value > player.getAttack()){ //fire
						int monster_damage =  (int)(Math.random() * 41 ) ;
						monster_hp = monster_hp - value;
						player.setHp( player.getHp() - monster_damage);
						if(player.getHp() < 0)
							player.setHp(0);
						if(monster_hp < 0)
							monster_hp = 0;
						System.out.printf("Monster's damage: %d\n", monster_damage);
						System.out.printf("Role's Hp: %d\n", player.getHp());
						System.out.printf("Monster's Hp: %d\n", monster_hp);
					}
					
				}while(player.getHp() > 0 && monster_hp > 0);
				
					if(player.getHp() <= 0 && monster_hp <= 0)
						System.out.println("Deuce\n\n\n");
					
					else if(player.getHp() > 0) 
						System.out.println("Win\n\n\n");
					
					else if (monster_hp > 0) 
						System.out.println("Lose\n\n\n");
					
			}
					
		}
	}
}
