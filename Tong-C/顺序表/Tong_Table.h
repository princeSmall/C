//
//  Tong_Table.h
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/12.
//

#ifndef Tong_Table_h
#define Tong_Table_h

#include <stdio.h>
#include <stdlib.h>
/**
 ⚠️⚠️⚠️⚠️  顺序表
 */

typedef struct Table{
    int *head;
    int length;
    int size;
}table;

/**
 初始化顺序表
 */
table initTable(void);

/**
 添加元素
 */
table addTable(table t, int elem, int add);

/**
 删除元素
 */
table delTable(table t, int add);

/**
 查找元素
 */
int selTable(table t, int elem);

/**
 删除元素
 */
table amendTable(table t, int elem ,int newElem);

void displayTable(table t);

void load_table(void);

#endif /* Tong_Table_h */
