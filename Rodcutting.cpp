//2017030191_LeeHyunji

#include <stdio.h>
#define MAX 987654321

int p[105];
int r[105];
int s[105];

void bottom_up_cut_rod(int* p, int n){
    for(int i = 0 ; i <= n ; i++) r[i] = s[i] = 0;
    for(int j = 1 ; j <= n ; j++){
        int q = -MAX;
        for(int i = 1 ; i <= j ; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void print_cut_rod(int* p, int n){
    bottom_up_cut_rod(p, n);
    /*
    for(int i = 1 ; i <= n ; i++) printf("%d ",r[i]);
    printf("\n");
    for(int i = 1 ; i <= n ; i++) printf("%d ",s[i]);
    printf("\n");
    */

    printf("%d\n",r[n]);
    while(n > 0){
        printf("%d ",s[n]);
        n = n - s[n];
    }
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&p[i]);
    
    print_cut_rod(p, n);
    
    return 0;
}


