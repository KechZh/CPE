#include <stdio.h>

int gcd(int a, int b){
    while(b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){
    int gcd_sum[510] = {0};

    for(int i = 1; i < 510; i++){
        gcd_sum[i] = gcd_sum[i-1];

        for(int j = 1; j < i; j++)
            gcd_sum[i] += gcd(i, j);
    }

    while(1){
        int n;
        scanf("%d", &n);

        if(n == 0)
            break;

        printf("%d\n", gcd_sum[n]);
    }

    return 0;
}