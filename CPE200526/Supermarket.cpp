#include <bits/stdc++.h>

#define MAX 10010

using namespace std;

typedef struct product{
    int profit;
    int deadline;
}product;

bool cmp(const product &a, const product &b){
    return a.profit > b.profit;
}

int main(){
    int n;

    while(scanf("%d", &n) != EOF){
        product prod[MAX];
        bool sell[MAX] = {false};
        int max_profit = 0;

        for(int i = 0; i < n; i++)
            scanf("%d%d", &prod[i].profit, &prod[i].deadline);

        sort(prod, prod + n, cmp);

        for(int i = 0; i < n; i++)
            for(int j = prod[i].deadline; j > 0; j--)
                if(!sell[j]){
                    max_profit += prod[i].profit;
                    sell[j] = true;
                    break;
                }

        printf("%d\n", max_profit);
    }

    return 0;
}