/* with BOJ_1929 https://www.acmicpc.net/problem/1929 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()]

bool p[1000001];
vector<int> prime;

void eratos(int n, int m) {
  p[1] = 1;
  for(int i=2; i*i<=m; i++) {
    if(p[i]) continue;
    for(int j=i*2; j<=m; j+=i) p[j] = 1;
  }
  for(int i=n; i<=m; i++)
    if(!p[i])
      prime.pb(i);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;
  eratos(N, M);
  for(auto i:prime) cout << i << '\n';
  
  return 0;
}