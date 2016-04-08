#include<stdio.h>
#include<stdlib.h>

int main(){
	int n1, n2, n3, n4;
	scanf("%d%d%d%d",&n1, &n2, &n3, &n4);
	
	printf("Num1: %d\n",n1);
	printf("Num2: %d\n",n2);
	printf("Num3: %d\n",n3);
	printf("Num4: %d\n",n4);
		
	printf("%d + %d - %d * %d = %d\n", n1, n2, n3, n4, n1+n2-n3*n4);
	printf("%d + %d * %d - %d = %d\n", n1, n2, n3, n4, n1+n2*n3-n4);
	printf("%d - %d + %d * %d = %d\n", n1, n2, n3, n4, n1-n2+n3*n4);
	printf("%d - %d * %d + %d = %d\n", n1, n2, n3, n4, n1-n2*n3+n4);
	printf("%d * %d + %d - %d = %d\n", n1, n2, n3, n4, n1*n2+n3-n4);
	printf("%d * %d - %d + %d = %d\n", n1, n2, n3, n4, n1*n2-n3+n4);
	
	system("PAUSE");
}
