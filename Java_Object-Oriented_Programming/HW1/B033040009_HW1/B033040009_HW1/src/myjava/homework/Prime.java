/*
 名稱 : HW1 - Prime
 學號 : B033040009
 系級 : 資工系 二年級
 姓名 : 蔡宜勳
*/


package myjava.homework;
import java.util.Scanner;

public class Prime {
	
	boolean isPrime(int n) {
	    if(n == 2)
	    	return true;
		else if (n % 2 == 0) 
	    	return false;
	    
	    for(int i = 3 ; i * i <= n ; i += 2) {
	        if(n % i == 0)
	            return false;
	    }
	    return true;
	}
	
	public static void main(String[] args) {
		while(true)
		{
		System.out.println("1.Check whether it's prime number");
		System.out.println("2.Find prime numbers(2~N)");
		System.out.println("3.Leave");
		
		
		Scanner keyboard = new Scanner(System.in);
		int instruction = keyboard.nextInt();
			if(instruction == 1)
			{
				System.out.println("Input the number :");
				int number = keyboard.nextInt();
				Prime v = new Prime();
				
				if(number < 2)
				{
					System.out.println("Input error : N must be equal greater than 2");
				}
				
				else if(v.isPrime(number))
				{
					System.out.print(number);
					System.out.print(' ');
					System.out.println("is a prime.");
				}
				
				else if(!v.isPrime(number))
				{
					System.out.print(number);
					System.out.print(' ');
					System.out.println("is not a prime.");
				}
			}
			
			else if(instruction == 2)
			{
				System.out.println("Input the number :");
				int number = keyboard.nextInt();
				if(number < 2)
				{
					System.out.println("Input error : N must be equal greater than 2");
				}
				
				else{
					System.out.print("Show the prime numbers(2 ~ ");
					System.out.print(number);
					System.out.println(')');
					Prime v = new Prime();
					int line_check = 0;
					String format = "%-8s";
					for(int i = 2 ; i <= number ; i += 1) 
					{
				        if(v.isPrime(i))
				        {
				        	line_check += 1;
				        	if(line_check > 10)
				        	{
				        		line_check = 1;
				        		System.out.println();
				        		System.out.printf(format, i);
				        	}
				        	else
				        	{
				        		System.out.printf(format, i);
				        	}
				        }
				            
				    }
					System.out.println();
				}
			}
			
			else if(instruction == 3){
				System.out.println("Bye!!!");
				keyboard.close();
				break;
			}
		}
	}

}
