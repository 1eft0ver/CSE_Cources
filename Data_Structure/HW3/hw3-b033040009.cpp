/*
Author�G���y�� B033040009
Date�GNov. 2, 2015
Purpose:��v���M�h(knight)�����ѽL������
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct Node{		//�ϥ�Structure���gStack 
	struct Node *prev;		//���V�e�@��Node��pointer 
	struct Node *next;		//���V��@��Node��pointer 
	int _x;					//��ѽL�W��x�y�Э� (j) 
	int _y;					//��ѽL�W��y�y�Э� (i) 
	int _k;					//���ʤ�V (k1~k8) 
	int _now_step;			//�����{�b���ĴX�B 
}Node;

void Push(Node** first,int x,int y,int k,int now_step){		//Stack��Push�ާ@ 
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

int Pop(Node** first){										//Stack��Pop�ާ@�APop�Xk 
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
    	n--;					//�ѩ�}�C���ެO��0�}�l�A�]�������N��J��n�ȥ���@�A���B�z 
    	Node *top = NULL;		//Stack 
		int sol = 1;			//�ΥH�P�_�O�_���Ѫ��ܼ� 
		int now_step = 2, all_step = (n + 1) * (n + 1);	 //now_step���{�b�B��(�]�����W�����_�I�A�]���Ĥ@�B��now_step�ȥ��M��2)�A all_step�����n���ѽL�`�̦h�i�H���X�B 
    	int x = 0, y = 0;								 //�{�b��x, y�y�� 
    	int chessboard[6][6];							 //�ΥH�N��ѽL���G���}�C�A���D�سW�w�W���]��6 
    	for(int a = 0 ; a < 6 ; ++a)					 //��l�ƤG�L�}�C 
    		for(int b = 0 ; b < 6 ; ++b)
    		chessboard[a][b] = 0;
        chessboard[0][0] = 1;							 //�N���W���]���_�I 
        for(int k = 1 ; now_step <= all_step ; k++)		
        {
            if(sol == 0)								 //���Y�L�ѡA���X�j�� 
                break;
			
            if( k == 1 && chessboard[x+1][y-2] == 0 && x + 1 <= n && y-2 >= 0)		//�w��U��V�樫�����p���B�z�A�H�ΧP�_�O�_�|���X�ѽL 
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
            else if(k>=9)					//�N��L���i���A�K�Ӥ�V�����L�F�A�]��pop�^�W�@�B�A������ 
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
            else if(now_step > all_step)			//�����Ҧ���l�����p�A���}�j�� 
                break;
        }
        if(sol == 0)								//�L�� 
            printf("No solution.\n");
            
        else if(now_step > all_step)				// �����Ҧ���l�F�A�G���ѡA��X�� 
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
