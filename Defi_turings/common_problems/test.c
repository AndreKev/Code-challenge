#include <stdio.h>

int main(){
    char s[] = "Hello";
    char *p = s;
    p[1] = 'i';
    printf("%s\n", s);
    return 0;
}