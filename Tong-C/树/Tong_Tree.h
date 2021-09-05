//
//  Tong_Tree.h
//  Tong-C
//
//  Created by PrinceSmall on 2021/7/23.
//

#ifndef Tong_Tree_h
#define Tong_Tree_h

#include <stdio.h>

/**
 树的结点
 */
typedef struct Tree_Node{
    int data;
    struct Tree_Node *left;
    struct Tree_Node *right;
}Tree_Node;

/**
 树根
 */
typedef struct {
    Tree_Node *root;
}Tree;

void insert(Tree *tree, int value);

void innorder(Tree_Node *node);

void load_tree(void);

#endif /* Tong_Tree_h */
