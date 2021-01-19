/* with BOJ_2042 https://www.acmicpc.net/problem/2042 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(vector<ll> &tree, int i) {
    ll ans = 0;
    while(i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(vector<ll> &tree, int i, ll diff) {
    while(i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<ll> arr(N+1), tree(N+1);
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        update(tree, i, arr[i]);
    }
    for(int i=0; i<M+K; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            ll diff = c-arr[b];
            arr[b] = c;
            update(tree, b, diff);
        } else cout << sum(tree, c) - sum(tree, b-1) << '\n';
    }

    return 0;
}