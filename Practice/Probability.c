#include <stdio.h>
#include <math.h>

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int player, winner;
        double event;
        double win_prob, total_prob = 0;

        scanf("%d%lf%d", &player, &event, &winner);

        win_prob = pow(1 - event, winner - 1) * event;

        for(int i = 0; i < player; i++)
            total_prob += pow(1 - event, i) * event;

        if(event != 0)
            printf("%.4lf\n", win_prob / total_prob);
        else
            printf("0.0000\n");
    }

    return 0;
}