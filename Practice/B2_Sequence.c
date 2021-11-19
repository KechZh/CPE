#include <stdio.h>

int main(){
    int ncase = 1;
    int n;

    while(scanf("%d", &n) != EOF){
        int b[100];
        int count[20010] = {0};
        int flag = 1;

        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        for(int i = 0; i < n; i++)
            if(b[i] < 1){
                flag = 0;
                break;
            }

        for(int i = 0; i < n - 1; i++)
            if(i < n - 1 && b[i] >= b[i+1]){
                flag = 0;
                break;
            }

        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                count[b[i] + b[j]]++;

        for(int i = 0; i < 20010; i++)
            if(count[i] > 1){
                flag = 0;
                break;
            }

        if(flag)
            printf("Case #%d: It is a B2-Sequence.\n\n", ncase);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n", ncase);

        ncase++;
    }

    return 0;
}