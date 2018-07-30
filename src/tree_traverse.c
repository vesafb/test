#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>

typedef struct BinaryNode{
    char value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode, *BinaryTree;

int CreateBinaryTree(BinaryTree &T, char *charArray, int *index, int length){
    if (*index>=length) {
        return 0;
    }
    char value =charArray[*index];
    //printf("%c",value);
    if ('*'==value) {
        T=NULL;
    }else{
        T=(BinaryTree)malloc(sizeof(BinaryNode));
        T->value=value;
        *index=*index+1;
        CreateBinaryTree(T->left, charArray, index, length);
        *index=*index+1;
        CreateBinaryTree(T->right, charArray, index, length);
    }
    return 1;
}

void PreorderRecursionTraversal(BinaryTree T){
    if (NULL != T) {
        printf("%c ",T->value);
        PreorderRecursionTraversal(T->left);
        PreorderRecursionTraversal(T->right);
    }
}

void PreorderTraversal(BinaryTree T){
    std::stack<BinaryTree> stack;
    BinaryTree p = T;
    while(NULL != p || !stack.empty()) {
        if(NULL != p) {
            stack.push(p);
            printf("%c ",p->value);
            p = p->left;
        } else {
            p = stack.top();
            stack.pop();
            p = p->right;
        }
    }
}


void InorderRecursionTraversal(BinaryTree T){
    if (NULL != T) {
        InorderRecursionTraversal(T->left);
        printf("%c ",T->value);
        InorderRecursionTraversal(T->right);
    }
}

void InorderTraversal(BinaryTree T){
    std::stack<BinaryTree> stack;
    BinaryTree p=T;
    while(NULL != p || !stack.empty()) {
        if(NULL != p) {
            stack.push(p);
            p = p->left;
        } else {
            p = stack.top();
            printf("%c ",p->value);
            stack.pop();
            p = p->right;
        }
    }
}

void PostorderRecursionTraversal(BinaryTree T){
    if (NULL != T) {
        PostorderRecursionTraversal(T->left);
        PostorderRecursionTraversal(T->right);
        printf("%c ",T->value);
        
    }
}

void PostorderTraversal(BinaryTree T){
    std::stack<BinaryTree> stack;
    BinaryTree p = T;
    BinaryTree last;
    while(NULL!= p || !stack.empty()) {
        if (NULL != p) {
            stack.push(p);
            p = p->left;
        } else {
            BinaryTree peek = stack.top();
            if(peek->right != NULL && peek->right != last) {
              p = peek->right;
            } else {
              stack.pop();
              printf("%c ", peek->value);
              last = peek;
            }
        }
    }
}

int main() {
  char tmp;
  while(
  char * str = "hello";
  BinaryTree t;
  int i = 0;
  int length = strlen(str);
  CreateBinaryTree(t, str, &i, length);
  PreorderTraversal(t);
  printf("\n");
  InorderTraversal(t);
  printf("\n");
  PostorderTraversal(t);
}
