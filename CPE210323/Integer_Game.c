#include <stdio.h>
#include <string.h>

int main(){
    int ncase;

    scanf("%d\n", &ncase);

    for(int i = 0; i < ncase; i++){
        char str[1010];
        int sum = 0;
        int mod0 = 0, mod1 = 0, mod2 = 0;

        fgets(str, 1010, stdin);
        str[strlen(str) - 1] = 0;

        for(int j = 0; j < strlen(str); j++){
            int tmp = str[j] - '0';

            sum += tmp;

            if(tmp % 3 == 0)
                mod0++;
            else if(tmp % 3 == 1)
                mod1++;
            else
                mod2++;
        }

        if(sum % 3 == 0){
            if(mod0 % 2 == 1)
                printf("Case %d: S\n", i+1);
            else
                printf("Case %d: T\n", i+1);
        }

        else if(sum % 3 == 1){
            if(mod1){
                if(mod0 % 2 == 0)
                    printf("Case %d: S\n", i+1);
                else
                    printf("Case %d: T\n", i+1);
            }
            else{
                printf("Case %d: T\n", i+1);
            }
        }

        else{
            if(mod2){
                if(mod0 % 2 == 0)
                    printf("Case %d: S\n", i+1);
                else
                    printf("Case %d: T\n", i+1);
            }
            else{
                printf("Case %d: T\n", i+1);
            }
        }
    }

    return 0;
}