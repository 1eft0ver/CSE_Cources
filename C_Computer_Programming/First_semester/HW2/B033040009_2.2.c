#include<stdio.h>
#include<stdlib.h>

int main(){
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	printf("長: %f\n",a);
	printf("寬: %f\n",b);
	printf("高: %f\n",c);
	printf("周長: %f\n",(a+b)*2);
	printf("面積: %f\n",a*b);
	printf("表面積: %f\n",(a*b + b*c + c*a)*2);
	printf("體積: %f\n",a*b*c);
	
	system("PAUSE");
	
}
