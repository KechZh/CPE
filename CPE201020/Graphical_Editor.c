#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 260

char table[MAX][MAX];
int m, n;
bool flag = true;
char tmp;

void clear_table(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            table[i][j] = 'O';
}

void fill_rectangle(int x1, int y1, int x2, int y2, char color){
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            table[i][j] = color;
}

void fill_region(int x, int y, char color){
    char now_color = table[x][y];

    table[x][y] = color;

    if(x - 1 > 0 && table[x - 1][y] == now_color)
        fill_region(x - 1, y, color);

    if(x + 1 <= m && table[x + 1][y] == now_color)
        fill_region(x + 1, y, color);

    if(y - 1 > 0 && table[x][y - 1] == now_color)
        fill_region(x, y - 1, color);

    if(y + 1 <= n && table[x][y + 1] == now_color)
        fill_region(x, y + 1, color);
}

void print_table(char name[]){
    printf("%s\n", name);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%c", table[j][i]);

        printf("\n");
    }
            
}

int main(){
    while(flag){
        char cmd;
        int x1, y1, x2, y2;
        char color;
        char name[10];

        scanf("%c", &cmd);

        switch(cmd){
            case 'I':
                scanf("%d %d", &m, &n);

                clear_table();

                break;

            case 'C':
                clear_table();

                break;

            case 'L':
                scanf("%d %d %c", &x1, &y1, &color);

                fill_rectangle(x1, y1, x1, y1, color);

                break;

            case 'V':
                scanf("%d %d %d %c", &x1, &y1, &y2, &color);

                fill_rectangle(x1, y1, x1, y2, color);

                break;

            case 'H':
                scanf("%d %d %d %c", &x1, &x2, &y1, &color);

                fill_rectangle(x1, y1, x2, y1, color);

                break;

            case 'K':
                scanf("%d %d %d %d %c", &x1, &x2, &y1, &y2, &color);

                fill_rectangle(x1, y1, x2, y2, color);

                break;
        
            case 'F':
                scanf("%d %d %c", &x1, &y1, &color);

                fill_region(x1, y1, color);

                break;

            case 'S':
                scanf("%s", name);

                print_table(name);

                break;

            case 'X':
                flag = false;

                break;

            default:
                

                break;
        }

        getc(stdin);
    }

    return 0;
}