#include <stdio.h>

int josephus(int n, int k){
	int s = 0;

	for (int i = 2; i <= n; i++)
		s = (s + k) % i;
    
	return s;
}

int main(){
    while(1){
        int n;
        int k;

        scanf("%d", &n);

        if(n == 0)
            break;
        
        n--;

        for(int i = 1; i < n; i++){
            k = i;
            int last = josephus(n, i);

            if(last == 11)
                break;
        }

        printf("%d\n", k);
    }
}