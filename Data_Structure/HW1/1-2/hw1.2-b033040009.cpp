/*
Author：蔡宜勳 B033040009 
Date：Oct. 5, 2015
Purpose：印出1到N之間所有整數之階乘 (factorial)，N<=50
*/ 

#include <iostream>

using namespace std;

int main(){	
	int n; 											 
	while(cin >> n){
		if(n == 0)									 //若輸入為0，結束程式 
		break;
		
		int fac[100];								 //以一名為fac的陣列進行階乘的大數乘法，給予其超過題目設定之測試資料上限50!的位數Size 
		for(int i = 0 ; i < 100 ; ++i)               //初始化陣列 
		fac[i] = 0;
		fac[0] = 1;									 //初始值必須為1 
		
		
		for(int x = 1 ; x <= n ; ++x){               //自1階開始乘到n階為止 
			for(int y = 0 ; y < 100 ; ++y)			 //從個位數開始，每個位數都乘上現在的x值 
				fac[y] = fac[y] * x;
				
			for(int z = 0 ; z < 100 ; ++z){			 //進行進位處理 
				int buf;							 //buf用來存放進位的數值 
				if(fac[z] >= 10){
					buf = fac[z] / 10;
					fac[z] = fac[z] % 10;
					fac[z + 1] = fac[z + 1] + buf;
				}
			}
		cout << x << "!=";
		int zero_check = 99;						 //zero_check自陣列尾端往前巡行，當找到第一個非0的數值時，即代表該位置為輸出初始點 
			while(fac[zero_check] == 0)
			--zero_check;
			
			for(int pos = zero_check ; pos >= 0 ; --pos)	//輸出出數值 
			cout << fac[pos];
			cout << endl;
		}
	cout << endl;											//不同測資之間的換行 
	}
} 
