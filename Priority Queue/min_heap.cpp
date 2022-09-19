#include <iostream>
using namespace std;

int heap[15];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(int n, int i) {
	int smallest = i;
	int l = i * 2;
	int r = i * 2 + 1;

	if (l <= n && heap[l] < heap[smallest]) smallest = l;

	if (r <= n && heap[r] < heap[smallest]) smallest = r;

	if (smallest != i) {
		swap(heap[i], heap[smallest]);
		heapify(n, smallest);
	}
}

int insert(int n, int v) {
	n++;
	heap[n] = v;

	int i = n;
	while (i > 1 && heap[i/2] > heap[i]) {
		swap(heap[i/2], heap[i]);
		i /= 2;
	}

	return n;
}

int remove(int n) {
	cout << heap[1] << ' ';

	swap(heap[n], heap[1]);
	n--;

	heapify(n, 1);

	return n;
}

void build_heap(int n) {
	for (int i=n/2; i>=1; i--)
		heapify(n, i);
}

void print_heap(int n) {
	for (int i=1; i<=n; i++) cout << heap[i] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n = 10;
	for (int i=1; i<=n; i++) heap[i] = -i * 10 + i;
	
	cout << "before heap\n";
	print_heap(n);

	// init
	cout << "init heap\n";
	build_heap(n);

	print_heap(n);

	// insert
	n = insert(n, -13);

	cout << "insert value -13\n";
	print_heap(n);

	// remove
	cout << "remove\n";
	while (n != 0) {
		n = remove(n);
	}

	return 0;
}
