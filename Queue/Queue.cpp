/* with BOJ_10845 https://www.acmicpc.net/problem/10845 */

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr[10005];
int l=0, r=0;

void push(int x) {
    arr[r++] = x;
}

int pop() {
    return arr[l++];
}

int size() {
    return r-l;
}

bool empty() {
    return r == l;
}

int front() {
    return arr[l];
}

int back() {
    return arr[r-1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    while(N--) {
        string cmd; cin >> cmd;
        if(cmd == "push") {
            int x; cin >> x;
            push(x);
        } else if(cmd == "pop") {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << pop() << '\n';
        } else if(cmd == "size") {
            cout << size() << '\n';
        } else if(cmd == "empty") {
            cout << empty() << '\n';
        } else if(cmd == "front") {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << front() << '\n';
        } else {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << back() << '\n';
        }
    }

    return 0;
}