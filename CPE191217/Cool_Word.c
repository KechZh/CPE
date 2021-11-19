#include <stdio.h>
#include <string.h>

#define MAX 40

int is_cool_word(char str[]){
    int letter[26] = {0};
    int time[MAX] = {0};

    for(int i = 0; i < strlen(str); i++)
        letter[str[i] - 'a']++;

    for(int i = 0; i < 26; i++)
        time[letter[i]]++;

    if(time[0] == 25)
        return 0;

    for(int i = 1; i < MAX; i++)
        if(time[i] > 1)
            return 0;
    
    return 1;
}

int main(){
    int ncase = 1;
    int n;

    while(scanf("%d\n", &n) != EOF){
        int total = 0;

        while(n--){
            char str[MAX];

            fgets(str, MAX, stdin);

            str[strlen(str) - 1] = 0;

            total += is_cool_word(str);
        }

        printf("Case %d: %d\n", ncase++, total);
    }

    return 0;
}