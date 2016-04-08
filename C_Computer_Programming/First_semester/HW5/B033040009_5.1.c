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
		printf("%d %d %d 不可以構成三角形\n", a, b, c);
		
		else{
			printf("%d %d %d 可以構成三角形\n", a, b, c);
			
			if(a * a + b * b == c * c)
			if(a == b){
			printf("%d %d %d 構成的為等腰直角三角形\n", a, b, c);
			continue;
			}
			else{
			printf("%d %d %d 構成的為直角三角形\n", a, b, c);
			continue;
			}
			
			if(a == b || b == c)
			if(a == b && b == c){
			printf("%d %d %d 構成的為正三角形\n", a, b, c);
			continue;
			}
			else{
			printf("%d %d %d 構成的為等腰三角形\n", a, b, c);
			continue;
			}
			printf("%d %d %d 構成的為一般三角形\n", a, b, c);
			
		}
	}
}
