#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    while(1){
        char str[1010];
        int a = 0, b = 0;
        
        fgets(str, 1010, stdin);
        str[strlen(str) - 1] = 0;

        if(strcmp(str, "0") == 0)
            break;

        for(int i = 0; i < strlen(str); i++){
            if(i % 2 == 0)
                a += str[i] - '0';
            else
                b += str[i] - '0';
        }

        if(abs(a - b) % 11 == 0)
            printf("%s is a multiple of 11.\n", str);
        else
            printf("%s is not a multiple of 11.\n", str);
    }

    return 0;
}