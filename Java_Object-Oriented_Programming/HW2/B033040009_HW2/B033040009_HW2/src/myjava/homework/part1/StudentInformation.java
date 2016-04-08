/*
 名稱 : HW2 - List
 學號 : B033040009
 系級 : 資工系 二年級
 姓名 : 蔡宜勳
*/

package myjava.homework.part1;

public class StudentInformation {
	private String Id;
	private String name;
	private int score;
	
	public StudentInformation() {
        this.Id = "";
        this.name = "";
        this.score = 0;
    }
	
	public StudentInformation(String _Id, String _name, int _score) {
        this.Id = _Id;
        this.name = _name;
        this.score = _score;
    }
	
	public void setID(String _Id) {
		this.Id = _Id;
	}
	
	public void setName(String _name) {
		this.name = _name;
	}
	
	public void setScore(int _score) {
		this.score = _score;
	}
	
	public String getID() {
		return this.Id;
	}
	
	public String getName() {
		return this.name;
	}
	
	public int getScore() {
		return this.score;
	}
	
	public void setData(String _Id, String _name, int _score) {
		this.Id = _Id;
		this.name = _name;
		this.score = _score;
	}
	
	public void show_Data() {
		System.out.printf("Student id :%s\n", this.Id);
		System.out.printf("Student name :%s\n", this.name);
		System.out.printf("Student %s %s this project\n", this.name, (this.score >= 60) ? "pass":"fail");
	}
	
	
}
