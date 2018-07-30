#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode * next;
  ListNode(int v):val(v), next(NULL) {};
};

ListNode *sort_list(ListNode *head) 
{
    if (head == NULL)
        return NULL;

    ListNode *p = head;
    int len = 0;        //get the length of link
    while (NULL != p) {
        p = p->next;
        len ++;
    }

    ListNode *temp = new ListNode(0);
    temp->next = head;
    
    int interval = 1;   //合并子列表的长度
    for (; interval <= len; interval *= 2) {
        ListNode *pre = temp;
        ListNode *first = temp->next;  //两段子列表的起始位置
        ListNode *second = temp->next;

        while (NULL != first || NULL != second) {
            int i = 0;
            while (i < interval && NULL != second) {
                second = second->next; //将second移到第二段子列表的起始处
                i ++;
            }

            int fvisit = 0, svisit = 0; //访问子列表的的次数<interval，保证列表中的元素全部能被访问
            while (fvisit < interval && svisit < interval && NULL != first && NULL != second) {
                if (first->val < second->val) {
                    pre->next = first;
                    pre = first;
                    first = first->next;
                    fvisit ++;
                }
                else {
                    pre->next = second;
                    pre = second;
                    second = second->next;
                    svisit ++;
                }
            }
            while (fvisit < interval && NULL != first) {
                pre->next = first;
                pre = first;
                first = first->next;
                fvisit ++;
            }
            while (svisit < interval && NULL != second) {
                pre->next = second;
                pre = second;
                second = second->next;
                svisit ++;
            }
            pre->next = second;
            first = second;
        }
    }
    ListNode *retResult = temp->next;
    delete temp;
    temp = NULL;
    return retResult;
}

void printt_list(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
}

void insert(ListNode *head, int val)
{
  while (head->next)
  {
    head = head->next;
  }
  head->next = new ListNode(val);
}

int main() {
  ListNode * head = new ListNode(1);
  insert(head, 42);
  insert(head, 13);
  insert(head, 6);
  insert(head, 234);
  insert(head, 19);
  insert(head, 52);
  insert(head, 41);
  insert(head, 322);
  insert(head, 234);
  head = sort_list(head);
  printt_list(head);
}
