#include<stdio.h>
#include<time.h>
#define LOTTERY_NUM 7

int main(){
	
	FILE *in, *out;
	in = fopen("Input1.txt","r");
	out = fopen("Output2.txt", "w");

	int i;
	int lot[7]; 
	int player[7];	
	
		
		for(i = 0 ; i < LOTTERY_NUM; ++i){
			int temp;
			fscanf(in, "%d" , &temp);
			lot[i] = temp;
			if(temp > 49 | temp < 1)
			printf("��J�W�X�d��!! ��J������1~49���� �Э��s��J\n");
		}
		
		srand(time(NULL)); 
		int num[50] = {0};
		for(i = 0 ; i < LOTTERY_NUM; ++i){
			player[i] = rand() % 50;
			if(player[i] == 0 || num[player[i]] == 1){
			--i;
			continue;
			}
			num[player[i]] = 1;
		}	
		//fprintf(out,"�o�����X : %d %d %d %d %d %d %d\n", lot[0],lot[1],lot[2],lot[3],lot[4],lot[5],lot[6]);
		fprintf(out,"��`���X : %d %d %d %d %d %d %d\n", player[0],player[1],player[2],player[3],player[4],player[5],player[6]);
		
		int matchcount = 0, specialmatch = 0; //�]�w����ܼ� �p��襤�������ƶq�H�ίS�O���襤�P�_ 
			if(lot[6] == player[6])
			specialmatch = 1;
			
			int m, n;
			for(m = 0 ; m < LOTTERY_NUM-1; ++m){
				for(n = 0; n < LOTTERY_NUM-1; ++n){
				if (player[m] == lot[n])
				++matchcount;
				}
			}
		if(matchcount < 3)
		fprintf(out,"�S����!!\n");
		
		
		
		if(matchcount == 6)
		fprintf(out,"���� !! ���Y��\n");
		else{
			if(specialmatch == 1){
				if(matchcount == 5)
				fprintf(out,"���� !! ���L��\n");
				
				if(matchcount == 4)
				fprintf(out,"���� !! ���v��\n");
				
				if(matchcount == 3)
				fprintf(out,"���� !! ������\n");
				
			}
			
			if(specialmatch == 0){
				if(matchcount == 5)
				fprintf(out,"���� !! ���Ѽ�\n");
				
				if(matchcount == 4)
				fprintf(out,"���� !! �����\n");
				
				if(matchcount == 3)
				fprintf(out,"���� !! ������\n");
			}
		}
		fclose(in);
		fclose(out);
		
	
} 
