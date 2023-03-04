#include <stdio.h>

void charshow(char*s, int begin, int end){
    for (int i=begin; i<end+1; i++)
        printf("%c", s[i]);
    printf("\n");
}

int lengthOfLongestSubstring(char * s){
    int occurence[26];
    int start, end, pos, length=0, temp_length;
    char a = 'a';
    start = end = 0;
    while (s[end]!='\0'){
        pos = (int)s[end]-a;  // The index of the character s[end]
        if (occurence[pos]){ // Current character already seen  -- end of substring
            temp_length = end-start;
            if (temp_length>length)
                length = temp_length;  // Save the max
            while (s[start]!=s[end]){
                //charshow(s, start, end);
                pos = (int)s[start]-a;
                occurence[pos]--;
                start++;   
            }
            start++;
        } else{
            occurence[pos]++;
        }
        end++;
    }
    temp_length = end - start;
    if (temp_length>length) 
        return temp_length;
    else return length;
}

int main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
}
