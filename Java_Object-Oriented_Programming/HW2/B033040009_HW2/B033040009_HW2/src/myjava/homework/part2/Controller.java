/*
 名稱 : HW2 - List
 學號 : B033040009
 系級 : 資工系 二年級
 姓名 : 蔡宜勳
*/

package myjava.homework.part2;

import java.util.Scanner;

public class Controller {

	public static void main(String[] args) {
		ItemList list = new ItemList();
		while(true) {
			System.out.println("Type 1: add item to list");
			System.out.println("Type 2: remove item from list");
			System.out.println("Type 3: show the list");
			
			Scanner keyboard = new Scanner(System.in);
			int type = keyboard.nextInt();
			
			switch(type) {
				case 1:
					System.out.print("Add item name :");
					list.addItem(keyboard.next());
					System.out.println("");
					break;
					
				case 2:
					System.out.print("Remove item name :");
					list.remove(keyboard.next());
					System.out.println("");
					break;
					
				case 3:
					System.out.println("Show the list");
					list.printList();
					System.out.println("");
					break;
				default:
					System.out.println("Wrong type. You're only allowed to choose type 1~3.");
					break;
			}			
		}
	}

}
