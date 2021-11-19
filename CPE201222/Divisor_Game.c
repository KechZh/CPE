#include <stdio.h>

#define MAX 1000010

int divisor[MAX] = {0}, ans[MAX] = {0}, max_div[MAX] = {0};

void create_table(){
    for(int i = 1; i < MAX; i++)
        for(int j = i; j < MAX; j += i)
            divisor[j]++;

    for(int i = 1; i < MAX; i++){
        if(divisor[i] >= max_div[i-1]){
            ans[i] = i;
            max_div[i] = divisor[i];
        }
        else{
            ans[i] = ans[i-1];
            max_div[i] = max_div[i-1];
        }
    }
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    create_table();

    while(ncase--){
        int n;

        scanf("%d", &n);

        printf("%d\n", ans[n]);
    }

    return 0;
}