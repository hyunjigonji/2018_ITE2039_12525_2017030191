//2017030191_LeeHyunji

#include <stdio.h>

int count;
int arr[300000];
int extract[300000];
int extrac;

void max_heapify(int* arr, int size, int i) {
    int left = i*2;
    int right = i*2+1;
    
    int largest = i;
    if (left <= size && arr[left] > arr[largest]) {
        if (right <= size && arr[left] == arr[right]){
            largest = right;
        }
        else{
            largest = left;
        }
    }
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        
        max_heapify(arr, size, largest);
    }
}
void insert_heap(int* arr, int i){
    if (i == 1){
        return;
    }
    else{
        int left = (i/2) * 2;
        int right = left + 1;
        
        if (arr[left] > arr[i/2]){
            int temp = arr[left];
            arr[left] = arr[i/2];
            arr[i/2] = temp;
            
            insert_heap(arr, i/2);
        }
        else if (right <= i && arr[i/2] < arr[right]){
            int temp = arr[right];
            arr[right] = arr[i/2];
            arr[i/2] = temp;
            
            insert_heap(arr, i/2);
        }
    }
}

int main() {
    while (true) {
        int input; scanf("%d",&input);
        if (input == 0){
            for (int i = 1 ; i <= extrac ; i++) {
                printf("%d ",extract[i]);
            }
            printf("\n");
            for (int i = 1 ; i < count + 1; i++) {
                printf("%d ",arr[i]);
            }
            return 0;
        }
        if (input == 1){
            scanf("%d", &arr[++count]);
            insert_heap(arr, count);
        }
        if (input == 2){
            extract[++extrac] = arr[1];
            arr[1] = arr[count--];
            max_heapify(arr, count, 1);
        }
        if (input == 3){
            int t = 0;
            scanf("%d", &t);
            scanf("%d", &arr[t]);
            int origin = arr[t];
            max_heapify(arr, count, t);
            if (origin == arr[t])
            {
                insert_heap(arr, t);
            }
        }
    }
    return 0;
}

