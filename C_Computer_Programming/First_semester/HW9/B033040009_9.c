#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	
	FILE *cfptr1;
	FILE *cfptr2;
	int num;
	srand(1);
	cfptr1 = fopen("input1.txt","w");			
		int i;
		for(i=1; i<=1000; ++i){
        	num=(rand() % 52);
       	 		if(num>=26)	//�B�z�p�g0->a 1->b    
       	 		fprintf(cfptr1, "%c", 97 + num - 26);   
        		else      	//�B�z�j�g 26->A 27->B 
				fprintf(cfptr1, "%c", 65 + num );  
        }
    fclose(cfptr1);
    
    
    	
    char c; //�n�M�䪺�r�� 
    	while(1){
    		cfptr1 = fopen("input1.txt","r");
    		printf("�п�J�n�M�䪺�r��:");
    		c = getchar();
    		char t; 
    		t = getchar(); //Ū������r�� 
    		
    		
			if(c == '*'){
			printf("�����M��C\n");
			break;
			}
			
			else if( (c >=65 && c <= 90) || (c >= 97 && c <=122)){
				int count = 0;
				int i;
				char ct;
				
				for(i = 1 ; i <= 1000 ; ++i){
					fscanf(cfptr1,"%c", &ct);
					if(ct == c || ct + 32 == c || ct -32 == c)
					++count;
				}
				printf("�r��'%c'�@�@��� %d��\n", c , count);
			}
			
			else {
			printf("��J���~�A�A�դ@���C\n");
			continue;
			}
			fclose(cfptr1);
		} 
		
		
		while(1){
			int changeline;		
     
			printf("�C�檺�r����:");
			scanf("%d", &changeline);			
			char t; 
    		t = getchar(); //Ū������r�� 	
			
			if(changeline == -1){
			printf("�����ק�\n");
			break;
			}	
			
			else if (changeline <= 0){
			printf("��J���~�A�A�դ@���C\n");
			continue;
			}
					
			else{			
			int j;		
			cfptr1 = fopen("input1.txt", "r");
			cfptr2 = fopen("output2.txt", "w");
				for(j = 1 ; j <= 1000 ; ++j){
				char ccl;
				fscanf(cfptr1,"%c", &ccl);
				printf("%c",ccl);
				fprintf(cfptr2, "%c" ,ccl);
					if(j % changeline == 0){
					printf("\n");
					fprintf(cfptr2, "\n");
					}
				}
				fclose(cfptr1);
				fclose(cfptr2);
				
			printf("��粒���C\n");
			}
			
			
			
		}
} 
