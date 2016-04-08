/*
 名稱 : HW2 - List
 學號 : B033040009
 系級 : 資工系 二年級
 姓名 : 蔡宜勳
*/

package myjava.homework.part1;
import java.util.Scanner;

public class Controller {

	public static void main(String[] args) {
		LinkedList<StudentInformation> Database = new LinkedList<StudentInformation>();
		while(true) {
		System.out.println("Type 1: add a student's data(student ID, student name and score)");
		System.out.println("Type 2: show student's data");
		System.out.println("Type 3: show all student's data.");
		
		Scanner keyboard = new Scanner(System.in);
		int type = keyboard.nextInt();
		
		
			switch(type) {
			case 1:
				String addID, addName;
				int addScore;
				System.out.println("Add new student's data :");
				System.out.print("student id :");
				addID = keyboard.next();
				System.out.print("student name :");
				addName = keyboard.next();
				System.out.print("Score :");
				addScore = keyboard.nextInt();
				
				StudentInformation temp = new StudentInformation(addID, addName, addScore);
				Database.addLast(temp);
				System.out.printf("This is student %d\n", Database.getSize());
				System.out.println("");
				break;
				
			case 2:
				System.out.println("To show which student's information");
				int number = keyboard.nextInt();
				if(number <= 0 || number > Database.getSize()) {
					System.out.println("Data no found");
				}
				
				else {
					Node<StudentInformation> specNode = Database.toSpecNode(number);
					StudentInformation specData = specNode.getData();
					specData.show_Data();
					System.out.printf("This is student %d\n", number);
				}
				System.out.println("");
				break;
				
			case 3:
				System.out.println("=====Student's data=====");
				int pass = 0, notpass = 0;
				for(int i = 1 ; i <= Database.getSize() ; ++i) {
					Node<StudentInformation> specNode = Database.toSpecNode(i);
					StudentInformation specData = specNode.getData();
					if(specData.getScore() >= 60)
						++pass;
					else
						++notpass;
					specData.show_Data();
					System.out.println("");
				}
				System.out.println("========================");
				System.out.printf("Pass : %d\n", pass);
				System.out.printf("No pass : %d\n", notpass);
				System.out.println("");
				break;
			
			default:
				System.out.println("Wrong type. You're only allowed to choose type 1~3.");
				break;
			}
		}
	}

}
