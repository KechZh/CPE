#include <stdio.h>

int main(){
    int i, j;

    while(scanf("%d%d", &i, &j) != EOF){
        int min_value, max_value;
        int max_cycle = 0;

        if(i < j){
            min_value = i;
            max_value = j;
        }
        else{
            min_value = j;
            max_value = i;
        }

        for(int k = min_value; k <= max_value; k++){
            int tmp = k;
            int cycle = 1;

            while(tmp > 1){
                if(tmp % 2 == 0)
                    tmp /= 2;
                else
                    tmp = tmp * 3 + 1;
                cycle++;
            }

            if(cycle > max_cycle)
                max_cycle = cycle;
        }

        printf("%d %d %d\n", i, j, max_cycle);
    }

    return 0;
}