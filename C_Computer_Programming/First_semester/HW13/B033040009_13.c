#include<stdio.h>
#include <time.h>
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//              佛祖保佑         永無BUG 
//
//
//

void swap (int *, int *);

int main(){
	int n;
	while(scanf("%d",&n)){
		if(n < 10 || n > 50){
		printf("輸入不合法，應介於10~50之間，請重新輸入\n");
		continue;
		}
		
	FILE *output;
	output = fopen("output1.txt","w");
	int a[3][50];
	srand(15);
	
	int i , j;
		for(i = 0 ; i < 3 ; ++i)
			for(j = 0 ; j < n ; ++j){
				int t;
				do{
				t = rand() % 501;
				a[i][j] = t;
				}while(t == 0);
			}
	// bubble sort
	time_t start_tm, finish_tm; 
  	time(&start_tm); 
  	fprintf(output,"Bubble Sort\n");
	fprintf(output,"排序前 : ");
	for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[0][j]);
	fprintf(output,"\n");
		for (i = n - 1; i > 0; --i){
       		for (j = 0 ; j < i ; ++j){
            	if (a[0][j] > a[0][j+1])
                swap(&a[0][i], &a[0][j]);
        	}
    	}
    fprintf(output,"排序後 : ");
    for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[0][j]);
	fprintf(output,"\n");
	time(&finish_tm); 
  	double elapsed_tm=difftime(finish_tm,start_tm); 
  	fprintf(output,"運算時間 : %d s\n", elapsed_tm);
  	
  	// Selection Sort 
  	time(&start_tm); 
  	fprintf(output,"Selection Sort \n");
	fprintf(output,"排序前 : ");
	for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[1][j]);
	fprintf(output,"\n");
  	for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            if (a[1][i]>a[1][j])
                swap(&a[1][i], &a[1][j]);
    fprintf(output,"排序後 : ");
    for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[1][j]);
	fprintf(output,"\n");
	time(&finish_tm); 
  	elapsed_tm=difftime(finish_tm,start_tm); 
  	fprintf(output,"運算時間 : %d s\n", elapsed_tm);
  	
  	//Insertion Sort 
  	time(&start_tm); 
  	fprintf(output,"Insertion Sort \n");
	fprintf(output,"排序前 : ");
	for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[2][j]);
	fprintf(output,"\n");
  		for (i = 1; i <= n; i++){
			int temp = a[2][i]; 
			for(j = i - 1; j >= 0 && a[2][j] > temp; j--) 
				a[2][j + 1] = a[2][j];
			a[2][j + 1] = temp; 
		}
	fprintf(output,"排序後 : ");
    for(j = 0 ; j < n ; ++j)
	fprintf(output,"%d ", a[2][j]);
	fprintf(output,"\n");
	time(&finish_tm); 
  	elapsed_tm=difftime(finish_tm,start_tm); 
  	fprintf(output,"運算時間 : %d s\n", elapsed_tm);
  	
	fclose(output);
	}
}

void swap (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* 
                                 |~~~~~~~|
                                 |       |	
                                 |       |
                                 |       |
                                 |       |
                                 |       |
      |~.\\\_\~~~~~~~~~~~~~~xx~~~         ~~~~~~~~~~~~~~~~~~~~~/_//;~|
      |  \  o \_         ,XXXXX),                         _..-~ o /  |
      |    ~~\  ~-.     XXXXX`)))),                 _.--~~   .-~~~   |
       ~~~~~~~`\   ~\~~~XXX' _/ ';))     |~~~~~~..-~     _.-~ ~~~~~~~ 
                `\   ~~--`_\~\, ;;;\)__.---.~~~      _.-~
                  ~-.       `:;;/;; \          _..-~~
                     ~-._      `''        /-~-~ 
                         `\              /  /
                           |         ,   | |
                            |  '        /  |
                             \/;          |
                              ;;          |
                              `;   .       |
                              |~~~-----.....|
                             | \             \
                            | /\~~--...__    |
                            (|  `\       __-\|  
                            ||    \_   /~    |
                            |)     \~-'      |
                             |      | \      '
                             |      |  \    :
                              \     |  |    |
                               |    )  (    ) 
                                \  /;  /\  |
                                |    |/   |
                                |    |   |
                                 \  .'  ||
                                 |  |  | |
                                 (  | |  |
                                 |   \ \ |
                                 || o `.)|
                                 |`\\\\) |
                                 |       |
                                 |       |
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                      耶穌保佑                永無 BUG
*/
