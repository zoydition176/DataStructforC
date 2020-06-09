#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * 
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

int main()
{
    return 1;
}

// 2. 两数相加  two sum
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *q = l1;
    struct ListNode *p = l2;
    struct ListNode *r = (struct ListNode *)malloc(sizeof(struct ListNode));
    r->next = NULL;
    struct ListNode *s = r;
    while (q != NULL || p != NULL)
    {
        if (q->next == NULL || p->next == NULL)
        { //最后一个节点情况
            if (q->next != NULL)
            { //p先结束
                p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                p->next->next = NULL;
                p->next->val = 0;
                r->val = q->val + p->val;
                if ((r->val) >= 10)
                { //节点进位情况
                    r->val = (r->val) % 10;
                    q = q->next;
                    p = p->next;
                    p->val = p->val + 1;
                }
                else
                {
                    q = q->next;
                    p = p->next;
                }
                r->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                r = r->next;
                r->next = NULL;
            }
            else if (p->next != NULL)
            { //q先结束
                q->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                q->next->next = NULL;
                q->next->val = 0;
                r->val = q->val + p->val;
                if ((r->val) >= 10)
                { //节点进位情况
                    r->val = (r->val) % 10;
                    q = q->next;
                    p = p->next;
                    q->val = q->val + 1;
                }
                else
                {
                    q = q->next;
                    p = p->next;
                }
                r->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                r = r->next;
                r->next = NULL;
            }
            else
            {
                r->val = q->val + p->val;
                if ((r->val) >= 10)
                { //若最后一个节点需要进位，则需要手动新增一个节点
                    r->val = (r->val) % 10;
                    q = NULL;
                    p = NULL;
                    r->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                    r = r->next;
                    r->val = 1;
                    r->next = NULL;
                }
                else
                { //若最后一个节点不需要进位，则直接结束
                    r->next = NULL;
                    break;
                }
            }
        }
        else
        { //普通节点情况
            r->val = q->val + p->val;
            if ((r->val) >= 10)
            { //节点进位情况
                r->val = (r->val) % 10;
                q = q->next;
                p = p->next;
                q->val = q->val + 1;
            }
            else
            {
                q = q->next;
                p = p->next;
            }
            r->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            r = r->next;
            r->next = NULL;
        }
    }
    return s;
}