// 2017030191_LeeHyunji

#include <stdio.h>

int arr[30005];

void insertion_sort(int arr[], int n){
    int next = 0;
    int i,j;
    for(i = 1 ; i < n ; i++){
        next = arr[i];
        for(j = i - 1 ; j >= 0 && next > arr[j] ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = next;
    }
}

int main(){
    int N; scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr, N);
    for(int i = 0 ; i < N ; i++) printf("%d\n",arr[i]);
    
    return 0;
}

