#include <stdio.h>

int in(char c, char *s){
    for (int k=0; s[k]!='\0'; k++){
        if (s[k]==c)
            return k;
    }
    return -1;
}

int myAtoi(char *s){
    char digs[] = "0123456789";
    char sign; int start=0; int end, digit;
    long long number = 0;
    for (; s[start]; start++)
        if (s[start]!=' ')
            break;
    if (!(s[start]))
        return 0;
    else{
        if (in(s[start], digs)>-1){
            sign = '+';
        }
        else if (s[start]=='-'){
            sign = '-';
            start++;
        } else if (s[start]=='+'){
            sign = '+';
            start++;
        } else
            return 0;
        //
        for (; s[start]=='0'; start++);
        // 
        if (s[start]&&in(s[start], digs)){
            end = start;
            for(; (digit=in(s[end], digs))>-1; end++){
                if (end-start+1<11)
                    number = number*10 + digit;
                else
                    return (start>0 && sign=='-')? -2147483648: 2147483647;  
            }
            if (start>0 && sign=='-'){
                number = -number;
                if (number<-2147483648)
                    return -2147483648;
                else
                    return number;
            } else{
                if (number>2147483647)
                    return 2147483647;
                else
                    return number;
            }   
        } else return 0;
    }
}

int main(){
    char string[] = "-01-42a";
    printf("%d\n", myAtoi(string));
}