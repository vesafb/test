#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct ListNode {
  int val;
  ListNode * next;
} * List;

List merge(List l, List r) {
  if(l == NULL) return r;
  if(r == NULL) return l;
  List p, q;
  if(l->val < r->val) {
    p = q = l;
    l = l->next;
  } else {
    p = q = r;
    r = r->next;
  }
  while(l != NULL && r != NULL) {
    if(l->val < r->val) {
      p->next = l;
      l = l->next;
      p = p->next;
    } else {
      p->next = r;
      r = r->next;
      p = p->next;
    }
  }
  if(l != NULL) {
    p->next = l;
  } else {
    p->next = r;
  }
  return q;
}

List msort(List head) {
  List p = head, q = head;
  while(q != NULL && q->next != NULL) {
    p = p->next;
    q = q->next->next;
  } 
  if(p->next == NULL) {
    if(p->val < head->val) {
      head->next = NULL;
      p->next = head;
      head = p;
    }
    return head;
  }
  List r = msort(p->next);
  p->next = NULL;
  List l = msort(head);
  return merge(l, r);
}

int main() {
  List l = (List)malloc(sizeof(ListNode));
  List p = l;
  l->val = 3;
  p->next = (List)malloc(sizeof(ListNode));
  p = p->next;
  p->val = 1;
  p->next = (List)malloc(sizeof(ListNode));
  p = p->next;
  p ->val = 2;
  p->next = (List)malloc(sizeof(ListNode));
  p = p->next;
  p ->val = 7;
  p->next = (List)malloc(sizeof(ListNode));
  p = p->next;
  p ->val = 5;
  p->next = (List)malloc(sizeof(ListNode));
  p = p->next;
  p ->val = 4;
  p->next = NULL;
  l = msort(l);
  while(l != NULL) {
    cout << l->val << endl;;
    l = l->next;
  }
}
