//
//  Tong_Link.h
//  Tong-C
//
//  Created by Tongle on 2021/7/13.
//

#ifndef Tong_Link_h
#define Tong_Link_h

#include <stdio.h>
/**
 ⚠️⚠️⚠️⚠️⚠️⚠️⚠️ 单向链表
 */

typedef struct Link{
    char elem;    // 代表数据域
    struct Link *next;     //代表指针域，指向直接后继元素
}link;

/**
 初始化链表
 */
link * initLink(void);

/**
 插入元素
 */
link * insertElem(link *p, int elem, int add);

/**
 删除元素
 */
link * deleteElem(link *p, int add);

/**
 查找元素
 */

int selectElem(link *p, int elem);

/**
 更新元素
 */
link *amendElem(link *p, int add, int newElem);

void display(link *p);




#endif /* Tong_Link_h */
