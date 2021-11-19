#include <stdio.h>
#include <string.h>

int main(){
    char str[110][110] = {{0}};
    int count = 0;
    int max_length = 0;

    while(fgets(str[count], 110, stdin)){
        str[count][strlen(str[count]) - 1] = 0;
        max_length = strlen(str[count]) > max_length ? strlen(str[count]) : max_length;

        count++;
    }

    for(int i = 0; i < max_length; i++){
        for(int j = count - 1; j >= 0; j--){
            if(str[j][i] > 0)
                printf("%c", str[j][i]);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}