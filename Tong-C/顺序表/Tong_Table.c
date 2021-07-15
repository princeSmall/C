//
//  Tong_Table.c
//  Tong-C
//
//  Created by Tongle on 2021/7/12.
//

#include "Tong_Table.h"
#define Size 5

table initTable(void){
    table t;
    t.head=(int*)malloc(Size*sizeof(int));
    if (!t.head){
        printf("初始化失败\n");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}
table addTable(table t, int elem, int add){
    if (add > t.length + 1 || add < 1) {
        printf("插入位置有问题\n");
        return t;
    }
    if (t.length >= t.size) {
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int));
        if (!t.head) {
            printf("存储分配失败\n");
        }
        t.size +=1;
    }
    for (int i = t.length -1;i >=add - 1 ; i--) {
        t.head[i + 1] = t.head[i];
    }
    t.head[add - 1]=elem;
    t.length ++;
    return t;
}

table delTable(table t, int add){
    if (add > t.length + 1 || add < 1) {
        printf("被删除元素位置有问题\n");
        return t;
    }
    for (int i = add; i <t.length; i++) {
        t.head[i -1] = t.head[i];
    }
    t.length --;
    
    return t;
}

int selTable(table t, int elem){
    for (int i = 0; i < t.length ; i ++) {
        if (t.head[i] == elem) {
            return i+1;
        }
    }
    return -1;
}

table amendTable(table t, int elem ,int newElem){
    for (int i = 0; i < t.length ; i ++) {
        if (t.head[i] == elem) {
            t.head[i] = newElem;
        }
    }
    return t;
}

void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("--%d ",t.head[i]);
    }
    printf("\n");
}
