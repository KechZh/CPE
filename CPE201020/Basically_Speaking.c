#include <stdio.h>
#include <string.h>

int main(){
    char str[10];
    int b1, b2;

    while(scanf("%s%d%d", str, &b1, &b2) != EOF){
        long long dec = 0;
        long long base = 1;

        for(int i = strlen(str) - 1; i >= 0; i--){
            if(str[i] >= '0' && str[i] <= '9')
                dec += (str[i] - '0') * base;
            else if(str[i] >= 'A' && str[i] <= 'F')
                dec += (str[i] - 'A' + 10) * base;

            base *= b1;
        }

        if(dec == 0){
            printf("      0\n");
            continue;
        }

        for(int i = 6; i >= 0; i--){
            if(dec > 0){
                int tmp = dec % b2;

                if(tmp >= 0 && tmp <= 9)
                    str[i] = tmp + '0';
                else
                    str[i] = tmp - 10 + 'A';

                dec /= b2;
            }
            else
                str[i] = ' ';
        }

        if(dec == 0)
            printf("%s\n", str);
        else
            printf("  ERROR\n");
    }

    return 0;
}