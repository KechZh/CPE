#include <stdio.h>

long long coordinate_to_step(int x, int y){
    long long length, step;

    length = x + y;
    step = length * (length + 1) / 2 + x;

    return step;
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    for(int i = 1; i <= ncase; i++){
        int src_x, src_y, dst_x, dst_y;
        long long step;

        scanf("%d%d%d%d", &src_x, &src_y, &dst_x, &dst_y);

        step = coordinate_to_step(dst_x, dst_y) - coordinate_to_step(src_x, src_y); 

        printf("Case %d: %lld\n", i, step);
    }

    return 0;
}