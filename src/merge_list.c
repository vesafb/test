#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode * merge_list(ListNode *head1, ListNode *head2)
    {
        ListNode *newhead = NULL, *p = NULL;
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        if (head1->val <= head2->val)
        {
            newhead = head1;
            head1 = head1->next;
        } else {
            newhead = head2;
            head2 = head2->next;
        }

        p = newhead;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val <= head2->val)
            {
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            } else {
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }
        }
        if (head1 != NULL)
        {
            p->next = head1;
        }
        if (head2 != NULL)
        {
            p->next = head2;
        }
        return newhead;
    }

    ListNode* sort_list(ListNode *head)
    {
        if (head == NULL || head->next==NULL)//如果没有元素或者只有一个元素，那么就直接退出
            return head;
        ListNode *l = NULL,*r=NULL;
        l = head;
        r = head;
        while (r->next && r->next->next)//找到中间节点
        {
            r = r->next->next;
            l = l->next;
        }

        if (r == head)//如果此时只有两个节点，那么中间节点就是头节点，l=r=head，无限循环，因此特殊判断
        {
            r = r->next;
            l->next = NULL;
            return merge_list(r, l);
        }

        r = sort_list(l->next);//排序后半部分
        l->next = NULL;//注意，一定要把前面从中间节点切断
        l = sort_list(head);//排序前面一部分
        ListNode* temp = merge_list(l, r);//合并两个有序链表
        return temp;
    }

    void printt_list(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
    void insert(ListNode *head,int val)
    {
	    while (head->next)
	    {
		    head = head->next;
	    }
	    head->next = new ListNode(val);
    }
};
int main()
{
Solution test;
ListNode * head = new ListNode(1);
    test.insert(head, 42);
    test.insert(head, 13);
    test.insert(head, 6);
    test.insert(head, 234);
    test.insert(head, 19);
    test.insert(head, 52);
    test.insert(head, 41);
    test.insert(head, 322);
    test.insert(head, 234);
    head=test.sort_list(head);
    test.printt_list(head);
}
