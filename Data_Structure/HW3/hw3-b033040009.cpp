/*
Author：蔡宜勳 B033040009
Date：Nov. 2, 2015
Purpose:西洋棋騎士(knight)走完棋盤的順序
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct Node{		//使用Structure撰寫Stack 
	struct Node *prev;		//指向前一個Node的pointer 
	struct Node *next;		//指向後一個Node的pointer 
	int _x;					//於棋盤上的x座標值 (j) 
	int _y;					//於棋盤上的y座標值 (i) 
	int _k;					//移動方向 (k1~k8) 
	int _now_step;			//紀錄現在為第幾步 
}Node;

void Push(Node** first,int x,int y,int k,int now_step){		//Stack的Push操作 
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp -> _x = x;
	tmp -> _y = y;
	tmp -> _k = k;
	tmp -> _now_step = now_step;
	tmp -> prev = NULL;
	tmp -> next = NULL;
	if((*first) == NULL)
		(*first) = tmp;
	else{
		Node *last = (*first);
		while(last -> next != NULL)
			last = last -> next;
		tmp -> prev = last;
		last -> next = tmp;
	}
}

int Pop(Node** first){										//Stack的Pop操作，Pop出k 
	if((*first) == NULL)
		return 0;
	else{
		Node *top = (*first);
		while( top -> next != NULL)
			top = top -> next;
		if(top == (*first))
			*first = NULL;
		else
			top -> prev -> next =NULL;
		free(top);
		return top->_k;
	}
}


int main(){

    int n; 
    while(cin >> n)				
    {	
    	n--;					//由於陣列索引是由0開始，因此必須將輸入之n值先減一再做處理 
    	Node *top = NULL;		//Stack 
		int sol = 1;			//用以判斷是否有解的變數 
		int now_step = 2, all_step = (n + 1) * (n + 1);	 //now_step為現在步數(因為左上角為起點，因此第一步之now_step值必然為2)， all_step為邊長n的棋盤總最多可以走幾步 
    	int x = 0, y = 0;								 //現在的x, y座標 
    	int chessboard[6][6];							 //用以代表棋盤的二維陣列，依題目規定上限設為6 
    	for(int a = 0 ; a < 6 ; ++a)					 //初始化二微陣列 
    		for(int b = 0 ; b < 6 ; ++b)
    		chessboard[a][b] = 0;
        chessboard[0][0] = 1;							 //將左上角設為起點 
        for(int k = 1 ; now_step <= all_step ; k++)		
        {
            if(sol == 0)								 //假若無解，跳出迴圈 
                break;
			
            if( k == 1 && chessboard[x+1][y-2] == 0 && x + 1 <= n && y-2 >= 0)		//針對各方向行走的情況做處理，以及判斷是否會走出棋盤 
            {
                Push(&top, x, y, k, now_step);
                chessboard[x+1][y-2] = now_step;
                now_step++;
                x = x + 1;
                y = y - 2;
                k = 0;
            }
            else if(k == 2 && chessboard[x+2][y-1] == 0 && x + 2 <= n && y - 1 >= 0)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x+2][y-1] = now_step;
                now_step++;
                x = x + 2;
                y = y - 1;
                k = 0;
            }
            else if(k == 3 && chessboard[x+2][y+1] == 0 && x + 2 <= n && y + 1 <= n)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x+2][y+1] = now_step;
                now_step++;
                x = x + 2;
                y = y + 1;
                k = 0;
            }
            else if(k == 4 && chessboard[x+1][y+2] == 0 && x + 1 <= n && y + 2 <= n)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x+1][y+2] = now_step;
                now_step++;
                x = x + 1;
                y = y + 2;
                k = 0;
            }
            else if(k == 5 && chessboard[x-1][y+2] == 0 && x-1 >= 0 && y + 2 <= n)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x-1][y+2] = now_step;
                now_step++;
                x = x - 1;
                y = y + 2;
                k = 0;
            }
            else if(k == 6 && chessboard[x-2][y+1] == 0 && x-2 >= 0 && y +1 <= n)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x-2][y+1] = now_step;
                now_step++;
                x = x - 2;
                y = y + 1;
                k = 0;
            }
            else if(k == 7 && chessboard[x-2][y-1] == 0 && x - 2 >= 0 && y - 1 >= 0)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x-2][y-1] = now_step;
                now_step++;
                x = x - 2;
                y = y - 1;
                k = 0;
            }
            else if(k == 8 && chessboard[x-1][y-2] == 0 && x - 1 >= 0 && y - 2 >= 0)
            {
                Push(&top, x, y, k, now_step);
                chessboard[x-1][y-2] = now_step;
                now_step++;
                x = x - 1;
                y = y - 2;
                k = 0;
            }
            else if(k>=9)					//代表無路可走，八個方向都走過了，因此pop回上一步再做嘗試 
            {
            	now_step--;
                int top_k = 1;                
                top_k = Pop(&top);
                chessboard[x][y] = 0;
                if(top_k == 0)
                    sol = 0;
                else
                    k = top_k;
                if(k == 1)
                {
                    x -= 1;
                    y += 2;
                }
                else if(k == 2)
                {
                    x -= 2;
                    y += 1;
                }
                else if(k == 3)
                {
                    x -= 2;
                    y -= 1;
                }
                else if(k == 4)
                {
                    x -= 1;
                    y -= 2;
                }
                else if(k == 5)
                {
                    x += 1;
                    y -= 2;
                }
                else if(k == 6)
                {
                    x += 2;
                    y -= 1;
                }
                else if(k == 7)
                {
                    x += 2;
                    y += 1;
                }
                else if(k == 8)
                {
                    x += 1;
                    y += 2;
                }
            }
            else if(now_step > all_step)			//走完所有格子的情況，離開迴圈 
                break;
        }
        if(sol == 0)								//無解 
            printf("No solution.\n");
            
        else if(now_step > all_step)				// 走完所有格子了，故有解，輸出解 
            for(int j = 0; j < n + 1; j++)
            {
                for(int i = 0; i < n + 1; i++)
                    printf("%2d ", chessboard[i][j]);
                printf("\n");
            }
        sol=1;
            for(int j = 0; j < n + 1; j++)
            {
                for(int i = 0; i < n + 1; i++)
                    chessboard[i][j] = 0;
            }
    }
    
}
