/*
HW7
資工系107級 蔡宜勳
B033040009 
*/

#include <stdio.h>

int isleap(int); //閏年判斷 

int main(){
	int date;
	int year, month, weekday;
	while(printf("Input: ") && scanf("%d", &date)){
		weekday = date % 10;
		date = (date - weekday) / 10;
		month = date % 100;
		date = (date - month) / 100;
		year = date;
		if(month > 12 || month < 1){
		printf("Month error\n");
		continue;
		}
			switch (month){
			
			case 1 :
			printf("                      January, %d\n",year);
			break;
			
			case 2 :
			printf("                     February, %d\n",year);
			break;
			
			case 3 :
			printf("                        March, %d\n",year);
			break;
			
			case 4 :
			printf("                        April, %d\n",year);
			break;
			
			case 5 :
			printf("                          May, %d\n",year);
			break;
			
			case 6:
			printf("                         June, %d\n",year);
			break;
			
			case 7 :
			printf("                         July, %d\n",year);
			break;
			
			case 8 :
			printf("                       August, %d\n",year);
			break;
			
			case 9 :
			printf("                    September, %d\n",year);
			break;
			
			case 10 :
			printf("                      October, %d\n",year);
			break;
			
			case 11 :
			printf("                     November, %d\n",year);
			break;
			
			case 12 :
			printf("                     December, %d\n",year);
			break;
			
			}
			
			printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");
			
			int days;  //當月天數判斷 
			if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
			days = 31;
			else{
				if(month == 2){
					if(isleap(year) == 1)
					days = 29;
					if(isleap(year) == 0)
					days = 28;
				}
				
				else
				days = 30;
			}
			
			int i;
			for(i = 0 ; i < weekday; ++i)
			printf("     ");
			int m;
			for(m = 1 ; m <= days; ++m){
				printf("  %3d", m);
				if((m + weekday) % 7 == 0) //每滿七天換一次行 
				printf("\n");
			}
			printf("\n");
	}
}

int isleap( int y){
	 if( (!(y % 4) && (y % 100)) || !(y % 400) )
	 return 1;
	 else
	 return 0;
}
