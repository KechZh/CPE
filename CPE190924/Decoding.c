#include <stdio.h>

int main(){
    int ncase;

    scanf("%d\n", &ncase);

    for(int i = 1; i <= ncase; i++){
        char c;
        int n;

        printf("Case %d: ", i);

        while(scanf("%c", &c) && c != '\n'){
            scanf("%d", &n);

            while(n--)
                printf("%c", c);
        }

        printf("\n");
    }

    return 0;
}