#include<stdio.h>
#include<stdlib.h>

int main(){
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	printf("��: %f\n",a);
	printf("�e: %f\n",b);
	printf("��: %f\n",c);
	printf("�P��: %f\n",(a+b)*2);
	printf("���n: %f\n",a*b);
	printf("���n: %f\n",(a*b + b*c + c*a)*2);
	printf("��n: %f\n",a*b*c);
	
	system("PAUSE");
	
}
