//2017030191_LeeHyunji

#include <stdio.h>
#include <stack>

using namespace std;

stack<int> ans;

bool adj[1005][1005];
bool finish[1005];
bool visit[1005];

int N;
bool DAG = true;

void dfs(int start){
  if(finish[start]){
    DAG = false;
    return;
  }
  finish[start] = true;

  for(int i = 1 ; i <= N ; i++){
    if(adj[start][i] && !visit[i]){
      dfs(i);
    }
  }
  visit[start] = true;
  ans.push(start);

  return;
}

int main(){
  scanf("%d",&N);
  int from, to;
  while(scanf("%d %d",&from,&to) != EOF){
    adj[from][to] = true;
  }
  for(int i = 1 ; i <= N ; i++){
    if(!visit[i]){
      dfs(i);
    }
  }
  if(ans.size() != N){
    DAG = false;
  }
  printf("%d\n",DAG);
  if(DAG){
    while(!ans.empty()){
      printf("%d ",ans.top());
      ans.pop();
    }
    printf("\n");
  }

  return 0;
}
