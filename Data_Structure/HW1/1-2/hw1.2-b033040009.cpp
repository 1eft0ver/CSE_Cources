/*
Author�G���y�� B033040009 
Date�GOct. 5, 2015
Purpose�G�L�X1��N�����Ҧ���Ƥ����� (factorial)�AN<=50
*/ 

#include <iostream>

using namespace std;

int main(){	
	int n; 											 
	while(cin >> n){
		if(n == 0)									 //�Y��J��0�A�����{�� 
		break;
		
		int fac[100];								 //�H�@�W��fac���}�C�i�涥�����j�ƭ��k�A������W�L�D�س]�w�����ո�ƤW��50!�����Size 
		for(int i = 0 ; i < 100 ; ++i)               //��l�ư}�C 
		fac[i] = 0;
		fac[0] = 1;									 //��l�ȥ�����1 
		
		
		for(int x = 1 ; x <= n ; ++x){               //��1���}�l����n������ 
			for(int y = 0 ; y < 100 ; ++y)			 //�q�Ӧ�ƶ}�l�A�C�Ӧ�Ƴ����W�{�b��x�� 
				fac[y] = fac[y] * x;
				
			for(int z = 0 ; z < 100 ; ++z){			 //�i��i��B�z 
				int buf;							 //buf�ΨӦs��i�쪺�ƭ� 
				if(fac[z] >= 10){
					buf = fac[z] / 10;
					fac[z] = fac[z] % 10;
					fac[z + 1] = fac[z + 1] + buf;
				}
			}
		cout << x << "!=";
		int zero_check = 99;						 //zero_check�۰}�C���ݩ��e����A����Ĥ@�ӫD0���ƭȮɡA�Y�N��Ӧ�m����X��l�I 
			while(fac[zero_check] == 0)
			--zero_check;
			
			for(int pos = zero_check ; pos >= 0 ; --pos)	//��X�X�ƭ� 
			cout << fac[pos];
			cout << endl;
		}
	cout << endl;											//���P���ꤧ�������� 
	}
} 
