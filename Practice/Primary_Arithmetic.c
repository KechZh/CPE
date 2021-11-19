#include <stdio.h>
#include <string.h>

int main(){
    while(1){
        int a, b;
        int carry = 0;
        int carry_count = 0;

        scanf("%d%d", &a, &b);

        if(a == 0 && b == 0)
            break;

        while(a > 0 || b > 0){
            int tmp = a % 10 + b % 10 + carry;

            a /= 10;
            b /= 10;

            if(tmp >= 10){
                carry = 1;
                carry_count++;
            }
            else
                carry = 0;
        }

        if(carry_count > 1)
            printf("%d carry operations.\n", carry_count);
        else if(carry_count == 1)
            printf("%d carry operation.\n", carry_count);
        else
            printf("No carry operation.\n");
    }

    return 0;
}