#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

int main(){
	while(1){
	
	int a, b, c, d, e; //���ӫY�� 
	int xrb, xru , xrr; //X���d�� 
	int x;
	double rm, fm; //��ڤιG��k�ײv 
	printf("��J�Y��:");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("��Jx�d��:");
	scanf("%d%d", &xrb, &xru);
	xrr = xru - xrb;
	printf("��J�ҨDX��:");
	scanf("%d", &x);
	rm =  a * -sin(b*M_PI*x/30) * (b*M_PI/30) + c * cos(d*M_PI*x/30) * (d*M_PI/30) + e; //�ھڷL���w�q�p���ڤ��u�ײv 
	printf("��ڤ��u�ײv:%.6lf\n", rm);
	fm = ((a * cos(b*M_PI*(x+1)/30) + c * sin(d*M_PI*(x+1)/30) + e) - (a * cos(b*M_PI*x/30) + c * sin(d*M_PI*x/30) + e)) / 1;
	printf("�G��k���u�ײv:%.6lf\n", fm);
	
	
	
	//�}�l�e��
	printf("   -35  -30  -25  -20  -15  -10  -5    0    5    10   15   20   25   30   35\n");
	char y[80]; //y�b
	
	//�p��x���d��U�������
	int xrb_n = 1; //xrb_n = x�d��U������� 
	int t = xrb;
	while(t != 0){
	t /= 10;
	++xrb_n; 
	} 
	
	
	//���Ny�b�ܦ���-��+�զ����ˤl 
	int i;
	for (i = 0 ; i < 80; ++i){		
		if((i + 1) % 5 == 0)      
		y[i] = '+';
		else
		y[i] = '-';		
	}
	//�B�zx���d��U����ܦby�b�W�����p�A�H��y�b�̥k�誺'Y'
	char xrb_s[80];
	sprintf(xrb_s, "%d", xrb);
	int j;
	for(j = 0 ; j < xrb_n; ++j)
	y[39+j] = xrb_s[j];
	y[79] = 'Y';
	
	//��Xy�b 
	int k;
	for(k = 0; k < 80; ++k)
	printf("%c",y[k]);
	
	int l, m;
	char ta; //���u���ϧκ��� 
	if(rm > 0)
	ta = '\\';
	if(rm < 0)
	ta = '/';
	if(rm == 0)
	ta = '|';
	
	for(l = xrb+1 ; l <= xru; ++l ){
		if(l >= x - 5 && l <= x + 5){ //�B�z���x���t5�d�򤺪��ϧ�(�]���ݭn�B�z���u��P�I) 
		
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
				int plong = 7 + xn + yn; // ��XP���y�Щһݭn������ 
				
				for(m = -39; m <=40; ++m){
					if(m == 0){
				
						if(l % 5 != 0)
						printf("|");
			
						else{
						printf("%d",l);
			
							//�B�z��X5�����Ʈ�x�b���쪺���D
							int temp = l, lx=1;
							while(temp != 0){
							temp/=10;
							++lx;
							}				
						m += lx -2;  
						}
					}
			
					else{
						//��XP�I�y�� �קK����o�� 
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
			
							//�B�z��X5�����Ʈ�x�b���쪺���D
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
						//�B�z��X5�����Ʈ�x�b���쪺���D
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
