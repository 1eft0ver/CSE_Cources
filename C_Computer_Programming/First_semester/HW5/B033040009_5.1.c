#include<stdio.h>
#include<stdlib.h>


int main(){
	int a, b, c, temp;
	while(1){
		scanf("%d%d%d", &a, &b, &c);

		if(a > b){
		temp = b;
		b = a;
		a = temp;
		}
		
		if(b > c){
		temp = c;
		c = b;
		b = temp;
		}
		
		if (a + b <= c)
		printf("%d %d %d ���i�H�c���T����\n", a, b, c);
		
		else{
			printf("%d %d %d �i�H�c���T����\n", a, b, c);
			
			if(a * a + b * b == c * c)
			if(a == b){
			printf("%d %d %d �c���������y�����T����\n", a, b, c);
			continue;
			}
			else{
			printf("%d %d %d �c�����������T����\n", a, b, c);
			continue;
			}
			
			if(a == b || b == c)
			if(a == b && b == c){
			printf("%d %d %d �c���������T����\n", a, b, c);
			continue;
			}
			else{
			printf("%d %d %d �c���������y�T����\n", a, b, c);
			continue;
			}
			printf("%d %d %d �c�������@��T����\n", a, b, c);
			
		}
	}
}
