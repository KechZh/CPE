#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, r, h;
    int height[10010] = {0};
    vector<pair<int, int>> node;
    int height_now = 0;

    while(scanf("%d%d%d", &l, &h, &r) != EOF){
        for(int i = l; i < r; i++)
            if(h > height[i])
                height[i] = h;
    }

    for(int i = 0; i < 10010; i++)
        if(height[i] != height_now){
            pair<int, int> tmp;
            
            tmp.first = i;
            tmp.second = height[i];

            node.push_back(tmp);
            height_now = height[i];
        }

    for(int i = 0; i < node.size(); i++){
        if(i < node.size() - 1)
            printf("%d %d ", node[i].first, node[i].second);
        else
            printf("%d %d\n", node[i].first, node[i].second);
    }

    return 0;
}