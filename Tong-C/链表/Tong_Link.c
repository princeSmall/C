//
//  Tong_Link.c
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/13.
//

#include "Tong_Link.h"
#include <stdlib.h>


link * initLink(void){
    link * temp = NULL;
    link * p = (link*)malloc(sizeof(link));
    if (p == NULL) {
        printf("申请空间失败");
        exit(0);
    }
    temp = p;
//    尾部插入法
    for (int i = 1; i < 5; i ++) {
        link* a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
//    头部插入法
    for (int i= 6; i < 10; i ++) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = temp->next;
        temp->next = a;
    }
    return p;
}
/**
 p为原链表，elem表示新数据元素，add表示新元素要插入的位置
 */

link * insertElem(link *p, int elem, int add){
    
    link *temp= p;
    //首先找到要插入位置的上一个结点
    for (int i = 0; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

link * deleteElem(link *p, int add){
    link *temp = p;
    for (int i = 0; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

int selectElem(link *p, int elem){
    link * t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i ++;
    }
    return -1;
}

/**
 更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值

 */
link *amendElem(link *p, int add, int newElem){
    link *temp = p;
    temp = temp->next;
    for (int i = 1; i < add; i ++) {
        temp =temp->next;
    }
    temp->elem = newElem;
    return p;
}

void display(link *p){
    link *temp= p;
    while (temp->next) {
        temp = temp->next;
        printf("link-->%d \n",temp->elem);
    }
    
}

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
        l=l->next;
    }
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


void load_link(void){
    link *a = initLink();
    display(a);
    
    a = insertElem(a, 8, 2);
    display(a);
    
    a = deleteElem(a, 3);
    display(a);
    
    a = amendElem(a, 2, 9);
    display(a);
    
    int i = selectElem(a, 8);
    printf("link---%d \n", i);
    
    line *p = initLine();
    displayLine(p);
    p = insertLine(p, 8, 3);
    displayLine(p);
    p = deleteLine(p, 3);
    displayLine(p);
    
    p = updateLine(p, 4, 7);
    displayLine(p);
}
