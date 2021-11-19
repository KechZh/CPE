#include <stdio.h>
#include <string.h>

char field[110][110];

void set_mine(int x, int y){
    field[x][y] = '*';

    if(field[x-1][y-1] != '*')
        field[x-1][y-1]++;
    if(field[x][y-1] != '*')
        field[x][y-1]++;
    if(field[x+1][y-1] != '*')
        field[x+1][y-1]++;
    if(field[x-1][y] != '*')
        field[x-1][y]++;
    if(field[x+1][y] != '*')
        field[x+1][y]++;
    if(field[x-1][y+1] != '*')
        field[x-1][y+1]++;
    if(field[x][y+1] != '*')
        field[x][y+1]++;
    if(field[x+1][y+1] != '*')
        field[x+1][y+1]++;
}

int main(){
    int ncase = 1;

    while(1){
        int n, m;
        char tmp;

        scanf("%d%d", &n, &m);
        scanf("%c", &tmp);

        if(n == 0 && m == 0)
            break;

        if(ncase > 1)
            printf("\n");

        memset(field, '0', sizeof(field));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%c", &tmp);

                if(tmp == '*')
                    set_mine(i, j);
            }

            scanf("%c", &tmp);
        }

        printf("Field #%d:\n", ncase++);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(j < m)
                    printf("%c", field[i][j]);
                else
                    printf("%c\n", field[i][j]);
            }
    }

    return 0;
}