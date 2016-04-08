/*
Author�G���y�� B033040009
Date�GNov. 23, 2015
Purpose:�B�z��Ӧh�������[�k�P���k
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class PolyNode                  //Linked List�`�I��Class
{
    public:
    PolyNode *next;
    int coef;                   //coef : �Y��
    int exp;                    //exp  : ����

    private:
};

class LinkedList
{
    public:
        LinkedList();           //Linked List Constructor
        ~LinkedList();          //Linked List Destructor
        void insert_back(int _coef, int _exp);              //�Ndata��JList���ݪ��禡
        void insert_front(int _coef, int _exp);             //�Ndata��JList�e�ݪ��禡
        void insert_prev(PolyNode *n, int _coef, int _exp); //�Ndata��JList�����w��m�e�@�檺�禡
        LinkedList format();                                //�NList���ӫ��Ƥj�p���ǱƦC�A�åB�h�����Y�Ƭ�0�������禡
        LinkedList operator+(const LinkedList& l);          //overload operator +
		LinkedList operator*(const LinkedList& l);          //overload operator *
		void print_list();                                  //��XList���e���禡
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
    if(current->next == NULL )  //���YList���u���@��element�����p
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
        if(current->coef != 0){                 //�ư��Y�Ƭ�0�����p

            if(formatted_current == NULL)       //List���Ū����p�A�����N���insert_back�Y�i(insert_front��i)
                formattedList.insert_back(current->coef, current->exp);

            else
            {
                while(formatted_current != NULL)
                {
                    if(current->exp > formatted_current->exp){          //��{�bŪ���쪺��ƪ����Ƥj��{�b���V����ƪ����ƮɡA�N�ӵ���ƴ��J��e��ƫe�@��
                        formattedList.insert_prev(formatted_current, current->coef, current->exp);
                        break;
                    }

                    else if(current->exp == formatted_current->exp){    //��{�bŪ���쪺��ƪ����Ƶ���{�b���V����ƪ����ƮɡA�N�Y�Ƭۥ[
                        formatted_current->coef += current->coef;
                        break;
                    }

                    else if(formatted_current->next == NULL){           //Ū��List���ݮɡA�N��{�bŪ�쪺�o����ƪ����Ƥp���e�Ҧ���ơA�]���N�o����Ʃ�JList����
                        formattedList.insert_back(current->coef, current->exp);
                        break;
                    }

                    formatted_current = formatted_current->next;
                }

            }

        }
    current = current->next;
    }

    if(formattedList.head == NULL)  //��S����ơA�]�N�O�ۭ��ɭ��ƩγQ���Ƭ�0�A�άO�ۥ[�۩覨0�ɡAreturn coef = 0, exp = 0
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
    while(temp != NULL)         //���F�T�O�����ܳQ���ƪ��ƭȡA�ϥηs��List�s���Q���ƪ���
    {
            mulitplicand.insert_back(temp->coef, temp->exp);
            temp = temp->next;
    }
    PolyNode* mulitplicand_current = mulitplicand.head;
    PolyNode* multiplier_current = multiplier.head;

    if ((mulitplicand_current->exp == 0 && mulitplicand_current->coef == 0)
        || (multiplier_current->exp == 0 && mulitplicand_current->coef == 0))   //���Y���ƩγQ���Ƭ�0�ɡA�n����0
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
            result.insert_back(mulitplicand_current->coef * multiplier_current->coef, mulitplicand_current->exp + multiplier_current->exp); //�N�U����e�ۭ��᪽��insert_back�Jlist���A�̫᪺���G�Aformat�Y�i
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
    while(temp != NULL)     //���F�T�O�����ܳQ�[�ƪ��ƭȡA�ϥηs��List�s���Q�[�ƪ���
    {
            result.insert_back(temp->coef, temp->exp);
            temp = temp->next;
    }
    PolyNode* result_current = result.head;
    PolyNode* addend_current = addend.head;

    if(result_current->exp == 0 && result_current->coef == 0)  //�Q�[�Ƭ�0�ɡAreturn�[��
    return addend;

    else if(addend_current->exp == 0 && addend_current->coef == 0)  //�[�Ƭ�0�ɡAreturn�Q�[��
    return result;

    else
    {
        while(addend_current != NULL)
        {
            while(result_current != NULL)   //�@���@���s���[�ƥ[�i�Q�[�Ƥ�
            {
                if(addend_current == NULL)  //���Y�Ҧ��[�ƪ������[�L�F�A���}�j��
                    break;

                if(addend_current->exp > result_current->exp)   //���Y��eŪ���쪺�������Ƥj���e���V���Q�[�ƪ����A�N�ӵ���ƴ��J��e��ƫe�@��
                {
                    result.insert_front(addend_current->coef, addend_current->exp);
                    addend_current = addend_current->next;
                    continue;
                }
                else if(addend_current->exp == result_current->exp)     //��{�bŪ���쪺��ƪ����Ƶ���{�b���V����ƪ����ƮɡA�N�Y�Ƭۥ[
                {
                    result_current->coef += addend_current->coef;
                    addend_current = addend_current->next;
                    continue;
                }
                else if(result_current->next == NULL)                   //Ū��List���ݮɡA�N��{�bŪ�쪺�o����ƪ����Ƥp���e�Ҧ���ơA�]���N�o����Ʃ�JList����
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

void LinkedList::print_list()       //����æL�XList�����e
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
    int counter = 1;    //�p���e��Case�X��counter
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

    if(n == 0 && m == 0)        //��n�Pm�Ҭ�0�ɡA�����{��
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
