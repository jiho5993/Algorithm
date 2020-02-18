/* with BOJ_10999 https://www.acmicpc.net/problem/10999 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int arr[1000001];

typedef struct SegTree {
  vector<ll> tree; // SegTree
  vector<ll> lazy; // LazyTree
  int size; // Tree size
  SegTree(int N): size(N) { // constructor
    tree.resize(N*4);
    lazy.resize(N*4);
  }

  ll init(int node, int st, int en) { // SegTree init
    if(st == en) return tree[node] = arr[st];

    int mid = (st+en)/2;
    return tree[node] = init(node*2, st, mid) + init(node*2+1, mid+1, en);
  }

  void update_lazy(int node, int st, int en) { // LazyTree update
    if(!lazy[node]) return; // if lazy node is 0...

    tree[node] += (en-st+1)*lazy[node]; // st ~ en 

    if(st != en) { // if it is not leaf node, Add lazy child node to parent node.
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0; // Used node -> 0
  }

  void update_tree(int left, int right, ll diff) { update_tree(1, 0, size-1, left, right, diff); }
  void update_tree(int node, int st, int en, int left, int right, ll diff) { // SegTree update
    update_lazy(node, st, en); // if lazy is existed, Update node.

    if(left > en || st > right) return;

    if(left <= st && en <= right) {
      tree[node] += (en-st+1)*diff; // SegTree update
      if(st != en) { // if it is not leaf node, Update Lazy
        lazy[node*2] += diff;
        lazy[node*2+1] += diff;
      }
      return;
    }

    int mid = (st+en)/2;
    update_tree(node*2, st, mid, left, right, diff);
    update_tree(node*2+1, mid+1, en, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1]; // Update SegTree's node value
  }

  ll sum(int left, int right) { return sum(1, 0, size-1, left, right); }
  ll sum(int node, int st, int en, int left, int right) {
    update_lazy(node, st, en); // if lazy is existed, Update node.

    if(en < left || st > right) return 0;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return sum(node*2, st, mid, left, right) + sum(node*2+1, mid+1, en, left, right);
  }
} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, M, K; cin >> N >> M >> K;
  for(int i=0; i<N; i++) cin >> arr[i];
  ST tree(N);
  tree.init(1, 0, N-1);

  for(int i=0; i<M+K; i++) {
    cin.ignore();
    int a; cin >> a;
    if(a == 1) {
      ll b, c, d; cin >> b >> c >> d;
      tree.update_tree(b-1, c-1, d);
    } else {
      int b, c; cin >> b >> c;
      cout << tree.sum(b-1, c-1) << '\n';
    }
  }

  return 0;
}