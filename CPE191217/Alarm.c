#include <stdio.h>

int main(){
    while(1){
        int h1, m1, h2, m2;
        int t1, t2;
        int diff;

        scanf("%d%d%d%d", &h1, &m1, &h2, &m2);

        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;

        t1 = h1 * 60 + m1;
        t2 = h2 * 60 + m2;

        diff = t2 - t1;
        diff = diff >= 0 ? diff : diff + 1440;

        printf("%d\n", diff);
    }

    return 0;
}