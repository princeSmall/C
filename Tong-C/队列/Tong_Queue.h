//
//  Tong_Queue.h
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/21.
//

#ifndef Tong_Queue_h
#define Tong_Queue_h

#include <stdio.h>
#define maxsize 10

#pragma mark --顺序队列
/**
 定义结点
 */
typedef struct q_node{
    int data;
    struct q_node *next;
}q_node;

/**
 定义队首和队尾指针
 */

typedef struct Queue{
    q_node *front;
    q_node *rear;
}Queue;

/**
 初始化结点
 */
q_node *init_node(void);

/**
 初始化队列
 */
Queue *init_queue(void);

/**
 入队
 */
void queue_push(Queue *q, int data);

/**
 出队
 */

void queue_pop(Queue *q);

/**
 打印
 */
void print_queue(Queue *q);

#pragma mark -- 循环队列

typedef struct circle_queue{
    int data[maxsize];
    int front;
    int rear;
}circle_queue;

circle_queue *init_circle_queue(void);

void circle_queue_push(circle_queue *q, int data);

void circle_queue_pop(circle_queue *q);

void load_queue(void);


#endif /* Tong_Queue_h */
