//2017030191_LeeHyunji

#include <stdio.h>

int arr[30005];
int n,m;
int min, minInd;

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
    
    for(int i = 0 ; i < m ; i++){
        minInd = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
    for(int i = 0 ; i < n ; i++) printf("%d\n",arr[i]);
    
    return 0;
}

