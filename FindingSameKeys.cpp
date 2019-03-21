//2017030191_LeeHyunji

#include <stdio.h>

int nset[100005], mset[100005];
int ans;

int main(){
  int n,m; scanf("%d %d",&n,&m);

  for(int i = 0 ; i < n ; i++){
    int nnum; scanf("%d",&nnum);
    nset[nnum] = 1;
  }
  for(int i = 0 ; i < m ; i++){
    int mnum; scanf("%d",&mnum);
    if(nset[mnum] == 1) ans++;
  }

  printf("%d\n",ans);

  return 0;
}

