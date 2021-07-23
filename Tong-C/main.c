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
#include "Tong_Stack.h"
#include "Tong_Queue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    //    顺序表
    load_table();
    //    链表
    load_link();
    //    栈
    load_stack();
    //    队列
    load_queue();
    //    静态链表
    load_component();
    
    return 0;
}
