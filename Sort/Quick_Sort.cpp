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
int arr[1000001];

int partition(int left, int right) {
    int j=left, item=arr[left];
    for(int i=left+1; i<=right; i++) {
        if(item > arr[i])
            swap(arr[i], arr[++j]);
    }
    swap(arr[left], arr[j]);
    return j;
}

void quick_sort(int left, int right) {
    if(left < right) {
        int pivot = partition(left, right);
        quick_sort(left, pivot-1);
        quick_sort(pivot+1, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    quick_sort(0, N-1);
    for(int i=0; i<N; i++) cout << arr[i] << '\n';

    return 0;
}