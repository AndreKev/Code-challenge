# include<stdio.h>
// ListNode Definition
struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 && list2){
        struct ListNode *p, *q, *k;
        if (list1->val<=list2->val){
            p = list1;
            q = list2;
            char plead = 1;
        } else {
            p = list2;
            q = list1;
            char plead = 0;
        }

        while (p&&q){
                if (p->next){
                    if (p->next->val<=q->val)
                        p = p->next;
                    else{
                        k = p->next;
                        p->next = q;
                        p = k;
                        k = q; q = p; p = k;  // switch p and q;
                    }
                } else{
                    p->next = q;
                    q = NULL;
                }
            if (p->val<=q->val)
                p = p->next;
            else{
                
            }
        }
        return (plead)? list1: list2;
        
    }
    // One of the two is empty or both
    if (list1)
        return list1;
    else if (list2)
        return list2;
    else
        return list1;
}