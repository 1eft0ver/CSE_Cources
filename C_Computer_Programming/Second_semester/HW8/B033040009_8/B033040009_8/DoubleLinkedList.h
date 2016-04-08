#include<stdio.h>
using namespace std;

class Dnode
{
	public:
		Dnode(){
		next = NULL;
		prev = NULL;
		};
		int data;
		void setnext(Dnode **head, Dnode **rear , int num){

		};

		void setpre(Dnode **head, Dnode **rear , int num){
			Dnode *temp;
			temp = new Dnode;
			temp.data = num;
			if(is_empty( (*head) ) && is_empty( (*rear) ))
			{
				(*head) = temp;
				(*head).next = NULL;
				(*head).prev = NULL;
				(*rear) = temp;
				(*rear).next = NULL;
				(*rear).prev = NULL;
			}
			else
			{
				temp.next = (*head);
				temp.prev = NULL;
				(*head).prev = temp;
				(*head).temp;
			}
		 ++count;
		};

	private:
		Dnode *next;
		Dnode *prev;
};