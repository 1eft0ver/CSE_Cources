/*
 �W�� : HW2 - List
 �Ǹ� : B033040009
 �t�� : ��u�t �G�~��
 �m�W : ���y��
*/

package myjava.homework.part2;
import java.util.ArrayList;

public class ItemList {
	private ArrayList<String> id;
	public ItemList() {	
		id = new ArrayList<>();
	}
	
	public void addItem(String _Item) {
		id.add(_Item);
	}
	
	public void remove(String _Item) {
		if(id.indexOf(_Item) != -1)
			id.remove(id.indexOf(_Item));
		else
			System.out.println("Item not found");
	}
	
	public void printList() {
		for(int i = 0 ; i < id.size() ; ++i) 
			System.out.printf("%d : %s\n", i+1, id.get(i));
	}
}
