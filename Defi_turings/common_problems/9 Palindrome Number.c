#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct biListNode{
    int val;
    struct biListNode* next;
    struct biListNode* prev;
};

bool isPalindrome(int x){
    if (x==0)
        return true;
    if (x<0)
        return false;
    struct biListNode* digits = malloc(sizeof(struct biListNode));
    struct biListNode* p = digits;
    int i=0, j=-1;
    while (x){
        p->val = x%10;
        x /= 10;
        if (x){
            p->next = (struct biListNode*)malloc(sizeof(struct biListNode));
            p->next->prev = p;
            p = p->next;
        } else
            p->next = digits;
        j++;
    }
    while ((p->val==digits->val)&&(i<j)){
        p = p->prev;
        digits = digits->next;
        i++; j--;
    }
    if ((i>=j))
        return true;
    else
        return false;
}

int main(){
    printf("%d\n", isPalindrome(10));
}