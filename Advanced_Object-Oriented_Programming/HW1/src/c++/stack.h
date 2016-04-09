#ifndef __STACK_H__
#define __STACK_H__
#include <cstdlib>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class Stack
{
    struct node *top;
    
    public:
    Stack()  {
        top = NULL;
    }

    void push(int x) {    
        struct node *ptr;
        ptr = new node;
        ptr->data = x;
        ptr->next = NULL;
        
        if(top!=NULL)
            ptr->next=top;
        
        top=ptr;
    }

    int pop() {
        struct node *temp;
        if(top ==   NULL) {
            cout<<"Stack is empty. No more element popable." << endl;
            return -1;
        }

        temp=top;
        top=top->next;
        int return_value = temp->data;
        delete temp;
        return return_value;
    }
};

#endif
