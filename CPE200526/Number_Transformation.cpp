#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

bool prime[MAX];
vector<int> prime_list;

void create_prime_table(){
    prime[0] = prime[1] = false;

    for(int i = 2; i < MAX; i++)
        prime[i] = true;

    for(int i = 2; i < MAX; i++)
        if(prime[i])
            for(int j = i * 2; j < MAX; j += i)
                prime[j] = false;
}

void create_prime_list(){
    for(int i = 2; i < MAX; i++)
        if(prime[i])
            prime_list.push_back(i);
}

int dp_tran(int s, int t){
    int tran[MAX];

    for(int i = 0; i < MAX; i++)
        tran[i] = 0x7fffffff;

    tran[s] = 0;

    for(int i = s; i <= t; i++)
        if(tran[i] != 0x7fffffff)
            for(int j = 0; j < prime_list.size() && prime_list[j] <= t - i && prime_list[j] != i; j++)
                if(i % prime_list[j] == 0)
                    tran[i + prime_list[j]] = min(tran[i] + 1, tran[i + prime_list[j]]);

    if(tran[t] != 0x7fffffff)
        return tran[t];
    else
        return -1;
}

int main(){
    int ncase = 1;

    create_prime_table();
    create_prime_list();

    while(1){
        int s, t;
        int tran_time;

        scanf("%d%d", &s, &t);

        if(s == 0 && t == 0)
            break;

        tran_time = dp_tran(s, t);

        printf("Case %d: %d\n", ncase++, tran_time);
    }

    return 0;
}