//
//  Tong_Stack.h
//  Tong-C
//
//  Created by Tongle on 2021/7/21.
//

#ifndef Tong_Stack_h
#define Tong_Stack_h

#include <stdio.h>
#define maxn 10000

#pragma mark --栈数组
/**
 结点设计
 */
typedef struct stack{
    int data[maxn];
    int top;
}stack;

/**
 初始化栈
 */
stack *init(void);

/**
 入栈
 */
void push(stack *s, int data);

/**
 出栈
 */

void pop(stack *s);

/**
 打印
 */

void print_stack(stack *s);

/**
 测试stack
 */
void load_stack(void);

#pragma mark --战链表

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack_node{
    Node *top;
    int count;
}link_stack;


link_stack *creat_stack(void);

link_stack *push_stack(link_stack *s, int data);

link_stack *pop_stack(link_stack *s);

void print_link_stack(link_stack *s);



#endif /* Tong_Stack_h */
