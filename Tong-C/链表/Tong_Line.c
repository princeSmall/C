//
//  Tong_Line.c
//  Tong-C
//
//  Created by Tongle on 2021/7/15.
//

#include "Tong_Line.h"

line *initLine(void){
    line *temp = NULL;
    line *head = (line *)malloc(sizeof(line));
    if (head == NULL) {
        exit(0);
    }
    temp = head;
    head->pre = NULL;
    head->next = NULL;
    for (int i = 1; i < 5; i ++) {
        line * a = (line *)malloc(sizeof(line));
        if (a == NULL) {
            exit(0);
        }
        a->data = i;
        a->next = NULL;
        a->pre = temp;
        temp->next = a;
        temp = temp->next;
    }
    return head;
}

void displayLine(line *head){
    line  * l = head;
    int position = 1;
    while (l) {
        printf("Line---%d-->%d \n",position++,l->data);
        printf("\n");
        l=l->next;
    }
    printf("\n");
}

line * insertLine(line *head, int data, int add){
    line *temp = (line *)malloc(sizeof(line));
    if (temp==NULL) {
        exit(0);
    }
    temp->data = data;
    temp->pre = NULL;
    temp->next = NULL;
    if (add == 1) {
        temp->next=head;
        head->pre = temp;
        head=temp;
    }else{
        line *body = head;
        for (int i = 1; i < add -1; i++) {
            body = body->next;
        }
        if (body->next == NULL) {
            body->next =temp;
            temp->pre = body;
        }else{
            body->next->pre = temp;
            temp->next = body->next;
            body->next = temp;
            temp->pre = body;
        }
    }
    return head;
}

line * deleteLine (line *head, int data){
    line *l = head;
    while (l){
        if (l->data == data) {
            l->next->pre = l->pre;
            l->pre->next = l->next;
            printf("删除成功 \n");
            return head;
        }
    l = l->next;
    }
    printf("链表中无此元素 \n");
    return head;
}

line *updateLine (line *head, int data, int newData){
    line *l = head;
    while (l) {
        if (l->data == data) {
            l->data = newData;
            printf("更新成功 \n");
            return head;
        }
        l = l->next;
    }
    return head;
}


void loadLine(void){
    line *p = initLine();
    displayLine(p);
    p = insertLine(p, 8, 3);
    displayLine(p);
    p = deleteLine(p, 3);
    displayLine(p);
    
    p = updateLine(p, 4, 7);
    displayLine(p);
}





