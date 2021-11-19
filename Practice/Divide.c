#include <stdio.h>

int main(){
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF){
        int a[50] = {n};
        int k = 1;
        int conquer = 1;

        if (n < m || n <= 1 || m <= 1)
            conquer = 0;

        while(n > 1 && m > 1){
            if(n % m == 0){
                a[k++] = n / m;
                n /= m;
            }
            else{
                conquer = 0;
                break;
            }
        }

        if(conquer)
            for(int i = 0; i < k; i++){
                if(i < k-1)
                    printf("%d ", a[i]);
                else
                    printf("%d\n", a[i]);
            }
        else
            printf("Boring!\n");
    }

    return 0;
}