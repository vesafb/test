#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node * prev, * next;
};

struct Node * insert(struct Node * l, int d)
{
   struct Node * tmp = (struct Node*)malloc(sizeof(struct Node));
   tmp->data = d;
   if(l != NULL) {
     tmp->next = l;
     l->prev = tmp;
   } else {
     tmp->next = NULL;
   }
   tmp->prev = NULL;
   return tmp;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

struct Node * partition(struct Node *l, struct Node * h) {
  int pivot = h->data;
  struct Node * i = l->prev;
  for(struct Node * j = l; j != h; j = j->next) {
    if(j->data <= pivot) {
      i = (i == NULL)? l : i->next;
      swap(&i->data, &j->data);
    }
  }
  swap(&i->next->data, &h->data);
  return i->next; 
}

void my_qsort(struct Node *l, struct Node * h) {
  if(h != NULL && l != h && l != h->next) {
    struct Node * p = partition(l, h);
    my_qsort(l, p->prev);
    my_qsort(p->next, h); 
  }
}

int main() {
  struct Node  * l;
  l = insert(l, 2); l = insert(l, 4); l = insert(l, 1); l = insert(l, 3); l = insert(l, 5); l = insert(l, 4);
  struct Node * h = l;
  while(h->next) h=h->next;
  my_qsort(l, h);
  for(struct Node * i = l;i != NULL; i = i->next) {
    printf("%d ", i->data);
  }
}
