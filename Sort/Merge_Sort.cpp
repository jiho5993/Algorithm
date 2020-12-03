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
int arr[1000001], arr2[1000001];

void merge(int l, int r) {
    int mid = (l+r)/2;
    int i=l, j=mid+1, k=l;
    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) arr2[k++] = arr[i++];
        else arr2[k++] = arr[j++];
    }
    int tmp = i > mid ? j : i;
    while(k <= r) arr2[k++] = arr[tmp++];

    for(int i=l; i<=r; i++) arr[i] = arr2[i];
}

void merge_sort(int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    merge_sort(0, N-1);

    for(int i=0; i<N; i++) cout << arr[i] << '\n';

    return 0;
}