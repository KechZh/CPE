#include <stdio.h>

int main(){
    int time[10010] = {0};
    int now = 0, bound = 1;
    int ncase = 1;
    int n;

    for(int i = 1; i < 10010; i++){
        time[i] = now;
        if(i == bound){
            now++;
            bound *= 2;
        }
    }

    while(1){
        scanf("%d", &n);

        if(n < 0)
            break;

        printf("Case %d: %d\n", ncase++, time[n]);
    }

    return 0;
}