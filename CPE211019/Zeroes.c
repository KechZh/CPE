#include <stdio.h>

long long low, high;

int main(){
    while(scanf("%lld%lld", &low, &high) && (low != 0 || high != 0))
        printf("%lld\n", (high / 5) - (low / 5) + 1);

    return 0;
}