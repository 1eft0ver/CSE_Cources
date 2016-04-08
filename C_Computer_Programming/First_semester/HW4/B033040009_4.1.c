#include<stdio.h>
#include<stdlib.h>

int main(){
	int salary, year;
	printf("Enter the value of monthly salary : ");
	scanf("%d", &salary);
	
	if (salary <= 30000)
	year = salary * 12 + salary * 1.5;
	
	if (salary > 30000 && salary <= 50000)
	year = salary * 12 + salary * 2;
	
	if (salary > 50000 && salary <= 70000)
	year = salary * 12 + salary * 2.5;
	
	if (salary > 70000)
	year = salary * 12 + salary * 4;
	
	printf("Your annual salary is $%d\n", year);
	system("PAUSE");
	
}
