#include <stdio.h>

int main(){
    int n;

    while(scanf("%d", &n) != EOF){
        int upper = 1, cut = 1;

        for(int i = 0; i < n; i++)
            upper *= 10;
        
        for(int i = 0; i < n/2; i++)
            cut *= 10;

        for(int i = 0; i < upper; i++){
            int a = i / cut;
            int b = i % cut;

            if(i == (a + b) * (a + b))
                switch(n){
                    case 2:
                        printf("%.2d\n", i);
                        break;
                    case 4:
                        printf("%.4d\n", i);
                        break;
                    case 6:
                        printf("%.6d\n", i);
                        break;
                    case 8:
                        printf("%.8d\n", i);
                        break;
                }
        }
    }

    return 0;
}