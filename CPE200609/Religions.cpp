#include <bits/stdc++.h>

#define MAX 50010

using namespace std;

vector<int> node[MAX];
bool visit[MAX];

void initialize(){
    memset(visit, false, sizeof(visit));

    for(int i = 0; i < MAX; i++)
        node[i].clear();
}

void dfs(int n){
    visit[n] = true;

    for(int i = 0; i < node[n].size(); i++)
        if(!visit[node[n][i]])
            dfs(node[n][i]);
}

int main(){
    int ncase = 1;

    while(1){
        int n, m;
        int node1, node2;
        int religion = 0;

        initialize();

        scanf("%d%d", &n, &m);

        if(n == 0 && m == 0)
            break;

        while(m--){
            scanf("%d%d", &node1, &node2);

            node[node1].push_back(node2);
            node[node2].push_back(node1);
        }

        for(int i = 1; i <= n; i++)
            if(!visit[i]){
                dfs(i);
                religion++;
            }

        printf("Case %d: %d\n", ncase++, religion);
    }

    return 0;
}