// 2017030191_LeeHyunji

#include <stdio.h>

int arr[100005];
int temp[50005];

void merge(int arr[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = 0;
    
    while(i <= mid && j <= right){
        if(arr[i] >= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    
    while(j <= right){
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    k--;
    
    while(k >= 0){
        arr[left + k] = temp[k];
        k--;
    }
}

void merge_sort(int arr[], int left, int right){
    int mid;
    if(left < right){
        mid = (left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    else return;
}

int main(){
    int N; scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr, 0, N-1);
    for(int i = 0 ; i < N ; i++) printf("%d\n",arr[i]);
    
    return 0;
}

