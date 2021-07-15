//
//  Tong_Component.c
//  Tong-C
//
//  Created by Tongle on 2021/7/13.
//

#include "Tong_Component.h"

#define maxSize 6

void reserveArr(component *array){
    for (int i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;
        array[i].data = -1;
    }
    array[maxSize -1].cur = 0;
}

int mallocArr(component *array){
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}

int initArr(component *array){
    reserveArr(array);
    int body = mallocArr(array);
    int tempBody= body;
    for (int i = 1; i < 4 ; i++) {
        int j = mallocArr(array);
        array[tempBody].cur = j;
        array[j].data = i;
        tempBody = j;
    }
    array[tempBody].cur = 0;
    return body;
}

void displayArr(component *array, int body){
    int tempBody = body;
    while (array[tempBody].cur) {
        printf("%d, %d \n",array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("--%d, %d \n",array[tempBody].data,array[tempBody].cur);
    
}
