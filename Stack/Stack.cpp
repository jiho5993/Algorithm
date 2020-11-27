/* with BOJ_10828 https://www.acmicpc.net/problem/10828 */

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr[100005];
int pos = 0;

void push(int val) {
    arr[pos++] = val;
}

int pop() {
    return arr[--pos];
}

int size() {
    return pos;
}

bool empty() {
    return pos == 0;
}

int top() {
    return arr[pos-1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    while(N--) {
        string cmd; cin >> cmd;
        if(cmd == "push") {
            int val; cin >> val;
            push(val);
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
        } else {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << top() << '\n';
        }
    }

    return 0;
}