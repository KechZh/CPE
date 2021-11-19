#include <stdio.h>

#define MAX 50010

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1 - i; j++)
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main(){
    int ncase;

    scanf("%d", &ncase);

    while(ncase--){
        int street, avenue, f;
        int s[MAX], a[MAX];

        scanf("%d%d%d", &street, &avenue, &f);

        for(int i = 0; i < f; i++)
            scanf("%d%d", &s[i], &a[i]);

        bubble_sort(s, f);
        bubble_sort(a, f);

        if(f % 2 == 0)
            printf("(Street: %d, Avenue: %d)\n", s[f / 2 - 1], a[f / 2 - 1]);
        else
            printf("(Street: %d, Avenue: %d)\n", s[f / 2], a[f / 2]);
    }

    return 0;
}