#include<stdio.h>
#include<math.h>

int determine_condition(int, int);
void swap(int* , int* );
int is_prime(int);

int main(){
	int m, n;
	while(scanf("%d%d", &m, &n)){
		FILE *output;
		output = fopen("output2.txt","w");
			if(determine_condition(m,n) == 0){
			printf("輸入不符合規範(屬於大於4的偶數)，請重新輸入\n");
			continue;
			}
			
			if(m > n)
			swap(&m,&n);
			
			int i;
			for(i = m ; i <= n ; i = i + 2){
				int j;
				for(j = 2 ; j <= i ; ++j){
					if(is_prime(j) && is_prime(i - j)){
					fprintf(output,"%d=%d+%d\n",i,j,i-j);
					break;
					}
				}
			}
		fclose(output);
	}
}

int determine_condition(int m, int n){
	if(m % 2 == 0 && n % 2 == 0 && m > 4 && n > 4)
	return 1;
	else
	return 0;
}

void swap(int* m, int* n){
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
}

int is_prime(int n){
	int i;
	for(i = 2 ; i < n / 2 + 1; ++i){
		if(n % i == 0){
		return 0;
		break;
		}
		if(n == n / 2)
		return 1;
	}
}
