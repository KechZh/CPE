#include <stdio.h>
#include <string.h>

typedef struct car{
    char maker[30];
    int low;
    int high;
}car;

int main(){
    int ncase;
    
    scanf("%d", &ncase);

    while(ncase--){
        int d, q;
        car c[10010];

        scanf("%d", &d);

        for(int i = 0; i < d; i++)
            scanf("%s %d %d", c[i].maker, &c[i].low, &c[i].high);

        scanf("%d", &q);

        while(q--){
            int query;
            char result[30] = "UNDETERMINED";

            scanf("%d", &query);

            for(int i = 0; i < d; i++){
                if(query >= c[i].low && query <= c[i].high && strcmp(result, "UNDETERMINED") == 0)
                    strcpy(result, c[i].maker);
                else if(query >= c[i].low && query <= c[i].high && strcmp(result, "UNDETERMINED") != 0){
                    strcpy(result, "UNDETERMINED");
                    break;
                }
            }

            printf("%s\n", result);
        }

        if(ncase)
            printf("\n");
    }

    return 0;
}