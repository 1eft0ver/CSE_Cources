#include<stdio.h>

int check_range (int);
int draw_parallelogram(int);
int draw_diamond(int);

int main(){
	int n;
	while(printf("Please input the number N: ") && scanf("%d", &n)){
		
	if(check_range(n) == 0){
	printf("The number N is out of range. Please input again!!\n");
	continue;
	}
	
	if(check_range(n) == 1){
		printf("\n");
		draw_parallelogram(n);
		printf("\n");
		draw_diamond(n);
	}
	
	}
}

int check_range(int n){
	if(n > 26 || n < 1)
	return 0;
	else
	return 1;
}

int draw_parallelogram(int n){
	int i;
	int m;
	for (i = 1 ; i <= n; ++i){
		for(m = 0 ; m < i - 1 ; ++m)
		printf(" ");
		
		for(m = 0 ; m < n ; ++m)
		printf("%c ", 65 + m);
		
		for (m = n - 2 ; m >= 0 ; --m)
		printf("%c ", 65 + m);
		
		printf("\n");
	}
}

int draw_diamond(int n){
	int i;
	int m;
	for(i = 1 ; i <= n ; ++i){
		for(m = (n - i) * 2 ; m > 0 ; --m)
		printf(" ");
		
		for (m = 0 ; m <= i - 1 ; ++m)
		printf("%c ", 65 + m);
		
		for (m = i - 2 ; m >= 0 ; --m)
		printf("%c ", 65 + m);
		
		printf("\n");
	}
	
	for(i = n - 1 ; i > 0 ; -- i){
				for(m = (n - i) * 2 ; m > 0 ; --m)
		printf(" ");
		
		for (m = 0 ; m <= i - 1 ; ++m)
		printf("%c ", 65 + m);
		
		for (m = i - 2 ; m >= 0 ; --m)
		printf("%c ", 65 + m);
		
		printf("\n");
	}
}