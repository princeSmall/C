//
//  Tong_Link.c
//  Tong-C
//
//  Created by Tongle on 2021/7/13.
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
    printf("\n");
    
}
