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
       	 		if(num>=26)	//處理小寫0->a 1->b    
       	 		fprintf(cfptr1, "%c", 97 + num - 26);   
        		else      	//處理大寫 26->A 27->B 
				fprintf(cfptr1, "%c", 65 + num );  
        }
    fclose(cfptr1);
    
    
    	
    char c; //要尋找的字元 
    	while(1){
    		cfptr1 = fopen("input1.txt","r");
    		printf("請輸入要尋找的字元:");
    		c = getchar();
    		char t; 
    		t = getchar(); //讀取換行字元 
    		
    		
			if(c == '*'){
			printf("結束尋找。\n");
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
				printf("字元'%c'一共找到 %d個\n", c , count);
			}
			
			else {
			printf("輸入錯誤，再試一次。\n");
			continue;
			}
			fclose(cfptr1);
		} 
		
		
		while(1){
			int changeline;		
     
			printf("每行的字元數:");
			scanf("%d", &changeline);			
			char t; 
    		t = getchar(); //讀取換行字元 	
			
			if(changeline == -1){
			printf("結束修改\n");
			break;
			}	
			
			else if (changeline <= 0){
			printf("輸入錯誤，再試一次。\n");
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
				
			printf("更改完成。\n");
			}
			
			
			
		}
} 
