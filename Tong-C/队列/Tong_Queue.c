//
//  Tong_Queue.c
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/21.
//

#include "Tong_Queue.h"
#include <stdlib.h>

q_node *init_node(void){
    q_node *n = (q_node *)malloc(sizeof(q_node));
    if (n == NULL) {
        printf("q_node error: apply failure");
        exit(0);
    }
    n->data = 0;
    n->next = 0;
    return n;
}

Queue *init_queue(void){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("queue error: apply failure");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int emptyQueue(Queue *q){
    if (q->front == NULL) {
        return 1;
    }else{
        return 0;
    }
}

void queue_push(Queue *q, int data){
    q_node *n = (q_node *)malloc(sizeof(q_node));
    n->next = NULL;
    n->data = data;
    if (emptyQueue(q)) {
        q->front = n;
        q->rear = n;
    }else{
        q->rear->next = n;
        q->rear = n;
    }
}

void queue_pop(Queue *q){
    q_node *n = q->front;
    if (emptyQueue(q)) {
        return;
    }
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
        free(n);
    }else{
        q->front = q->front->next;
        free(n);
    }
}

void print_queue(Queue *q){
    q_node *n = q->front;
    while (n) {
        printf("queue---%d \n",n->data);
        n = n->next;
    }
}

circle_queue *init_circle_queue(void){
    circle_queue *q = (circle_queue *)malloc(sizeof(circle_queue));
    if (q == NULL) {
        printf("circle_queue error: apply error");
        exit(0);
    }
    q->front = 0;
    q->rear = 0;
    return q;
}

void circle_queue_push(circle_queue *q, int data){
    if ((q->rear + 1) % maxsize == q->front) {
        printf("circle_queue error: can not push");
    }else{
        q->rear = (q->rear + 1) % maxsize;
        q->data[q->rear] = data;
    }
}
void circle_queue_pop(circle_queue *q){
    if (q->rear == q->front) {
        printf("circle_queue error: can not pop");
    }else{
        q->data[q->front] = 0;
        q->front=(q->front + 1)%maxsize;
    }
}

void print_circle_queue(circle_queue *q){
    int i = q->front;
    while (q->rear != i) {
        i=(i + 1)%maxsize;
        printf("circle-queque---%d \n",q->data[i]);
    }
}

void load_queue(void){
    Queue *q = init_queue();
    circle_queue * queue = init_circle_queue();
    int input[5] = {21,22,23,24,25};
    for (int i = 0; i < 5; i ++) {
        queue_push(q, input[i]);
        circle_queue_push(queue, input[i]);
    }
    print_queue(q);
    queue_pop(q);
    print_queue(q);
    
    print_circle_queue(queue);
    circle_queue_pop(queue);
    print_circle_queue(queue);
}



