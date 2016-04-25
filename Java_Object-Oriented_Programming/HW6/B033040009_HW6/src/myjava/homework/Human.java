package myjava.homework;

public abstract class Human {
	private int hp;
	private int attack;
	
	public int getHp() {
		return hp;
	}
	
	public void setHp(int value) {
		hp = value;
	}
	
	public int getAttack() {
		return attack;
	}
	
	public void setAtack(int value) {
		attack = value;
	}
	
	public abstract int action();
	//public abstract int skill_act();
}
