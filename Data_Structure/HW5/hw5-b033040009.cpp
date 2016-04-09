/*
Author：蔡宜勳 B033040009
Date：Nov. 23, 2015
Purpose:處理兩個多項式之加法與乘法
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class PolyNode                  //Linked List節點的Class
{
    public:
    PolyNode *next;
    int coef;                   //coef : 係數
    int exp;                    //exp  : 指數

    private:
};

class LinkedList
{
    public:
        LinkedList();           //Linked List Constructor
        ~LinkedList();          //Linked List Destructor
        void insert_back(int _coef, int _exp);              //將data放入List尾端的函式
        void insert_front(int _coef, int _exp);             //將data放入List前端的函式
        void insert_prev(PolyNode *n, int _coef, int _exp); //將data放入List中指定位置前一格的函式
        LinkedList format();                                //將List按照指數大小順序排列，並且去除掉係數為0的項的函式
        LinkedList operator+(const LinkedList& l);          //overload operator +
		LinkedList operator*(const LinkedList& l);          //overload operator *
		void print_list();                                  //輸出List內容的函式
    private:
        PolyNode *head;
};

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
}

void LinkedList::insert_back(int _coef, int _exp)
{
    PolyNode* newNode = new PolyNode;
	newNode->coef = _coef;
	newNode->exp = _exp;
	newNode->next = NULL;

	PolyNode* current = head;
	if (head == NULL)
		head = newNode;
	else
	{

		while (current->next != NULL)
		current = current->next;
		current->next = newNode;

	}
}

void LinkedList::insert_front(int _coef, int _exp)
{
    PolyNode* newNode = new PolyNode;
	newNode->coef = _coef;
	newNode->exp = _exp;
	newNode->next = head;
	head = newNode;
}

void LinkedList::insert_prev(PolyNode *n, int _coef, int _exp)
{
    PolyNode* newNode = new PolyNode;
	newNode->coef = _coef;
	newNode->exp = _exp;
	newNode->next = n;

    PolyNode* current = head;
    if(current->next == NULL )  //假若List內只有一個element的情況
        head = newNode;

    else
    {
        if(current == n)
        head = newNode;

        else
        {
            while (current->next != n)
                current = current->next;
            current->next = newNode;
        }
    }

}

LinkedList LinkedList::format()
{
    LinkedList formattedList;
    PolyNode* current = head;
    while (current != NULL)
    {

        PolyNode* formatted_current = formattedList.head;
        if(current->coef != 0){                 //排除係數為0的情況

            if(formatted_current == NULL)       //List為空的情況，直接將資料insert_back即可(insert_front亦可)
                formattedList.insert_back(current->coef, current->exp);

            else
            {
                while(formatted_current != NULL)
                {
                    if(current->exp > formatted_current->exp){          //當現在讀取到的資料的指數大於現在指向的資料的指數時，將該筆資料插入當前資料前一格
                        formattedList.insert_prev(formatted_current, current->coef, current->exp);
                        break;
                    }

                    else if(current->exp == formatted_current->exp){    //當現在讀取到的資料的指數等於現在指向的資料的指數時，將係數相加
                        formatted_current->coef += current->coef;
                        break;
                    }

                    else if(formatted_current->next == NULL){           //讀到List尾端時，代表現在讀到的這筆資料的指數小於當前所有資料，因此將這筆資料放入List尾端
                        formattedList.insert_back(current->coef, current->exp);
                        break;
                    }

                    formatted_current = formatted_current->next;
                }

            }

        }
    current = current->next;
    }

    if(formattedList.head == NULL)  //當沒有資料，也就是相乘時乘數或被乘數為0，或是相加相抵成0時，return coef = 0, exp = 0
    {
        LinkedList zero;
        zero.insert_back(0,0);
        return zero;
    }
    else
    return formattedList;
}

LinkedList LinkedList::operator*(const LinkedList& multiplier)
{
    LinkedList result, mulitplicand;
    PolyNode* temp = head;
    while(temp != NULL)         //為了確保不改變被乘數的數值，使用新的List存取被乘數的值
    {
            mulitplicand.insert_back(temp->coef, temp->exp);
            temp = temp->next;
    }
    PolyNode* mulitplicand_current = mulitplicand.head;
    PolyNode* multiplier_current = multiplier.head;

    if ((mulitplicand_current->exp == 0 && mulitplicand_current->coef == 0)
        || (multiplier_current->exp == 0 && mulitplicand_current->coef == 0))   //假若乘數或被乘數為0時，積必為0
    {
        LinkedList zero;
        zero.insert_back(0,0);
        return zero;
    }

    else
    {
        while(mulitplicand_current != NULL)
        {
            multiplier_current = multiplier.head;
            while(multiplier_current != NULL)
            {
            result.insert_back(mulitplicand_current->coef * multiplier_current->coef, mulitplicand_current->exp + multiplier_current->exp); //將各項交叉相乘後直接insert_back入list內，最後的結果再format即可
            multiplier_current = multiplier_current-> next;
            }
        mulitplicand_current = mulitplicand_current->next;
        }
        return result.format();
    }
}

LinkedList LinkedList::operator+(const LinkedList& addend)
{
    LinkedList result;
    PolyNode* temp = head;
    while(temp != NULL)     //為了確保不改變被加數的數值，使用新的List存取被加數的值
    {
            result.insert_back(temp->coef, temp->exp);
            temp = temp->next;
    }
    PolyNode* result_current = result.head;
    PolyNode* addend_current = addend.head;

    if(result_current->exp == 0 && result_current->coef == 0)  //被加數為0時，return加數
    return addend;

    else if(addend_current->exp == 0 && addend_current->coef == 0)  //加數為0時，return被加數
    return result;

    else
    {
        while(addend_current != NULL)
        {
            while(result_current != NULL)   //一項一項存取加數加進被加數內
            {
                if(addend_current == NULL)  //假若所有加數的項都加過了，離開迴圈
                    break;

                if(addend_current->exp > result_current->exp)   //假若當前讀取到的項的指數大於當前指向的被加數的項，將該筆資料插入當前資料前一格
                {
                    result.insert_front(addend_current->coef, addend_current->exp);
                    addend_current = addend_current->next;
                    continue;
                }
                else if(addend_current->exp == result_current->exp)     //當現在讀取到的資料的指數等於現在指向的資料的指數時，將係數相加
                {
                    result_current->coef += addend_current->coef;
                    addend_current = addend_current->next;
                    continue;
                }
                else if(result_current->next == NULL)                   //讀到List尾端時，代表現在讀到的這筆資料的指數小於當前所有資料，因此將這筆資料放入List尾端
                {
                    result.insert_back(addend_current->coef, addend_current->exp);
                    addend_current = addend_current->next;
                    continue;
                }

            result_current = result_current->next;
            }
        }
    return result.format();
    }
}

void LinkedList::print_list()       //巡行並印出List的內容
{
    PolyNode *current = head;
    while(current != NULL)
    {
        cout << current->coef << " " << current->exp << endl;
        current = current->next;
    }
}

int main()
{
    int n, m;
    int counter = 1;    //計算當前為Case幾的counter
    while(1)
    {
    cin >> n;
    LinkedList l1;
        for(int i = 0 ; i < n ; ++i)
        {
            int exp, coef;
            cin >> coef >> exp;
            l1.insert_back(coef, exp);
        }
        l1 = l1.format();

    cin >> m;
    LinkedList l2;
        for(int i = 0 ; i < m ; ++i)
        {
            int exp, coef;
            cin >> coef >> exp;
            l2.insert_back(coef, exp);
        }
        l2 = l2.format();

    if(n == 0 && m == 0)        //當n與m皆為0時，結束程式
        break;
    cout << "Case" << counter << ":" <<endl;
    cout << "ADD" << endl;
    LinkedList Sum;
    Sum = l1 + l2;
    Sum.print_list();
    cout << endl;
    cout << "MULTIPLY" << endl;
    LinkedList Product;
    Product = l1 * l2;
    Product.print_list();
    cout << "END" << endl;
    ++counter;
    }
}
