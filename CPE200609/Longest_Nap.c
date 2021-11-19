#include <stdio.h>

#define MAX 24 * 60

int schedule[MAX + 10];

void schedule_appointment(int t1, int t2){
    for(int i = t1; i < t2; i++)
        schedule[i] = 1;
}

void initialize(){
    for(int i = 0; i < MAX + 10; i++)
        schedule[i] = 0;
    
    schedule_appointment(0, 10 * 60);
    schedule_appointment(18 * 60, 24 * 60);
}

int calculate_nap_time(int start_time){
    int nap = 0;

    for(int i = start_time; i < MAX; i++){
        if(schedule[i] == 0){
            nap++;
            schedule[i] = 1;
        }
        else
            break;
    }

    return nap;
}

int main(){
    int ncase = 1;
    int s;

    while(scanf("%d", &s) != EOF){
        int h1, m1, h2, m2;
        char str[300];
        int start_time;
        int max_nap = 0;

        initialize();

        while(s--){
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            gets(str);

            int t1 = h1 * 60 + m1;
            int t2 = h2 * 60 + m2;

            schedule_appointment(t1, t2);
        }

        for(int i = 10 * 60; i < 18 * 60; i++)
            if(schedule[i] == 0){
                int nap = calculate_nap_time(i);

                if(nap > max_nap){
                    max_nap = nap;
                    start_time = i;
                }
            }

        if(max_nap / 60 > 0)
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d hours and %d minutes.\n", ncase++, start_time / 60, start_time % 60, max_nap / 60, max_nap % 60);
        else
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d minutes.\n", ncase++, start_time / 60, start_time % 60, max_nap);
    }

    return 0;
}