#include <stdio.h>

long long big_mod(int b, int p, int m){
    if(p == 0)
        return 1;
    else if(p == 1)
        return b % m;
    else{
        if(p % 2 == 0)
            return (big_mod(b, p/2, m) * big_mod(b, p/2, m)) % m;
        else
            return (big_mod(b, p/2, m) * big_mod(b, p/2, m) * (b % m)) % m;
    }
}

int main(){
    int b, p, m;

    while(scanf("%d%d%d", &b, &p, &m) != EOF){
        long long ans = big_mod(b, p, m);

        printf("%lld\n", ans);
    }
}