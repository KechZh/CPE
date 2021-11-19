#include <stdio.h>

int compute_ones_of_binary(int n){
    int ones = 0;

    while(n > 0){
        ones += n % 2;
        n /= 2;
    }

    return ones;
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int n;
        int b1, b2 = 0;

        scanf("%d", &n);

        b1 = compute_ones_of_binary(n);

        while(n > 0){
            b2 += compute_ones_of_binary(n % 10);
            n /= 10;
        }

        printf("%d %d\n", b1, b2);
    }

    return 0;
}