/*
Author�G���y�� B033040009
Date�GNov. 9, 2015
Purpose:��v���M�h(knight)�����ѽL�����ǡA�ϥ�Recursive��@ 
*/

#include<iostream>
using namespace std;
int chessboard[6][6];

int march(int n, int step, int row, int col){        //�M�h�樫��Function�A���Y�ਫ���ѽL�h�Ǧ^1�A�_�h�Ǧ^0 
	int i;
	int r_next, c_next;    
    
    int const d_row[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };  //�K�Ӥ�V(K1~K8) i���t�� 
    int const d_col[8] = { -2, -1, 1, 2, 2, 1,  -1,  -2 };  //�K�Ӥ�V(K1~K8) j���t��
    
    if(step > n * n) //���Y�����Ҧ���l�F�Areturn 1 
    return 1;
    
    for(int i = 0 ; i < 8 ; ++i){
    	r_next = row + d_row[i];
    	c_next = col + d_col[i];
    	
    	if(0 > r_next || r_next >= n ||
	       0 > c_next || c_next >= n || 
		   chessboard[r_next][c_next] != 0) //�Y�U�@�B�L�k�樫(���L�F�άO�W�X�ѽL)�A�h�~����դU�@�Ӥ�V 
		   continue; 
		   
		chessboard[r_next][c_next] = step; //�N��e�B�ƶ�J�ѽL��l 
		
		if (march(n, step+1, r_next, c_next))
		return 1;
		
		chessboard[r_next][c_next] = 0;
    }
    return 0; //�������Ҧ���l�A�]��return 0 
}

int main()
{
    int n;
    while(cin >> n){
    	for(int a = 0 ; a < 6 ; ++a)					 //��l�ƤG�L�}�C 
    		for(int b = 0 ; b < 6 ; ++b)
    		chessboard[a][b] = 0;
        chessboard[0][0] = 1;	
		int x = 0, y = 0;                         //x, y���{�b���쪺��l�y�СA�ѥ��W���}�l�樫�G��Ȭ�0
		int now_step = 2;	                      //�{�b���쪺�O�ĴX�B�A�ѩ�Ĥ@�B�T�w�����W���A�]��now_step����l�ȥ��M��2 
		
		if(march(n, now_step, x, y)){			  //�����ѽL�A��X���G 
			for(int j = 0; j < n; j++)
            {
                for(int i = 0; i < n; i++)
                    printf("%2d ", chessboard[i][j]);
                printf("\n");
            }
		}
		
		else{
		cout << "No solution" << endl;			  //�������A�L�� 
		}
    }
}
