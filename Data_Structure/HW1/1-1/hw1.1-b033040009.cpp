/*
Author：蔡宜勳 B033040009 
Date：Oct. 4, 2015
Purpose：製作N階(N為奇數)的魔方陣(magic square) 
*/ 

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n; 													//n階魔方陣 
	while(cin >> n){ 
		int matrix[9][9];              						//寫入魔方陣的二維陣列，因為題目限定上限為9階魔方陣，因此size設定為9 
		int start_point = n / 2;							//matrix[0][start_point]即為魔方陣中1的位置 
		
		for(int x = 0 ; x < 9 ; ++x)
		for(int y = 0 ; y < 9 ; ++y)
		matrix[x][y] = 0;              						//初始化陣列內所有元素為0 
			
			int now_row = 0;								//now_row : 現在應該將數值填入的位置的row 
			int now_column = start_point;					//now_column : 現在應該將數值填入的位置的column
			for(int i = 1 ; i <= n * n ; ++i){
				matrix[now_row][now_column] = i;
				int ori_row = now_row;						//ori_row : 紀錄上一個填入數值的位置的row 
				int ori_column = now_column;				//ori_column :  紀錄上一個填入數值的位置的column
				now_row--;
				now_column--;
					
					if(now_row < 0)							 //依照魔方陣的規律繪製魔方陣 
					now_row = n - 1;
					
					if(now_column < 0)
					now_column = n - 1;
					
					if(matrix[now_row][now_column] != 0){
						now_row = ori_row + 1;
						now_column = ori_column;
						
						if(now_row == n)
						now_row == 0;
					}
			}
			
			for(int x = 0 ; x < n ; ++x){    				//輸出魔方陣 
			for(int y = 0 ; y < n ; ++y){
			cout << setw(2);                               	//格式化輸出 
			cout << matrix[x][y] << " ";
			}
			cout << endl;									//換行 
			}
	}
}
