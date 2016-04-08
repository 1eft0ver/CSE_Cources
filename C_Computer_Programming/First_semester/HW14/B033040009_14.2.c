#include<stdio.h>
#include<string.h>
int main(){
	while(1){
	char ask[100];
	printf("輸入姓名或生日月分 : ");
	scanf("%s",ask);
		FILE *input;
		input = fopen("Input2.txt","r");
			char namestr[100], birthdaystr[100];
			char name[10000][100];
			char birthday[10000][100];
			int month[10000];
			int no = 0;
			
			while(fscanf(input,"%s %s",namestr,birthdaystr) != EOF){
				int y,m,d;
				strcpy(name[no], namestr);
				strcpy(birthday[no], birthdaystr);
				sscanf(birthdaystr,"%d/%d/%d", &y,&m,&d);
				month[no] = m;
				++no;
			}
			
		if(ask[0] >= 49 && ask[0] <= 57){  //輸入為月份 
			int m;
			sscanf(ask,"%d",&m);
				int i;
				for(i = 0; i <= no ; ++i){
					if(month[i] == m)
					printf("%s %s\n", name[i],birthday[i]);
				}
		}
		
		else{  //輸入為名字 
			int i;
			for(i = 0 ; i <= no ; ++i){
				if(strcmp(ask,name[i])==0)
				printf("%s %s\n", name[i],birthday[i]);
			}
		}
		
		fclose(input);
	}
}
