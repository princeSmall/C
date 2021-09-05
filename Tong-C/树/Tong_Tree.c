//
//  Tong_Tree.c
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/23.
//

#include "Tong_Tree.h"
#include <stdlib.h>

void insert(Tree *tree, int value){
    
    Tree_Node *node = (Tree_Node *)malloc(sizeof(Tree_Node));
    node->data = value;
    node->right = NULL;
    node->left = NULL;
    
    if (tree->root == NULL) {
        tree->root = node;
    }else{
        Tree_Node *temp = tree->root;
        while (temp != NULL) {
            if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                }else{
                    temp = temp->left;
                }
            }else{
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
}

/**
 中序遍历
 In-Order
 */
void innorder(Tree_Node *node){
    if (node != NULL) {
        innorder(node->left);
        printf("tree---%d \n",node->data);
        innorder(node->right);
    }
}

void load_tree(void){
    Tree tree;
    tree.root = NULL;
    int n[7] = {5,2,6,1,3,4,8};
    for (int i = 0; i < 7; i ++) {
        insert(&tree, n[i]);
    }
    innorder(tree.root);
    
}
