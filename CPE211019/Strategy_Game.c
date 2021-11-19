#include <stdio.h>
#include <string.h>

#define MAX 510

int p, r;
int sum[MAX];
int winner;
int max_sum;
int tmp;

void init(){
    memset(sum, 0, sizeof(sum));
    winner = max_sum = 0;
}

int main(){
    while(scanf("%d%d", &p, &r) != EOF){
        init();

        for(int i = 0; i < r; i++)
            for(int j = 1; j <= p; j++){
                scanf("%d", &tmp);
                sum[j] += tmp;
            }

        for(int i = 1; i <= p; i++)
            if(sum[i] >= max_sum){
                winner = i;
                max_sum = sum[i];
            }

        printf("%d\n", winner);
    }

    return 0;
}