/* with BOJ_11404 https://www.acmicpc.net/problem/11404 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N, M;
int adj[101][101];

void floyd() {
  for(int via=1; via<=N; via++) { // via도시를 거쳐가는게 더 빠를 경우 update
    for(int from=1; from<=N; from++) { // from에서
      if(!adj[from][via]) // 시작 지점에서 경유 지점까지의 거리가 0인 경우
        continue;
      for(int to=1; to<=N; to++) { // to로
        if(!adj[via][to] || from == to)
          continue;
        if(!adj[from][to] || adj[from][to] > adj[from][via] + adj[via][to])
          adj[from][to] = adj[from][via] + adj[via][to];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M;
  for(int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    if(!adj[a][b]) adj[a][b] = c;
    else adj[a][b] = min(adj[a][b], c);
  }

  floyd();

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) cout << adj[i][j] << ' ';
    cout << '\n';
  }
  
  return 0;
}