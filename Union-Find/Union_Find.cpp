/* with BOJ_1717 https://www.acmicpc.net/problem/1717 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int parent[1000001];
int level[1000001];

int find(int u) { // 시간 복잡도: lgN
  if(parent[u] == u) return u; // u의 루트 노드가 자기 자신이면
  return parent[u] = find(parent[u]);
  // find함수를 다시 호출하면서 "경로 압축 최적화"를 진행한다.
}

void merge(int u, int v) { // 시간 복잡도: lgN
  u = find(u), v = find(v); // u, v의 루트 노드를 먼저 찾는다

  if(u == v) return; // 루트 노드가 같다면 이미 같은 트리

  // u가 v보다 더 깊은 트리라면 swap
  if(level[u] > level[v]) swap(u, v); // 항상 u가 작은 트리가 되도록 한다.

  parent[u] = v; // u의 루트가 v가 되도록

  // u와 v의 깊이가 같을 때 v의 깊이를 늘려준다.
  if(level[u] == level[v]) level[v]++;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;

  for(int i=1; i<=N; i++) { // 초기에는 자신의 부모는 자기 자신, 물론 level도 1
    parent[i] = i;
    level[i] = 1;
  }

  while(M--) {
    int a, b, c; cin >> a >> b >> c;
    if(a == 0) merge(b, c);
    else {
      if(find(b) == find(c)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  
  return 0;
}