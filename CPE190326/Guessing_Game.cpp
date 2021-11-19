#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    char state[10];
    int upper, lower;
    bool flag = true;

    while(flag){
        upper = 11;
        lower = 0;

        while(1){
            scanf("%d", &num);
            getc(stdin);

            if(num == 0){
                flag = false;
                break;
            }

            fgets(state, 10, stdin);

            if(strcmp(state, "too high\n") == 0)
                upper = min(upper, num);
            else if(strcmp(state, "too low\n") == 0)
                lower = max(lower, num);
            else{
                if(num < upper && num > lower)
                    printf("Stan may be honest\n");
                else
                    printf("Stan is dishonest\n");

                break;
            }
        }
    }
    return 0;
}