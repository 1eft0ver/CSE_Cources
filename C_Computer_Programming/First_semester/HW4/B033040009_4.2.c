#include<stdio.h>
#include<stdlib.h>

float ctof( float temp ){
	return temp * 9 / 5 + 32;
}

float ftoc( float temp ){
	return (temp - 32) * 5 / 9;
}
int main(){
	float temp;
	char type;
	printf("Enter the Temperature: ");
	scanf("%f%c", &temp , &type);
	switch( type ){
		
		case'c':
		case'C':
		temp = ctof(temp);
		printf("\nFahrenheit: %.3fF\n", temp);
		break;
		
		case'f':
		case'F':
		temp = ftoc(temp);
		printf("\nCelcius: %.4fC\n", temp);
		break;
		
		default:
		printf("\nERROR!\n");
		
	}
	system("PAUSE");
}
