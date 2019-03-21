//2017030191_LeeHyunji

#include <stdio.h>
#define min(a,b) a <= b ? a : b

int a1[105], a2[105];
int t1[105], t2[105];
int T1[105], T2[105];
int S[2][105];
int ans[105];

int main(){
    int n; scanf("%d",&n);
    int e1,e2; scanf("%d %d",&e1,&e2);
    int x1,x2; scanf("%d %d",&x1,&x2);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a1[i]);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a2[i]);
    for(int i = 1 ; i < n ; i++) scanf("%d",&t1[i]);
    for(int i = 1 ; i < n ; i++) scanf("%d",&t2[i]);

    T1[1] = e1 + a1[1];
    T2[1] = e2 + a2[1];
    
    for(int i = 2 ; i <= n ; i++){
        T1[i] = min(T1[i-1] + a1[i], T2[i-1] + t2[i-1] + a1[i]);
        S[0][i] = T1[i-1]+a1[i] <= T2[i-1]+t2[i-1]+a1[i] ? 1:2;
        T2[i] = min(T2[i-1] + a2[i], T1[i-1] + t1[i-1] + a2[i]);
        S[1][i] = T2[i-1]+a2[i] < T1[i-1]+t1[i-1]+a2[i] ? 2:1;
    }
    T1[n+1] = T1[n] + x1;
    T2[n+1] = T2[n] + x2;
    
    int now = T1[n+1] <= T2[n+1] ? 1 : 2;
    ans[n+1] = now;
    
    for(int i = n ; i >= 1 ; i--){
        now = S[now-1][i];
        ans[i] = now;
        //printf("now = %d\n",now);
    }
    
    printf("%d\n",min(T1[n] + x1, T2[n] + x2));
    
    for(int i = 2 ; i <= n+1 ; i++) printf("%d %d\n",ans[i],i-1);
    
    return 0;
}


