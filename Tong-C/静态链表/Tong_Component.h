//
//  Tong_Component.h
//  Tong-C
//
//  Created by Tongle on 2021/7/13.
//

#ifndef Tong_Component_h
#define Tong_Component_h

#include <stdio.h>

typedef struct {
    int data;
    int cur;
}component;
/**
 将结构体数组中所有分量链接到备用链表中
 */
void reserveArr(component *array);
/**
 初始化静态链表
 */
int initArr(component *array);
/**
 输出函数
 */
void displayArr(component *array, int body);
/**
 从备用链表上摘下空闲节点的函数
 */
int mallocArr(component *array);

#endif /* Tong_Component_h */
