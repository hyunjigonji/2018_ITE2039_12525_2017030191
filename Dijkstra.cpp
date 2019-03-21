//2017030191_LeeHyunji

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dist[5005];

vector<pair<int,int> > adj[5005];
priority_queue<pair<int,int> > pq;

int main(){
  int n; scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    int start, num; scanf("%d %d",&start,&num);
    for(int j = 0 ; j < num ; j++){
      int dest, wei; scanf("%d %d",&dest,&wei);
      adj[start].push_back(make_pair(dest,wei));
    }
  }

  for(int i = 1 ; i <= n ; i++) dist[i] = INF;

  pq.push(make_pair(0,1));
  dist[1] = 0;

  while(!pq.empty()){
    int now = pq.top().second;
    int nowdis = -pq.top().first;
    pq.pop();

    if(dist[now] < nowdis) continue;

    for(size_t i = 0 ; i < adj[now].size() ; i++){
      int next = adj[now][i].first;
      int nextdis = nowdis + adj[now][i].second;

      if(dist[next] > nextdis){
        dist[next] = nextdis;
        pq.push(make_pair(-nextdis,next));
      }
    }
  }

  int ans = -INF;
  for(int i = 1 ; i <= n ; i++){
    if(ans < dist[i]) ans = dist[i];
    //printf("%d ",dist[i]);
  }
  printf("%d\n",ans);

  return 0;
}

