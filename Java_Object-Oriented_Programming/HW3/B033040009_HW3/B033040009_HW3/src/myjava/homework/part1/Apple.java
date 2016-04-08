package myjava.homework.part1;

public class Apple {
	private String variety;
	private int price;
	private double weight;
	
	public Apple(int _price, double _weight) {
		variety = null;
		price = _price;
		weight = _weight;
	}
	
	public Apple(String _variety, int _price, double _weight) {
		variety = _variety;
		price = _price;
		weight = _weight;
	}
	
	public int getPrice() {
		return price;
	}
	
	protected void setPrice(int _price) {
		price = _price;
	}
	
	public double getWeight() {
		return weight;
	}
	
	public void setWeight(double _weight) {
		weight = _weight;
	}
	
	protected void setVariety(String _variety) {
		variety = _variety;
	}
}
