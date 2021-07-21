//
//  Tong_Stack.c
//  Tong-C
//
//  Created by Tongle on 2021/7/21.
//

#include "Tong_Stack.h"
#include <stdlib.h>
#include <string.h>

stack *init(){
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("failure");
        exit(0);
    }
    //memset 其表示将整个空间初始化
    memset(s->data, 0, sizeof(s->data));
    s->top = 0;
    return s;
}

void push(stack *s, int data){
    s->data[s->top]=data;
    s->top++;
}

void pop(stack *s){
    if (s->top != 0) {
        s->data[s->top] = 0;
        s->top--;
    }
}

void print_stack(stack *s){
    for (int i = s->top -1; i >= 0; i--) {
        printf("stack---%d \n",s->data[i]);
    }
}

link_stack *creat_stack(void){
    link_stack *stack = (link_stack *)malloc(sizeof(link_stack));
    if (stack == NULL) {
        printf("creat failure...");
        exit(0);
    }
    stack->top = NULL;
    stack->count = 0;
    return stack;
}

link_stack *push_stack(link_stack *s, int data){
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = s->top;
    s->top = node;
    s->count ++;
    return s;
}

link_stack *pop_stack(link_stack *s){
    Node *temp;
    temp = s->top;
    if (s->top == NULL) {
        printf("stack error: stack is nil");
    }else{
        s->top = s->top->next;
        free(temp);
        s->count --;
    }
    return s;
}

void print_link_stack(link_stack *s){
    Node *node;
    node = s->top;
    if (s->top == NULL) {
        printf("stack error: stack is nil");
    }
    while (node) {
        printf("link_stack---%d  \n",node->data);
        node = node->next;
    }
}

void load_stack(){
    /**
     数组栈
     */
    stack *s = init();
    for (int i = 0; i < 5; i ++) {
        int input[5] = {11,22,33,44,55};
        push(s, input[i]);
    }
    print_stack(s);
    pop(s);
    print_stack(s);
    /**
     链表栈
     */
    link_stack *stack = creat_stack();
    for (int i = 0; i < 5; i ++) {
        int input[5] = {12,13,14,15,16};
        push_stack(stack, input[i]);
    }
    print_link_stack(stack);
    pop_stack(stack);
    print_link_stack(stack);
    
}
