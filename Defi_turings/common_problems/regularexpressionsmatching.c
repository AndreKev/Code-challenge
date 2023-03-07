#include <stdio.h>
int isMatch(char * s, char * p){
    int i =0, j=0;
    while (p[j]){
        if (p[j]=='.'){
            if (s[i])
                i++;
            else
                return 0;
            j++;
        } else if (p[j]=='*'){
            j--;
            if (p[j]!='.')
                while (s[i]==p[j])
                    i++;
            else
            j+=2;
        } else if (s[i]!=p[j]&&p[j+1]!='*')
            return 0;
        else{
            i++; j++;
        }
    }
    return (s[i]==p[j]);
}

int main(){
    char s[] = "aa";
    char p[] = "b*a*a*";
    printf("%d\n", isMatch(s, p));
}