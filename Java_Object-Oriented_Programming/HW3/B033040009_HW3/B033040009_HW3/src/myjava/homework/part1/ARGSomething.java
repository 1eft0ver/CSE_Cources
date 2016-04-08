package myjava.homework.part1;

public class ARGSomething {
	int avg(int... numbers) {	
		int sum = 0;
		
		for (int temp : numbers) 
			sum += temp;
		
		return sum / numbers.length;
	}
	
	double avg(double... numbers) { 
		double sum = 0;
		
		for (double temp : numbers) 
			sum += temp;
		
		return sum / numbers.length;
	}
	
	static int avg(String one_word) {
		System.out.print("The number of this word is ");
		return one_word.length();
	}
	
	static double avg(String... strings) {
		double sum = 0;
		
		for(String temp : strings) 
			sum += temp.length();
		
		System.out.print("The avg number of these words is ");
		return sum / strings.length;
		
	}
	
	static double avg(Apple one_apple) {
		double total_weight = one_apple.getWeight();
		int total_cost = one_apple.getPrice();
		System.out.print("The price per gram is ");
		return total_weight / total_cost;
	}
	
	static double avg(Apple... apples) {
		double total_weight = 0;
		int total_cost = 0;
		
		for(Apple temp : apples) {
			total_weight += temp.getWeight();
			total_cost += temp.getPrice();
		}
		
		System.out.print("The price per gram is ");
		return total_weight / total_cost;
	}
	
	
	public static void main(String[] args) {
		// You cannot modify anything in the main function!!!!
		ARGSomething t=new ARGSomething();
		System.out.println(t.avg(10,20));
		System.out.println(t.avg(20,60,120));
		System.out.println(t.avg(10,20,30,40));
		
		System.out.println(t.avg(0.1,0.2));
		System.out.println(t.avg(20,60.0,120));
		System.out.println(t.avg(10,20,new Integer(30),40.0));
		
		System.out.println(avg("Apple"));
		System.out.println(avg("Apple","Cat"));
		System.out.println(avg("Apple","Cat",new String("Bee")));
		
		System.out.println(avg(new Apple(10,59.5)));
		System.out.println(avg(new Apple(10,59.5),new Apple("Washington",30,80.3)));
		Apple green=new Apple("Granny Smith",30,88);
		System.out.println(avg(new Apple(10,59.5),new Apple("Washington",30,80.3),green));
	}

}
