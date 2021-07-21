//
//  main.c
//  Tong-C
//
//  Created by Tongle on 2021/7/12.
//

#include <stdio.h>
#include "Tong_Table.h"
#include "Tong_Link.h"
#include "Tong_Component.h"
#include "Tong_Line.h"
#include "Tong_Stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    双向链表
    loadLine();
//    栈
    load_stack();
    
    component array[6];
    int body = initArr(array);
    printf("静态链表为：\n");
    displayArr(array, body);
    
    link * a = initLink();
    display(a);
    
    a = insertElem(a, 8, 2);
    display(a);
    
    a = deleteElem(a, 3);
    display(a);
    
    a = amendElem(a, 2, 9);
    display(a);
    
    int i = selectElem(a, 8);
    
    printf("%d \n",i);
    

    
    
    table t1 = initTable();
    for (int i=1; i<=5; i++) {
           t1.head[i-1]=i;
           t1.length++;
       }
       printf("原顺序表：\n");
       displayTable(t1);
    t1 = addTable(t1, 5, 2);
    displayTable(t1);
    
    t1 = amendTable(t1, 2, 10);
    displayTable(t1);
    return 0;
}
