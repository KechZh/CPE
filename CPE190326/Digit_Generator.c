#include <stdio.h>

#define MAX 100010

int gen[MAX] = {0};

int generate(int n){
    int result = n;
    int tmp = n;

    while(tmp > 0){
        result += tmp % 10;
        tmp /= 10;
    }

    return result;
}

void create_table(){
    for(int i = 1; generate(i) < MAX; i++)
        if(gen[generate(i)] == 0)
            gen[generate(i)] = i;
}

int main(){
    int ncase;

    create_table();

    scanf("%d", &ncase);

    while(ncase--){
        int n;

        scanf("%d", &n);

        printf("%d\n", gen[n]);
    }

    return 0;
}