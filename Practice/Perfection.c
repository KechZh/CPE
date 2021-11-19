#include <stdio.h>

int main(){
    printf("PERFECTION OUTPUT\n");

    while(1){
        int n;
        int sum = 0;

        scanf("%d", &n);

        if(n == 0)
            break;
        
        for(int i = 1; i <= n/2; i++)
            if(n % i == 0)
                sum += i;
        
        if(n == sum)
            printf("%5d  PERFECT\n", n);
        else if(n > sum)
            printf("%5d  DEFICIENT\n", n);
        else
            printf("%5d  ABUNDANT\n", n);
    }

    printf("END OF OUTPUT\n");

    return 0;
}