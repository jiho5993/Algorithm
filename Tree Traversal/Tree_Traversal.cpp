/* with BOJ_1991 https://www.acmicpc.net/problem/1991 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N;
char tree[27][2];

void preorder(int loc) { // root -> left -> right
  if(loc + 'A' == '.') return;

  cout << (char)(loc+'A');
  preorder(tree[loc][0] - 'A');
  preorder(tree[loc][1] - 'A');
}

void inorder(int loc) { // left -> root -> right
  if(loc + 'A' == '.') return;

  inorder(tree[loc][0] - 'A');
  cout << (char)(loc+'A');
  inorder(tree[loc][1] - 'A');
}

void postorder(int loc) { // left -> right -> root
  if(loc + 'A' == '.') return;

  postorder(tree[loc][0] - 'A');
  postorder(tree[loc][1] - 'A');
  cout << (char)(loc+'A');
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  while(N--) {
    char a, b, c; cin >> a >> b >> c;
    tree[a-'A'][0] = b;
    tree[a-'A'][1] = c;
  }

  preorder(0);
  cout << '\n';

  inorder(0);
  cout << '\n';

  postorder(0);
  
  return 0;
}