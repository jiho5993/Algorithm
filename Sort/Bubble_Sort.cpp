/* with BOJ_2750 https://www.acmicpc.net/problem/2750 */

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N;
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
    for(int i=0; i<N; i++) cout << arr[i] << '\n';

    return 0;
}