/* with BOJ_1753 https://www.acmicpc.net/problem/1753 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

vector<vector<pii> > adj(20001);
int v, e, st;
int dist[20001];

void dij(int src) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    fill(dist, dist+20001, 2e9);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(auto i : adj[here]) {
            int there = i.first;
            int new_cost = i.second + cost;
            if(dist[there] > new_cost) {
                dist[there]  = new_cost;
                pq.push({new_cost, there});
            }
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> v >> e >> st;
    for(int i=0; i<e; i++) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1].pb({v2, cost});
    }
    dij(st);
    for(int i=1; i<=v; i++) {
        if(dist[i] == 2e9) cout << "INF\n";
        else cout << dist[i];
    }

  return 0;
}