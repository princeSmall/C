//
//  Tong_GreedyAlgorithm.c
//  Tong-C
//
//  Created by PrinceSmall on 2021/8/19.
//

#include "Tong_GreedyAlgorithm.h"
#include <string.h>
#include <math.h>

//发薪水
int calculateSalary(int salary){
    int temp = salary;
    int count = 0;
    while (temp != 0) {
        if (temp >= 100) {
            count += temp / 100;
            temp = temp % 100;
            
        }else if (temp >= 50){
            count += temp / 50;
            temp = temp % 50;
            
        }else if (temp >= 10){
            count += temp / 10;
            temp = temp % 10;
            
        }else if (temp >= 5){
            count += temp / 5;
            temp = temp % 5;
           
        }else if (temp >= 2){
            count += temp / 2;
            temp = temp % 2;
            
        }else {
            count += temp / 1;
            temp = temp % 1;
        }
    }
    return count;
}


//翻硬币
int minCount(char one[], char two[]){
    int count = 0;
    for (int i = 0; i < strlen(one); i ++) {
        if (i + 1 < strlen(one)) {
            if (one[i] != two[i]) {
                if (one[i + 1] != two[i +1]) {
                    count += 1;
                    i++;
                }else{
                    char temp[] = "*";
                    char tempO[] = "o";
                    if (one[i + 1] == temp[0]) {
                        one[i + 1] = tempO[0];
                    }else{
                        one[i + 1] = temp[0];
                    }
                    count += 1;
                }
            }
        }
        
    }
    return count;
}

// 冒泡排序
void maoPao(int tree[], int count){
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j ++) {
            if (tree[i] > tree[j]) {
                int temp = tree[i];
                tree[i] = tree[j];
                tree[j] = temp;
            }
        }
    }
}


//哈夫曼树总费用
int huffmanTree(int tree[], int count){
    int totalPrice = 0;
    int length = count;
    for (int m = 0; m < count-1; m ++) {
        maoPao(tree, length);
        for (int n = 0; n < length -1; n ++) {
            if (n == 0) {
                tree[0] = tree[0] + tree[1];
                totalPrice += tree[0];
            }else{
                tree[n] = tree[n + 1];
            }
        }
        length--;
    }
    return totalPrice;
}





void load_greedyAlogorithm(void){
    
    int count = calculateSalary(121);
    printf("贪心算法薪水-%d \n",count);
    //    *o**o***o***
    //    *o***o**o***
    
    char one[] = "***o***o**";
    char two[] = "*o***o****";
    
    int minCoun = minCount(one, two);
    printf("贪心算法翻硬币-%d \n",minCoun);
    
    int tree[5] = {5,3,8,2,9};
    int totalPrice = huffmanTree(tree, 5);
    printf("贪心算法huffman树的总费用-%d \n",totalPrice);
}
