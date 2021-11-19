#include <stdio.h>

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int day, num_party;
        int party[3660] = {0};
        int sum = 0;

        scanf("%d%d", &day, &num_party);

        while(num_party--){
            int hartal;

            scanf("%d", &hartal);

            for(int i = hartal; i <= day; i += hartal)
                party[i] = 1;
        }

        for(int i = 7; i <= day + 7; i += 7)
            party[i] = party[i-1] = 0;

        for(int i = 1; i <= day; i++)
            sum += party[i];

        printf("%d\n", sum);
    }

    return 0;
}