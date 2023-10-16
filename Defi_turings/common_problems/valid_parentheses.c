#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    char token;
    struct stack *over;
    struct stack *under;
    
};

bool isValid(char * s){
    struct stack *st = malloc(sizeof(struct stack));
    st->token = '$';
    // iterate over the string
    for(; *s; ++s){
        if (*s=='{'||*s=='('||*s=='['){
            if (!st->over)  // allocate memo if not present
                st->over = (struct stack*)malloc(sizeof(struct stack));
            st->over->under = st;
            st = st->over;
            st->token = (*s=='(')? ')': (*s=='{')? '}': ']';
            
        } else {
            // check if it matches with the top of the stack;
            if (st->token==*s)
                st = st->under;
            else
                return false;
        }
    }
    return st->token=='$';
}
int main(){
    printf("%d\n", isValid("((()))"));
}