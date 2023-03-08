#include <stdio.h>>

char * intToRoman(int num){
    static char *string[100];
    unsigned char i = 0;
    char div;
    while (num){
        div = num/1000;
        while (div--)
            string[i++] = 'M';
        num %= 1000;
        div = num/100;
        while (div){
            if (div>8){
                string[i++] = 'C';
                string[i++] = 'M';
            } else if (div==4){
                string[i++] = 'C';
                string[i++] = 'D';
            } else if (div<4){
                while (div--){
                    string[i++] = 'C';
                }
            } else { //  if (div>4)
                div -= 5;
                string[i++] = 'D';
                while (div--)
                    string[i++] = 'C';
            }
            div--;
        }
        num %= 100;
        div = num/10;
        while (div){
            if (div>8){
                string[i++] = 'X';
                string[i++] = 'C';
            } else if (div==4){
                string[i++] = 'C';
                string[i++] = 'L';
            } else if (div<4){
                while (div>0){
                    string[i++] = 'X';
                    div--;
                }
            } else { //  if (div>4)
                div -= 5;
                string[i++] = 'L';
                while (div--)
                    {string[i++] = 'X'; printf("%s", string);}
            }
            div--;
        }
        num %= 10;
        div = num;
        if (div){
            if (div>8){
                string[i++] = 'I';
                string[i++] = 'X';
            } else if (div==4){
                string[i++] = 'I';
                string[i++] = 'V';
            } else if (div<4){
                printf("Entered\n");
                while (div>0){
                    printf("hey");
                    string[i++] = 'I';
                    div--;
                }
            } else { //  if (div>4)
                div -= 5;
                string[i++] = 'V';
                string[i++] = 'I';
            }
        }
        num = 0;
    }
    string[i] = '\0';
    return string;
}

int main(){
    intToRoman(3);
    //printf("%s\n", intToRoman(3));
}