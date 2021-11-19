#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
int seq[1010][20];

void ducci(int now){
    for(int i = 0; i < n; i++)
        seq[now][i] = abs(seq[now - 1][i] - seq[now - 1][(i + 1) % n]);
}

bool compare_sequence(int a, int b){
    bool eq = true;

    for(int i = 0; i < n; i++)
        if(seq[a][i] != seq[b][i]){
            eq = false;
            break;
        }

    return eq;
}

int check_sequence(int now){
    bool zero = true;
    bool loop = false;

    for(int i = 0; i < n; i++)
        if(seq[now][i] != 0){
            zero = false;
            break;
        }

    if(zero)
        return 1;

    for(int i = 0; i < now; i++){
        if(compare_sequence(now, i)){
            loop = true;
            break;
        }
    }

    if(loop)
        return 2;

    return 0;
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int cnt = 1;
        int state;

        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%d", &seq[0][i]);
        
        while(1){
            ducci(cnt);
            state = check_sequence(cnt);

            if(state == 1){
                printf("ZERO\n");
                break;
            }
            else if(state == 2){
                printf("LOOP\n");
                break;
            }

            cnt++;
        }
    }

    return 0;
}