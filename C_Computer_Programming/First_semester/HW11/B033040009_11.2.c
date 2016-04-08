#include<stdio.h>
void determine_date(int* , int* , int*);
int of_the_week(int , int , int );

int main(){
	int date;
	while(scanf("%d", &date)){
		int yy, mm, dd;
		yy = date / 10000;
		date -= yy * 10000;
		mm = date / 100;
		date -= mm * 100;
		dd = date;
		determine_date(&yy, &mm, &dd);
			if(of_the_week(yy, mm, dd) == 0)
			printf("Sunday\n");
			if(of_the_week(yy, mm, dd) == 1)
			printf("Monday\n");
			if(of_the_week(yy, mm, dd) == 2)
			printf("Tuesday\n");
			if(of_the_week(yy, mm, dd) == 3)
			printf("Wednesday\n");
			if(of_the_week(yy, mm, dd) == 4)
			printf("Thursday\n");
			if(of_the_week(yy, mm, dd) == 5)
			printf("Friday\n");
			if(of_the_week(yy, mm, dd) == 6)
			printf("Saturday\n");
			
	}	
} 

void determine_date(int* yy, int* mm, int* dd){
		
	if(*yy != 2012)
	*yy = 2012;
	
	while(*mm < 1 | *mm > 12){
	printf("月份輸入錯誤，請重新輸入\n");
	int temp;
	scanf("%d", &temp);
	*mm = temp;
	}	
	
	while(*dd < 1 || *dd > monthday[*mm]){
	printf("日期輸入錯誤，請重新輸入\n");
	int temp;
	scanf("%d", &temp);
	*dd = temp;
	}
	
}
int of_the_week(int yy, int mm, int dd){
	int year[367];
		int i;
		int firstday = 0;
	 	for(i = 1 ; i <= 366; ++i){    //推算出2012年第幾天為星期幾並存入陣列中 
			year[i] = firstday % 7;
			++firstday;
	 	}
	 	
	int monthday[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	int whatday = 0;
		for(i = 1 ; i < mm; ++i)
		whatday += monthday[i];
		whatday += dd;
		return year[whatday];
	
	 	
}
