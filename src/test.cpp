#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct BinaryNode{
    char value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode, *BTree;

void levelInput(BTree root, BTree n) {
    if(!root) return;
    queue<BTree> q;
    BTree tmp;
    q.push(root);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp->left){  
            q.push(tmp->left);  
        } else {
           tmp->left = n;
           break;
        } 
        if(tmp->right){  
           q.push(tmp->right);  
        } else {
           tmp->right = n;
           break;
        } 
    }  
}

void levelPrint(BTree root) {
  if(!root) return;
  queue<BTree> q;
  BTree tmp;
  q.push(root);
  while(!q.empty()){
    tmp = q.front();
    q.pop();
    cout << tmp->value << ' ';  
    if(tmp->left){  
        q.push(tmp->left);  
    }  
    if(tmp->right){  
        q.push(tmp->right);  
    }  
  }  
}

void heapAdjust(int arr[], int len, int index)
{
    int l = 2*index + 1;
    int r = 2*index + 2;
    int i = index;
    if(l < len && arr[l] > arr[i]) i = l;
    if(r < len && arr[r] > arr[i]) i = r;
    if(i != index)
    {
        swap(arr[i], arr[index]);
        heapAdjust(arr, len, i);
    }
}

int main() {
  BTree t = NULL;
  int arr[1000];
  int len = 0;
  while(true) {
    char c = getchar();
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
      BTree tmp = (BTree)malloc(sizeof(BinaryNode));
      tmp->value = c;
      tmp->left = NULL;
      tmp->right = NULL;
      if(t == NULL) {
        t = tmp;
      } else {
        levelInput(t, tmp);
      }
      levelPrint(t);
    } else if (c >= '0' && c <= '9') {
      arr[len] = c;
      swap(arr[0], arr[len]);
      heapAdjust(arr, len, 0);
      len++;
      for(int i = 0; i < len; i++) {
        cout << i << ' ';
      }
    } else {
      levelPrint(t);
      for(int i = 0; i < len; i++) {
        cout << i << ' ';
      }
      break;
    }
  }
  return 0;
}
