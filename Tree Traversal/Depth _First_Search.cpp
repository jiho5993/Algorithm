/* with BOJ_11724 https://www.acmicpc.net/problem/11724 */

#include <bits/stdc++.h>
using namespace std;

int N, M, res=0;
vector<int> arr[1001];
bool visit[1001];

void dfs(int cur) {
    visit[cur] = true;
    for(auto i:arr[cur]) {
        if(!visit[i]) {
            dfs(i);
            visit[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1; i<=N; i++) {
        if(!visit[i]) {
            dfs(i);
            res++;
        }
    }
    cout << res;

    return 0;
}