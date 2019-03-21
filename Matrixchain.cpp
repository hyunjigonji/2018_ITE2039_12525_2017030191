//2017030191_LeeHyunji
#include <stdio.h>
#define MAX 987654321

int p[105];
int m[105][105];
int s[105][105];

void matrix_chain(int* p,int n){
    for(int i = 1 ; i <= n ; i++) m[i][i] = 0;
    for(int l = 2 ; l <= n ; l++){
        for(int i = 1 ; i <= n-l+1 ; i++){
            int j = i+l-1;
            m[i][j] = MAX;
            for(int k = i ; k <= j-1 ; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void matrix_chain_order(int i, int j){
    if(i == j){
        printf("%d ", i);
    }
    else{
        printf("( ");
        matrix_chain_order(i, s[i][j]);
        matrix_chain_order(s[i][j] + 1, j);
        printf(") ");
    }
}

int print_order(int* p, int i, int j){
    if(i == j) return 0;
    
    int min = MAX;
    int count = 0;
    
    for(int k = i ; k < j ; k++){
        count = print_order(p, i, k) + print_order(p, k, j) + p[i-1]*p[k]*p[j];
        
        if(count < min) min = count;
    }
    
    return min;
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 0 ; i <= n ; i++) scanf("%d",&p[i]);
    
    matrix_chain(p, n);
    
    printf("%d\n",m[1][n]);
 
    matrix_chain_order(1, n);
    printf("\n");
    
    return 0;
}


