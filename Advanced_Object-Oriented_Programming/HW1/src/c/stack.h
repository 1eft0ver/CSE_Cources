#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct stack {
    int sp;
    int stk[STACK_SIZE];
    struct node* bottom;
};

struct node {
	int data;
	struct node* next;
};

extern void push(struct stack* it, int x);
extern int pop(struct stack* it);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif
