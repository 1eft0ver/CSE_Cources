/*
Author�G���y�� B033040009 
Date�GOct. 4, 2015
Purpose�G�s�@N��(N���_��)���]��}(magic square) 
*/ 

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n; 													//n���]��} 
	while(cin >> n){ 
		int matrix[9][9];              						//�g�J�]��}���G���}�C�A�]���D�ح��w�W����9���]��}�A�]��size�]�w��9 
		int start_point = n / 2;							//matrix[0][start_point]�Y���]��}��1����m 
		
		for(int x = 0 ; x < 9 ; ++x)
		for(int y = 0 ; y < 9 ; ++y)
		matrix[x][y] = 0;              						//��l�ư}�C���Ҧ�������0 
			
			int now_row = 0;								//now_row : �{�b���ӱN�ƭȶ�J����m��row 
			int now_column = start_point;					//now_column : �{�b���ӱN�ƭȶ�J����m��column
			for(int i = 1 ; i <= n * n ; ++i){
				matrix[now_row][now_column] = i;
				int ori_row = now_row;						//ori_row : �����W�@�Ӷ�J�ƭȪ���m��row 
				int ori_column = now_column;				//ori_column :  �����W�@�Ӷ�J�ƭȪ���m��column
				now_row--;
				now_column--;
					
					if(now_row < 0)							 //�̷��]��}���W��ø�s�]��} 
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
			
			for(int x = 0 ; x < n ; ++x){    				//��X�]��} 
			for(int y = 0 ; y < n ; ++y){
			cout << setw(2);                               	//�榡�ƿ�X 
			cout << matrix[x][y] << " ";
			}
			cout << endl;									//���� 
			}
	}
}
