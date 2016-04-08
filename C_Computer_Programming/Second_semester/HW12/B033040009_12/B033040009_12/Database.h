#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	int tab;
	int number; 
    string name;
	int old;
    bool sex; 
    string mail;
	string filename;
	string address;
	struct node *prev,*next;
}Node;

class Database
{
public:
	
	Node *head,*tail;//主要的 double linked list
	Node *searchhead;//搜尋用 stack
	int count;//計算 主要的 double linked list 內有幾筆資料
	
	/*
	建構子 初始化變數
	*/
	Database()
	{
		head = nullptr;
		tail = nullptr;
		searchhead = nullptr;
		count = 0;
	}


/*
************************
*******  Normal  *******
************************
*/

	/*
	push 進 主要的 double linked list
	*/
	void push(int tab, int number, string name, int old, bool sex, string mail, string filename, string address)
	{
		Node *newptr = new Node;
		newptr->next = nullptr;
		newptr->prev = nullptr;
		newptr->tab = tab; 
		newptr->number = number; 
		newptr->name = name;
		newptr->old = old;
		newptr->sex = sex; 
		newptr->mail = mail;
		newptr->filename = filename;
		newptr->address = address;
		if(head == nullptr)
		{
			head = tail = newptr;
		}
		else
		{
			tail->next = newptr;
			newptr->prev = tail;
			tail = newptr;
		}
		count++;
	}//push function end

	/*
	刪除 "編號為 n" 的資料
	*/
	bool deletenode(int n)
	{
		for(Node* temp = head;temp!=nullptr;temp = temp->next)
		{
			if(n == temp->number)
			{
				if(temp == head && temp == tail)
				{
					head = tail = nullptr;
				}
				else if(temp == head)
				{
					head = head->next;
				}
				else if(temp == tail)
				{
					tail = tail->prev;
					tail->next = nullptr;
				}
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
				delete temp;
				count--;
				return true;
			}
		}
		return false;
	}//deletenode function end

	/*
	清空 (用來處理重新載入的狀況)
	*/
	void clear()
	{
		while(count)
		{
			Node *temp = head;
			if(head->next == nullptr)
				head = nullptr;
			else
			{
				head = head->next;
				delete temp;
			}
			count--;
		}
	}//clear function end

	/*
	排序 method1 == 1 -> 按照編號 , method1 == 2 -> 按照性別 , method1 == 3 -> 按照年齡
	*/
	void sort(int method)
	{
		Node *cur = head;
		if(method == 1)
		{
			for(int i=0;i<count;i++)
			{
				cur = head;
				while(cur->next != nullptr)
				{
					if((cur->number) > (cur->next->number))//小->大
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 1)
		else if(method == 2)
		{
			for(int i=0;i<count;i++)
			{
				cur = head;
				while(cur->next != nullptr)
				{
					if((int)(cur->sex) < (int)(cur->next->sex))	//male->female
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 2)
		else if(method == 3)
		{
			for(int i=0;i<count;i++)
			{
				cur = head;
				while(cur->next != nullptr)
				{
					if((int)(cur->old) > (int)(cur->next->old))	//male->female
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 3)
	}//sort function end

	/*
	判斷是否有重複編號 "有->true , 沒有->false"
	*/
	bool dubnum(int num)
	{
		Node *cur = head;
		while(cur != nullptr)
		{
			if(cur->number == num)
				return true;
			cur = cur->next;
		}
		return false;
	}//dubnum function end

	/*
	取得 head
	*/
	Node* getList()
	{
		return head;
	}

	/*
	取得 count
	*/
	int getCount()
	{
		return count;
	}

/*
************************
*******  Search  *******
************************
*/

	/*
	尋找 "編號在 n1~n2 之間" 或 "性別 jsex == 1 -> Male , jsex == 0 -> Female  , jsex == 3 -> 都可" 或 "姓名開頭是 s1" 或 "Emial 是 s2" 或 "地址 是 s3"  ***未完成
	*/
	void search(int n1,int n2,int jsex,string s1,string s2)
	{
		Node *cur = head;
		int judge=0;//判斷s1 s2
		int use=0;//找出 '@' 的位置
		
		/*清空 searchhead 以便重新搜尋*/
		while(searchhead != nullptr)
		{
			Node *temp = searchhead;
			if(head->next == nullptr)
				searchhead = nullptr;
			else
			{
				searchhead = searchhead->next;
				delete temp;
			}
		}
		
		/*主要搜尋Loop*/
		while(cur != nullptr)
		{
			judge=0;
			use=0;
			if(cur->number >= n1 && cur->number <= n2)
			{
				if(jsex == 1)
				{
					if(cur->sex != true)
					{
						cur = cur->next;
						continue;
					}
				}
				else if(jsex == 0)
				{
					if(cur->sex != false)
					{
						cur = cur->next;
						continue;
					}
				}
				if(s1 != "allok")
				{
					for(int i=0;i<(int)(s1.size());i++)
					{
						if((cur->name)[i] != s1[i])
						{
							judge = 1;
							break;
						}
					}
				}
				if(judge == 1)
				{
					cur = cur->next;
					continue;
				}
				if(s2 != "allok")
				{
					while((cur->mail)[use] != '@')
					{
						use++;
					}
					for(int i=0;i<(int)(s2.size());i++)
					{
						if((cur->mail)[i+use+1] != s2[i])
						{
							judge = 2;
							break;
						}
					}
				}
				if(judge == 2)
				{
					cur = cur->next;
					continue;
				}
				searchpush(cur->number,cur->name,cur->old,cur->sex,cur->mail,cur->filename,cur->address);
			}
			cur = cur->next;
		}
	}//search function end

	/*
	push 進 Search 之後的 head 中 "searchhead"
	*/
	void searchpush(int number, string name, int old, bool sex, string mail, string filename, string address)
	{
		Node *newptr = new Node;
		newptr->next = nullptr;
		newptr->prev = nullptr;
		newptr->number = number; 
		newptr->name = name;
		newptr->old = old;
		newptr->sex = sex; 
		newptr->mail = mail;
		newptr->filename = filename;
		newptr->address = address;
		if(searchhead == nullptr)
		{
			searchhead = newptr;
		}
		else
		{
			newptr->next = searchhead;
			searchhead = newptr;
		}
	}//searchpush function end

	/*
	取得搜尋完畢後的 searchhead
	*/
	Node* getSList()
	{
		return searchhead;
	}

	/*
	搜尋完畢後的 searchhead 的排序(因為stack先進後出 印出來的資料會和一般排序相反)  method1 == 1 -> 按照編號 , method1 == 2 -> 按照性別
	*/
	void searchsort(int method)
	{
		Node *cur = searchhead;
		if(method == 1)
		{
			for(int i=0;i<count;i++)
			{
				cur = searchhead;
				while(cur->next != nullptr)
				{
					if((cur->number) > (cur->next->number))//小->大
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 1)
		else if(method == 2)
		{
			for(int i=0;i<count;i++)
			{
				cur = searchhead;
				while(cur->next != nullptr)
				{
					if((int)(cur->sex) < (int)(cur->next->sex))	//male->female
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 2)
		else if(method == 3)
		{
			for(int i=0;i<count;i++)
			{
				cur = searchhead;
				while(cur->next != nullptr)
				{
					if((int)(cur->old) > (int)(cur->next->old))	//male->female
					{
						int num1 = cur->number;
						string name1 = cur->name;
						int old1 = cur->old;
						bool sex1 = cur->sex;
						string mail1 = cur->mail;
						string filename1  = cur->filename;
						string address1  = cur->address;
						
						cur->number = cur->next->number;
						cur->name = cur->next->name;
						cur->old = cur->next->old;
						cur->sex = cur->next->sex;
						cur->mail = cur->next->mail;
						cur->filename = cur->next->filename;
						cur->address = cur->next->address;

						cur->next->number = num1;
						cur->next->old = old1;
						cur->next->name = name1;
						cur->next->sex = sex1;
						cur->next->mail = mail1;
						cur->next->filename = filename1;
						cur->next->address = address1;
					}
					cur = cur->next;
				}
			}
		}//else if(method == 3)
	}//searchsort function end


/*
*************************
*********  End  *********
*************************
*/

};//Database class end