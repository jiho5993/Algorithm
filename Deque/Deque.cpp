/* with BOJ_10866 https://www.acmicpc.net/problem/10866 */

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr[20001];
int l=10000, r=10000;

void push_front(int x) {
    arr[--l] = x;
}

void push_back(int x) {
    arr[r++] = x;
}

int pop_front() {
    return arr[l++];
}

int pop_back() {
    return arr[--r];
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
        if(cmd == "push_front") {
            int x; cin >> x;
            push_front(x);
        } else if(cmd == "push_back") {
            int x; cin >> x;
            push_back(x);
        } else if(cmd == "pop_front") {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << pop_front() << '\n';
        } else if(cmd == "pop_back") {
            if(empty()) {
                cout << "-1\n";
                continue;
            }
            cout << pop_back() << '\n';
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