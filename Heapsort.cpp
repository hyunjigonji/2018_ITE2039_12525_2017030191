//2017030191_LeeHyunji
#include <stdio.h>

int arr[100005];

void max_heapify(int* arr, int i, int n){
    int l = 2*i;
    int r = (2*i)+1;
    
    int largest = 0;
    if(l <= n && arr[l] > arr[i]){
        largest = l;
    }
    else largest = i;
    
    if(r <= n && arr[r] > arr[largest]){
        largest = r;
    }
    
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        max_heapify(arr, largest, n);
    }
}

void build_max_heap(int* arr, int n){
    for(int i = n/2 ; i >= 1 ; i--){
        max_heapify(arr,i,n);
    }
}

int main(){
    int n, k; scanf("%d %d",&n,&k);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&arr[i]);
    
    build_max_heap(arr, n);
    int size = n;
    for(int i = size ; i >= 2 ; i--){
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        
        n--;
        
        max_heapify(arr, 1, n);
    }
    
    for(int i = size ; i > size-k ; i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i = size-k ; i >= 1 ; i--){
        printf("%d ",arr[i]);
    }
    
    return 0;
}

