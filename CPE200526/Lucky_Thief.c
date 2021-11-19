#include <stdio.h>

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        long long key, house;

        scanf("%lld%lld", &key, &house);

        printf("%lld\n", ((house - key) + (house - 1)) * key / 2);
    }

    return 0;
}