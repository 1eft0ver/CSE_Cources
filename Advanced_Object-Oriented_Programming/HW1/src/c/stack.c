#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(struct stack* it, int x)
{
    /*
    it->stk[++it->sp] = x;
    */
    struct node* iterator = it->bottom;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = NULL;

    while(iterator->next != NULL)
        iterator = iterator->next;
    iterator->next = new_node;
}

int pop(struct stack* it)
{
    /*
    return it->stk[it->sp--];
    */
    struct node* iterator = it->bottom;
    struct node* iterator_prev; 
    if(iterator->next == NULL){
    	printf("Stack is empty. No more element popable\n");
    	return EXIT_FAILURE;
    }

    else{
        while(iterator->next != NULL) {
            iterator_prev = iterator;
            iterator = iterator->next;        
        }
        int return_value = iterator->data;
        iterator_prev->next = NULL;
        free(iterator);
        return return_value;
    }
}

struct stack* new_stack()
{
    
    struct stack* stk = (struct stack*)malloc(sizeof(struct stack));
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->next = NULL;
    //stk->sp = -1;
    stk->bottom =  nd;
    return stk;
    

}

void delete_stack(struct stack* stk)
{
    free(stk);
}