#include<stdio.h>
#include<stdlib.h>

int main(){
	float fa, fb, fc, fd, fe;
	printf("輸入5個浮點數：\n");
	scanf("%f%f%f%f%f", &fa, &fb, &fc, &fd, &fe);
	printf("$");
	printf("%7.2f\n",fa);
	printf("%8.2f\n",fb);
	printf("%8.2f\n",fc);
	printf("%8.2f\n",fd);
	printf("+");
	printf("%7.2f\n",fe);
	printf("--------\n");
	printf("%8.2f\n\n",fa+fb+fc+fd+fe);
	
	int ia ,ib ,ic ,id ,ie;
	printf("輸入5個整數：\n");
	scanf("%d%d%d%d%d", &ia, &ib, &ic, &id, &ie);
	printf("Hexadecimal\n");
	printf("%7x\n", ia);
	printf("%7x\n", ib);
	printf("%7x\n", ic);
	printf("%7x\n", id);
	printf("+");
	printf("%6x\n", ie);
	printf("--------\n");
	printf("%7x\n\n",ia+ib+ic+id+ie);
	
	printf("Octal\n");
	printf("%7o\n", ia);
	printf("%7o\n", ib);
	printf("%7o\n", ic);
	printf("%7o\n", id);
	printf("+");
	printf("%6o\n", ie);
	printf("--------\n");
	printf("%7o\n\n",ia+ib+ic+id+ie);	
	system("PAUSE");
} 
