/* with BOJ_1753 https://www.acmicpc.net/problem/1753 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
const int INF = 2e9;
vector<pii> arr[20001];
vector<int> dist(20001, INF);
int V, E, st;

void dij() {
  dist[st] = 0;
  priority_queue<pii, vector<pii>, greater<pii> > pq; // min heap을 사용
  pq.push({0, st}); // {가중치, 정점} 이 순서대로 넣어야 가장 작은 경로를 가진 정점이 나오도록 하기 위해
  while(!pq.empty()) {
    int tmp = pq.top().second;
    int cst = pq.top().first;
    pq.pop();
    if(dist[tmp] < cst) continue;
    for(auto i:arr[tmp]) {
      int nxt = i.first;
      int nc = i.second + cst;
      if(dist[nxt] > nc) {
        dist[nxt] = nc;
        pq.push({nc, nxt});
      }
    }
  }
  for(int i=1; i<=V; i++) {
    if(dist[i] == INF) cout << "INF\n";
    else cout << dist[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> V >> E >> st;
  for(int i=0; i<E; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].pb({b, c});
  }
  dij();
  
  return 0;
}