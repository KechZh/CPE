#include <stdio.h>

#define MAX 1000010

int prime[MAX];

void create_prime_table(){
    for(int i = 2; i < MAX; i++)
        prime[i] = 1;

    for(int i = 0; i < MAX; i++)
        if(prime[i])
            for(int j = i*2; j < MAX; j += i)
                prime[j] = 0;
}

int reverse_number(int num){
    int rev_num = 0;
    int digit[10];
    int count = 0;

    while(num > 0){
        digit[count++] = num % 10;
        num /= 10;
    }

    for(int i = 0; i < count; i++)
        rev_num = rev_num * 10 + digit[i];
    
    return rev_num;
}

int main(){
    int n;

    create_prime_table();

    while(scanf("%d", &n) != EOF){
        if(prime[n] && prime[reverse_number(n)] && n != reverse_number(n))
            printf("%d is emirp.\n", n);
        else if(prime[n])
            printf("%d is prime.\n", n);
        else
            printf("%d is not prime.\n", n);
    }

    return 0;
}