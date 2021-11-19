#include <stdio.h>

int main(){
    int ncase;
    char day[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d", &ncase);

    while(ncase--){
        int m, d;
        int sum = 4;

        scanf("%d%d", &m, &d);

        for(int i = 0; i < m; i++){
            if(i < m-1)
                sum += month[i];
            else
                sum += d;
        }
        
        printf("%s\n", day[sum%7]);
    }

    return 0;
}