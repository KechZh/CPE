#include <stdio.h>

#define MAX_DIGIT 2000

int fib[5010][MAX_DIGIT] = {{0}, {1}};

void big_addition(int sum[], int n1[], int n2[]){
    int carry = 0;

    for(int i = 0; i < MAX_DIGIT; i++){
        sum[i] = (n1[i] + n2[i] + carry) % 10;
        carry = (n1[i] + n2[i] + carry) / 10;
    }
}

void create_fib_table(){
    for(int i = 2; i < 5010; i++)
        big_addition(fib[i], fib[i-1], fib[i-2]);
}

int main(){
    int n;

    create_fib_table();

    while(scanf("%d", &n) != EOF){
        int sta = 0;

        for(int i = MAX_DIGIT - 1; i >= 0; i--)
            if(fib[n][i] != 0){
                sta = i;
                break;
            }

        printf("The Fibonacci number for %d is ", n);

        for(int i = sta; i >= 0; i--){
            if(i > 0)
                printf("%d", fib[n][i]);
            else
                printf("%d\n", fib[n][i]);
        }
    }

    return 0;
}