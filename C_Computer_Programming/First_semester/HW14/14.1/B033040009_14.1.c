#include<stdio.h>
#include<string.h>

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
//              �򯪫O��         �õLBUG 
//
//
//

int main(){
	FILE *input;
	input = fopen("Input.txt","r");
		char line1[4096];
		int stack[5];
		int check_num[100000];
		fgets(line1,4096,input);
			int point = 0;
			int n;
			int pos = 0;
			char *p = line1;
				while(sscanf(p, "%d%n", &n , &pos) == 1){
				stack[point] = n;
				check_num[n] = 1;
				++point;
				p += pos;
				}
				--point;
				char command[4];
				int target;
				
				while(fscanf(input,"%s%d",command,&target) != EOF){
									
					
					if(strcmp(command,"Push") == 0){
						/*
						stack[point + 1] = target;
						++point;
						check_num[target] = 1;
						*/
						
						
						if(check_num[target] == 1){
						printf("���ƪ��Ʀr���\n");
						break;
						}
						else{
							if(point >= 4){
							printf("�c�l�w��\n");
							break;
							}
							
							else{
							stack[point + 1] = target;
							++point;
							check_num[target] = 1;
							}
						}
						
					}
					
					if(strcmp(command,"Pop") == 0){
						/*
						--point;
						check_num[target] = 0;
						*/
						
						
						if(check_num[target] != 1){
						printf("�L���Ʀr���\n");
						break;
						}
						
						else{
							if(stack[point] != target){
							printf("���O�̫��i�h���Ʀr���\n");
							break;
							}
							
							else{
							--point;
							check_num[target] = 0;
							}
						}
						
					}
					
					
				}
				
				printf("�c�l�̪��Ʀr��� : ");
				int i;
				for(i = 0 ; i <= point ; ++i)
					printf("%d ", stack[i]);
				printf("\n");
				
	fclose(input);
	system("PAUSE");
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

                      �C�q�O��                �õL BUG
*/
