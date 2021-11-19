#include <bits/stdc++.h>

using namespace std;

vector<int> pos[30];

void create_position_vector(){
    for(int i = 0; i < 20; i++){
        if(i == 0)
            pos[i].push_back(1);
        else{
            for(int j = 0; j < pos[i - 1].size(); j++)
                pos[i].push_back(pos[i - 1][j] * 2);
            for(int j = 0; j < pos[i - 1].size(); j++)
                pos[i].push_back(pos[i - 1][j] * 2 + 1);
        }
    }
}

int main(){
    int ncase;

    create_position_vector();

    scanf("%d", &ncase);

    while(ncase--){
        int depth, num;

        scanf("%d%d", &depth, &num);

        printf("%d\n", pos[depth - 1][num - 1]);
    }

    scanf("%d", &ncase);

    return 0;
}