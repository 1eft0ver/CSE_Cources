#include<stdio.h>
#include<stdlib.h>

int main(){
	int a, b, c, d, e , f, g, h;
	float average;
	char rank;
	while(1){
		scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
		average = (a + b + c + d + e + f + g + h) *1.0 / 8;
		
		if (average >= 90)
		rank = 'a';
		
		else if(average >= 80 && average < 90)
		rank = 'b';
		
		else if(average >= 70 && average < 80)
		rank = 'c';
		
		else if(average >= 60 && average < 70)
		rank = 'd';
		
		else if(average < 60)
		rank = 'e';
		
		switch( rank ){
			
		case 'a':
		printf("�ӦP�Ǫ���������: %.2f\n", average);
		printf("�ӦP�Ǫ����Z����: �u��\n");
		break;
		
		case 'b':
		printf("�ӦP�Ǫ���������: %.2f\n", average);
		printf("�ӦP�Ǫ����Z����: �ҵ�\n");
		break;
		
		case 'c':
		printf("�ӦP�Ǫ���������: %.2f\n", average);
		printf("�ӦP�Ǫ����Z����: �A��\n");
		break;
		
		case 'd':
		printf("�ӦP�Ǫ���������: %.2f\n", average);
		printf("�ӦP�Ǫ����Z����: ����\n");
		break;
		
		case 'e':
		printf("�ӦP�Ǫ���������: %.2f\n", average);
		printf("�ӦP�Ǫ����Z����: �B��\n");
		break;
		
		}
	}
}
