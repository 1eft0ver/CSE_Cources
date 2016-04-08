/*
Author：蔡宜勳 B033040009
Date：Nov. 9, 2015
Purpose:西洋棋騎士(knight)走完棋盤的順序，使用Recursive實作 
*/

#include<iostream>
using namespace std;
int chessboard[6][6];

int march(int n, int step, int row, int col){        //騎士行走的Function，假若能走完棋盤則傳回1，否則傳回0 
	int i;
	int r_next, c_next;    
    
    int const d_row[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };  //八個方向(K1~K8) i的差值 
    int const d_col[8] = { -2, -1, 1, 2, 2, 1,  -1,  -2 };  //八個方向(K1~K8) j的差值
    
    if(step > n * n) //假若走完所有格子了，return 1 
    return 1;
    
    for(int i = 0 ; i < 8 ; ++i){
    	r_next = row + d_row[i];
    	c_next = col + d_col[i];
    	
    	if(0 > r_next || r_next >= n ||
	       0 > c_next || c_next >= n || 
		   chessboard[r_next][c_next] != 0) //若下一步無法行走(走過了或是超出棋盤)，則繼續嘗試下一個方向 
		   continue; 
		   
		chessboard[r_next][c_next] = step; //將當前步數填入棋盤格子 
		
		if (march(n, step+1, r_next, c_next))
		return 1;
		
		chessboard[r_next][c_next] = 0;
    }
    return 0; //走不完所有格子，因此return 0 
}

int main()
{
    int n;
    while(cin >> n){
    	for(int a = 0 ; a < 6 ; ++a)					 //初始化二微陣列 
    		for(int b = 0 ; b < 6 ; ++b)
    		chessboard[a][b] = 0;
        chessboard[0][0] = 1;	
		int x = 0, y = 0;                         //x, y為現在走到的格子座標，由左上角開始行走故初值為0
		int now_step = 2;	                      //現在走到的是第幾步，由於第一步固定為左上角，因此now_step之初始值必然為2 
		
		if(march(n, now_step, x, y)){			  //走完棋盤，輸出結果 
			for(int j = 0; j < n; j++)
            {
                for(int i = 0; i < n; i++)
                    printf("%2d ", chessboard[i][j]);
                printf("\n");
            }
		}
		
		else{
		cout << "No solution" << endl;			  //走不完，無解 
		}
    }
}
