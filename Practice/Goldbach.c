#include <stdio.h>

int main(){
    int prime[40000] = {0};

    for(int i = 2; i < 40000; i++)
        prime[i] = 1;

    for(int i = 0; i < 40000; i++)
        if(prime[i])
            for(int j = i*2; j < 40000; j += i)
                prime[j] = 0;

    while(1){
        int num;
        int ans = 0;

        scanf("%d", &num);

        if(num == 0)
            break;

        for(int i = 0; i <= num/2; i++)
            if(prime[i] && prime[num-i])
                ans++;

        printf("%d\n", ans);
    }

    return 0;
}