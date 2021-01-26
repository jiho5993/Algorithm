/* with BOJ_1926 https://www.acmicpc.net/problem/1926 */

#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int N, M;
int arr[501][501];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    int res1=0, res2=0;
    queue<pair<int, int> > qp;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j]) {
                qp.push({i, j});
                arr[i][j] = 0;
                res1++;
                int cnt=1;
                while(!qp.empty()) {
                    for(int k=0; k<4; k++) {
                        int xx = qp.front().second + dx[k];
                        int yy = qp.front().first + dy[k];
                        if(yy < 0 || xx < 0 || yy >= N || xx >= M || !arr[yy][xx]) continue;
                        arr[yy][xx] = 0;
                        qp.push({yy, xx});
                        cnt++;
                    }
                    qp.pop();
                }
                res2 = max(res2, cnt);
            }
        }
    }
    cout << res1 << '\n' << res2;

    return 0;
}