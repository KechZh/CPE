#include <bits/stdc++.h>

using namespace std;

void count_digit(int n, int count[]){
    while(n > 0){
        count[n % 10]++;
        n /= 10;
    }
}

int arranging_descending_order(int count[]){
    int des = 0;

    for(int i = 9; i >= 0; i--)
        for(int j = 0; j < count[i]; j++)
            des = des * 10 + i;

    return des;
}

int arranging_ascending_order(int count[]){
    int as = 0;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < count[i]; j++)
            as = as * 10 + i;

    return as;
}

int main(){
    while(1){
        int n;
        int chain = 0;
        bool flag = true;
        vector<int> visit;

        scanf("%d", &n);

        if(n == 0)
            break;

        printf("Original number was %d\n", n);

        while(flag){
            int count[10] = {0};

            visit.push_back(n);

            count_digit(n, count);

            int des = arranging_descending_order(count);
            int as = arranging_ascending_order(count);

            n = des - as;

            for(int i = 0; i < visit.size(); i++)
                if(n == visit[i]){
                    flag = false;
                    break;
                }

            chain++;

            for(int i = 0; i < visit.size(); i++)
                if(n == visit[i]){
                    flag = false;
                    break;
                }

            printf("%d - %d = %d\n", des, as, n);
        }

        printf("Chain length %d\n\n", chain);
    }

    return 0;
}