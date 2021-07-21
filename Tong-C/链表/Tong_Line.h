//
//  Tong_Line.h
//  Tong-C
//
//  Created by Tongle on 2021/7/15.
//

#ifndef Tong_Line_h
#define Tong_Line_h

#include <stdio.h>
#include <stdlib.h>

/**
 ⚠️⚠️⚠️⚠️⚠️⚠️⚠️ 双向链表
 */

typedef struct Line{
    int data;
    struct Line *pre;
    struct Line *next;
}line;
//分别表示该结点的前驱(pre)，后继(next)，以及当前数据(data)

/**
 初始化链表
 */
line *initLine(void);

line *updateLine (line *head, int data, int newData);

line * deleteLine (line *head, int data);

line * insertLine(line *head, int data, int add);

void displayLine(line *head);

void loadLine(void);




#endif /* Tong_Line_h */
