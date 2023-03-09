#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void print(struct ListNode* l){
    if (l==NULL)
        printf("Empty\n");
    else{
        struct ListNode* p = l;
        while (p->next!=NULL){
            printf("[%d]->", p->val);
            p = p->next;
        }
        printf("[%d]\n", p->val);
    }
}

int equal(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1=l1, *p2=l2;
    while (p1!=NULL && p2!= NULL){
        if (p1->val!=p2->val)
            return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1==NULL && p2==NULL)
        return 1;
    else
        return 0;
}

struct ListNode* initialize(int value){
    struct ListNode* l;
    l= (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = l;
    while (value){
        p->val = value%10;
        value /= 10;
        if (value){
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
        }
    }
    return l;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
int cache0 = 0;
    struct ListNode* head;
    head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* current = head;

    while (l1||l2){
        cache0 = ((l1!=NULL)? l1->val: 0) + ((l2!=NULL)? l2->val: 0) + cache0;
        // Create new list
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = cache0%10;  
        current = current->next;
        cache0 /=10; 
        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;
    }
    if (cache0){
        current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        current->next->val = cache0;
    }

    return head->next;
}

int main(){
    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *sum;
    l1 = initialize(421);
    l2 = initialize(421);
     
    for (int i= 0; i<10; i++){
        l1 = initialize(i);
        for (int j=i; j<10; j++){
            l2 = initialize(j);
            sum = addTwoNumbers(l1, l2);
            int eq = equal(sum, initialize(i+j));
            printf("%d, %d: %d\t", i, j, eq);
            print(sum);
        }
    }
    return 0;
} 