#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        int num;
        int sum = 0;

        scanf("%d", &num);

        if(num == 0)
            break;

        while(num >= 10){
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }

            num = sum;
            sum = 0;
        }

        printf("%d\n", num);
    }

    return 0;
}