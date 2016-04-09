#ifndef __STACK_H__
#define __STACK_H__
#include <cstdlib>
#include <iostream>
using namespace std;

//   Creating a NODE Structure
struct node
{
    int data;
    struct node *next;
};

// Creating a class STACK
class Stack
{
    struct node *top;
    public:
    Stack() // constructure
    {
        top=NULL;
    }
    void push(int x); // to insert an element
    int pop();  // to delete an element
    //void show(); // to show the stack
};
// PUSH Operation
void Stack::push(int x)
{
    
    struct node *ptr;
    ptr=new node;
    ptr->data=x;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;
    

}

// POP Operation
int Stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"nThe stack is empty!!!";
    }
    temp=top;
    top=top->next;
    int return_value = temp->data;
    delete temp;
    return return_value;
}

#endif

const int NUM_ITEMS = 200;

int main()
{
    //Node n1;
    Stack stk1;
    Stack stk2;

    for (int i = 0; i < NUM_ITEMS; i++) {
    stk1.push(100+i);
    stk2.push(600+i);
    }

    cout << "Dump of stack 1:" << endl;
    for (int i = 0; i < NUM_ITEMS; i++)
    cout << stk1.pop() << endl;

    cout << "Dump of stack 2:" << endl;
    for (int i = 0; i < NUM_ITEMS; i++)
    cout << stk2.pop() << endl;
    
    return 0;
}
