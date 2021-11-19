#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char c[40];
    char exp[26] = "22233344455566677778889999";

    while(fgets(c, 40, stdin) != NULL){
        c[strlen(c) - 1] = 0;
        
        for(int i = 0; i < strlen(c); i++)
            if(isupper(c[i]))
                c[i] = exp[c[i] - 'A'];

        printf("%s\n", c);
    }

    return 0;
}