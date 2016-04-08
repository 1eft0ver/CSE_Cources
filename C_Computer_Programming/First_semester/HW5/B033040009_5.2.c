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
		printf("該同學的平均分數: %.2f\n", average);
		printf("該同學的成績等級: 優等\n");
		break;
		
		case 'b':
		printf("該同學的平均分數: %.2f\n", average);
		printf("該同學的成績等級: 甲等\n");
		break;
		
		case 'c':
		printf("該同學的平均分數: %.2f\n", average);
		printf("該同學的成績等級: 乙等\n");
		break;
		
		case 'd':
		printf("該同學的平均分數: %.2f\n", average);
		printf("該同學的成績等級: 丙等\n");
		break;
		
		case 'e':
		printf("該同學的平均分數: %.2f\n", average);
		printf("該同學的成績等級: 丁等\n");
		break;
		
		}
	}
}
