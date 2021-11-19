#include <stdio.h>

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int soda_bot, empty_bot, req;
        int sum = 0;

        scanf("%d%d%d", &soda_bot, &empty_bot, &req);

        while(soda_bot + empty_bot >= req){
            int tmp1 = (soda_bot + empty_bot) / req;
            int tmp2 = (soda_bot + empty_bot) % req;

            soda_bot = tmp1;
            empty_bot = tmp2;

            sum += tmp1;
        }

        printf("%d\n", sum);
    }

    return 0;
}