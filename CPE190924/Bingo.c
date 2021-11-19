#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct postion{
    int row;
    int col;
}postion;

int bingo[5][5];
postion pos[75];
bool take[5][5];

void initialize(){
    memset(pos, -1, sizeof(pos));
    memset(take, false, sizeof(take));

    take[2][2] = true;
}

bool check_bingo(int n){
    if(pos[n].row != -1 && pos[n].col != -1){
        take[pos[n].row][pos[n].col] = true;

        if(take[pos[n].row][0] && take[pos[n].row][1] && take[pos[n].row][2] && take[pos[n].row][3] && take[pos[n].row][4])
            return true;

        if(take[0][pos[n].col] && take[1][pos[n].col] && take[2][pos[n].col] && take[3][pos[n].col] && take[4][pos[n].col])
            return true;

        if(take[0][0] && take[1][1] && take[2][2] && take[3][3] && take[4][4])
            return true;
        
        if(take[4][0] && take[3][1] && take[2][2] && take[1][3] && take[0][4])
            return true;

        return false;
    }
    else
        return false;
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int order[75];

        initialize();

        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(i != 2 || j != 2){
                    int n;

                    scanf("%d", &n);

                    bingo[i][j] = n;
                    pos[n].row = i;
                    pos[n].col = j;
                }

        for(int i = 0; i < 75; i++)
            scanf("%d", &order[i]);

        for(int i = 0; i < 75; i++)
            if(check_bingo(order[i])){
                printf("BINGO after %d numbers announced\n", i + 1);
                break;
            }
    }

    return 0;
}