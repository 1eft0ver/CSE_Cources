#include<stdio.h>
#include<math.h>

int isprime(int);

int main(){
	 int n;
	 while(printf("Input:") && scanf("%d", &n)){
	 		 	
	 	if(isprime(n) == 0){
	 		printf("%d=", n);
	 	     int i;
	 	     for(i = 2 ; i <= n ; ++i){
	 	          while(n % i == 0){
	 	          printf("%d",i);
	 	          n /= i;
	 	               if(n == 1)
	 	               printf("\n");
	 	               else
	 	               printf("*");
	 	          }
	 	     }
	 	}
	 	else
	 	printf("%d=%d", n , n);
	 	printf("\n");
	 }
}

int isprime(int n){
	int i;
	for(i = 2 ; i <= sqrt(n) ; ++i){
     	if (n % i == 0){
     	return 0;
     	break;
     	}
     	
     	if(i == sqrt(n) && n % i != 0)
     	return 1;    	
	}
}
