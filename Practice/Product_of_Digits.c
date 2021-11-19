#include <stdio.h>

int main(){
    int ncase;
    scanf("%d", &ncase);

    while(ncase--){
        int n;
        int pow[10] = {0};

        scanf("%d", &n);

        if(n == 1){
            printf("1\n");
            continue;
        }

        for(int i = 9; i >= 2; i--)
            while(n % i == 0){
                pow[i]++;
                n /= i;
            }

        if(n == 1){
            for(int i = 2; i <= 9; i++)
                for(int j = 0; j < pow[i]; j++)
                    printf("%d", i);
            printf("\n");
        }
        else
            printf("-1\n");
    }

    return 0;
}