#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

int main(){
	while(1){
	
	int a, b, c, d, e; //五個係數 
	int xrb, xru , xrr; //X的範圍 
	int x;
	double rm, fm; //實際及逼近法斜率 
	printf("輸入係數:");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("輸入x範圍:");
	scanf("%d%d", &xrb, &xru);
	xrr = xru - xrb;
	printf("輸入所求X值:");
	scanf("%d", &x);
	rm =  a * -sin(b*M_PI*x/30) * (b*M_PI/30) + c * cos(d*M_PI*x/30) * (d*M_PI/30) + e; //根據微分定義計算實際切線斜率 
	printf("實際切線斜率:%.6lf\n", rm);
	fm = ((a * cos(b*M_PI*(x+1)/30) + c * sin(d*M_PI*(x+1)/30) + e) - (a * cos(b*M_PI*x/30) + c * sin(d*M_PI*x/30) + e)) / 1;
	printf("逼近法切線斜率:%.6lf\n", fm);
	
	
	
	//開始畫圖
	printf("   -35  -30  -25  -20  -15  -10  -5    0    5    10   15   20   25   30   35\n");
	char y[80]; //y軸
	
	//計算x的範圍下限的位數
	int xrb_n = 1; //xrb_n = x範圍下限的位數 
	int t = xrb;
	while(t != 0){
	t /= 10;
	++xrb_n; 
	} 
	
	
	//先將y軸變成由-及+組成的樣子 
	int i;
	for (i = 0 ; i < 80; ++i){		
		if((i + 1) % 5 == 0)      
		y[i] = '+';
		else
		y[i] = '-';		
	}
	//處理x的範圍下限表示在y軸上的情況，以及y軸最右方的'Y'
	char xrb_s[80];
	sprintf(xrb_s, "%d", xrb);
	int j;
	for(j = 0 ; j < xrb_n; ++j)
	y[39+j] = xrb_s[j];
	y[79] = 'Y';
	
	//輸出y軸 
	int k;
	for(k = 0; k < 80; ++k)
	printf("%c",y[k]);
	
	int l, m;
	char ta; //切線的圖形種類 
	if(rm > 0)
	ta = '\\';
	if(rm < 0)
	ta = '/';
	if(rm == 0)
	ta = '|';
	
	for(l = xrb+1 ; l <= xru; ++l ){
		if(l >= x - 5 && l <= x + 5){ //處理位於x正負5範圍內的圖形(因為需要處理切線及P點) 
		
			if(l == x){
				int x_t, xn=1, y_t , yn=1 , y;
				y = roundf(a * cos(b*M_PI*x/30) + c * sin(d*M_PI*x/30) + e);
					x_t = x;
					while(x_t !=0){
					x_t /= 10;
					++xn;
					}
				
					y_t = y;
					while(y_t !=0){
					y_t /= 10;
					++yn;
					}
				int plong = 7 + xn + yn; // 輸出P的座標所需要的長度 
				
				for(m = -39; m <=40; ++m){
					if(m == 0){
				
						if(l % 5 != 0)
						printf("|");
			
						else{
						printf("%d",l);
			
							//處理輸出5的倍數時x軸錯位的問題
							int temp = l, lx=1;
							while(temp != 0){
							temp/=10;
							++lx;
							}				
						m += lx -2;  
						}
					}
			
					else{
						//輸出P點座標 避免換行發生 
						if((m >= -39 && m < -20) || (m >= 0 && m < 20)){						
							if( m+plong -2 == y){
							printf("( %d, %d ) P", x , y);
							m += plong -2; 
							}	
							else
							printf(" ");
						}
						
						else{						
							if( m  == y -1){
							printf("P ( %d, %d )", x , y);
							m += plong -1;
							}
							
							else
							printf(" ");
						}
				
					}
				} 
			}
			
			else{
			
				for(m = -39; m <= 40; ++m){
					if(m == 0){
				
						if(l % 5 != 0)
						printf("|");
			
						else{
						printf("%d",l);
			
							//處理輸出5的倍數時x軸錯位的問題
							int temp = l, lx=1;
							while(temp != 0){
							temp/=10;
							++lx;
							}				
						m += lx -2;  
						}
					}
			
					else{						
						float func = a * cos(b*M_PI*l/30) + c * sin(d*M_PI*l/30) + e;
						
						if( m+1 == roundf(func))
						printf("*");
						
						else
						printf(" ");
				
					}
				} 
			
			}
		}
		
		else{
			
			for(m = -39; m <= 40; ++m){	
			
				if(m == 0){
				
					if(l % 5 != 0)
					printf("|");
			
					else{
					printf("%d",l);			
						//處理輸出5的倍數時x軸錯位的問題
						int temp1 = l, lx1=1;
						while(temp1 != 0){
						temp1/=10;
						++lx1;
						}				
						m += lx1 -2;  
					}
				}
			
				else{
					float func1 = a * cos(b*M_PI*l/30) + c * sin(d*M_PI*l/30) + e;
					
					if( m+1 == (int)func1)
					printf("*");
					
					else
					printf(" ");
				}
			}
		
		}
	
	}
	
	}
} 
