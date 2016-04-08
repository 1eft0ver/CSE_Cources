#include<stdio.h>

int main(){
	FILE *cfptr1, *cfptr2, *output;
	while(1){
		int m;
		scanf("%d",&m);
		if(m > 30 || m < 0){
		printf("M is out of range!(1¡ØM¡Ø30)\n");
		continue;
		}
		
		cfptr1 = fopen("input1.txt","w");
		cfptr2 = fopen("input2.txt","w");
		
		int i;
		srand(1);
			for(i = 0 ; i < m ; ++i){		
			int ran = rand();
			fprintf(cfptr1 ,"%d ",ran);
			}
		fclose(cfptr1);
		
		srand(2);
			for(i = 0 ; i < m ; ++i){		
			int ran = rand();
			fprintf(cfptr2 ,"%d ", ran);
			}
		fclose(cfptr2);
		
		cfptr1 = fopen("input1.txt","r");
		cfptr2 = fopen("input2.txt","r");
		output = fopen("output1.txt","w");
		
		fprintf(output,"Random number¡G   Random number¡G   Result¡G \n");
		
		for(i = 0 ; i < m ; ++i){
		int n1, n2;
		fscanf(cfptr1,"%d", &n1);         
		fscanf(cfptr2,"%d", &n2);
		fprintf(output, "     %-18d%-14d%d\n",n1,n2,n1+n2);
		}
		fclose(cfptr1);
		fclose(cfptr2);
		fclose(output);
	}
}
