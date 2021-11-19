#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];

    while(fgets(str, 1000, stdin) != NULL){
        str[strlen(str) - 1] = 0;

        for(int i = 0; i < strlen(str); i++)
            str[i] -= 7;

        printf("%s\n", str);
    }

    return 0;
}