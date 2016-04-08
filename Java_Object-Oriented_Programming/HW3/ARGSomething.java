package myjava.homework.part1;

public class ARGSomething {
	

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
