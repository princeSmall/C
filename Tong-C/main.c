//
//  main.c
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/12.
//

#include <stdio.h>
#include "Tong_Table.h"
#include "Tong_Link.h"
#include "Tong_Component.h"
#include "Tong_Stack.h"
#include "Tong_Queue.h"
#include "Tong_Tree.h"
#include "Tong_GreedyAlgorithm.h"

#include <math.h>

int swap(int *a,int *b)
{
    if (*a!=*b)
    {
        *a=*a^*b;
        *b=*b^*a;
        *a=*a^*b;
    }
    return 0;
}

double twoPointLength(int array[]){
    if (array[0] == array[2]) {
        return array[1] > array[3] ? array[1] : array[3];
    }else if (array[1] == array[3]){
        return array[0] > array[2] ? array[0] : array[2];
    }else{
        return hypot(array[2]-array[0], array[3]-array[1]);
    }
}

double hypotMethod(double i, double j){
    return sqrt(i * i + j * j);
}

int huffumanTree(void){
    int arr[5] = {5,3,8,2,9};
   
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp =arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        
        printf("%d \n",arr[i]);
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");

//    int huff = huffumanTree();
    load_greedyAlogorithm();
    int arr[4] = {0,0,1,1};
    double arrLength = twoPointLength(arr);
    printf("--%.2f \n",arrLength);
    
    
    int a=5;
    int b=3;
//  a=  0101
//  b=  0011
//    1.    a = 0110
//          b = 0011
    
//    2.    b = 0101
//          a = 0110
    
//    3     a = 0011
//          b = 0101
    swap(&a,&b);
    printf("a=%d b=%d\n",a,b);
    
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
//    树
    load_tree();
    
    return 0;
}
