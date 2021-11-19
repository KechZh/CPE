#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

vector<int> node[MAX];
bool visit[MAX];
int in[MAX];
int out[MAX];
int edge_count = 0; 

void initialize(){
    memset(visit, false, sizeof(visit));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    edge_count = 0;

    for(int i = 0; i < MAX; i++)
        node[i].clear();
}

int find_root(){
    int root;
    queue<int> que;
    int now, next;

    for(int i = 0; i < MAX; i++){
        if(in[i] == 0 && out[i] != 0)
            que.push(i);
    }

    if(que.size() != 1)
        return -1;

    root = que.front();

    while(!que.empty()){
        now = que.front();
        que.pop();

        if(!visit[now])
            visit[now] = true;
        else
            return -1;

        for(int i = 0; i < node[now].size(); i++){
            next = node[now][i];
            que.push(next);
        }
    }

    for(int i = 0; i < MAX; i++)
        if((in[i] > 0 || out[i] > 0) && !visit[i])
            return -1;

    return root;
}

int main(){
    int ncase = 1;
    int src, dst;
    int root;
    bool flag = true;

    while(flag){
        initialize();

        while(1){
            scanf("%d%d", &src, &dst);

            if(src > 0 && dst > 0){
                node[src].push_back(dst);
                in[dst]++;
                out[src]++;

                edge_count++;
            }
            else if(src == 0 && dst == 0){
                root = find_root();

                if(root != -1 || edge_count == 0)
                    printf("Case %d is a tree.\n", ncase++);
                else
                    printf("Case %d is not a tree.\n", ncase++);

                break;
            }
            else{
                flag = false;
                break;
            }
        }
    }
}