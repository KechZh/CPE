#include <stdio.h>
#include <math.h>

int main(){
    while(1){
        int a, b;
        double root_a, root_b;
        int ans = 0;
        
        scanf("%d%d", &a, &b);

        if(a == 0 && b == 0)
            break;

        root_a = sqrt(a);
        root_b = sqrt(b);

        for(int i = 0; i < 500; i++)
            if(i >= root_a && i <= root_b)
                ans++;
        
        printf("%d\n", ans);
    }

    return 0;
}