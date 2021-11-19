#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    
    while(scanf("%d", &n) != EOF){
        int num[3010];
        int diff[3010] = {0};
        int jolly = 1;

        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);

        for(int i = 1; i < n; i++){
            int tmp = abs(num[i] - num[i-1]);
            diff[tmp]++;
        }

        for(int i = 1; i < n; i++)
            if(diff[i] != 1)
                jolly = 0;

        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}