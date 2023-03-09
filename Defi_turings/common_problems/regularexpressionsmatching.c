#include <stdio.h>

struct GraphNode{
    char letter = "\0";
    struct GraphNode* lson;
    struct GraphNode* rson;
}

void insertchar(struct GraphNode* G, char *s, char *p, int i, int j, char empty){
    if (p[j]=='\0'&&s[i]=='\0')
        return 1;
    else if (p[j]&&!s[i])
        return 0;
    else if (s[i]&&!p[j])
        return 0;
    else{

    }
}

int isMatch(char *s, char *p){
    
}


int isMath(char *s, char *p){
    struct GraphNode* G;
}

int isMatch(char *s, char *p){
    int i=0,j=0;
    while (p[j]){
        if (p[j]=='*'){
            
        } else if (s[i]!=p[j])
            if (p[++j]!='*')
                return 0;
            else ++j;
        else
            if (p[++j]=='*')
                continue;
            else{
                i++;
            }
    }
}


int isMatch2(char * s, char * p){
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
    char s[] = "aab";
    char p[] = "aab";
    printf("%d\n", isMatch2(s, p));
}