#include <stdio.h>

int main(){
    int ncase;
    scanf("%d", &ncase);

    for(int i = 0; i < ncase; i++){
        int a, b;
        int sum = 0;

        scanf("%d%d", &a, &b);

        for(int j = a; j <= b; j++)
            if(j % 2 == 1)
                sum += j;

        printf("Case %d: %d\n", i+1, sum);
    }

    return 0;
}