#include <iostream>
#include <algorithm>

#define MAX 1000000
using namespace std;

int n, m;
int a[MAX], b[MAX], c[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}

	for (int j = n; j < m + n; j++) {
		c[j] = b[j - n];
	}

	int c_size = m + n;

	sort(c, c + c_size);

	for (int i = 0; i < c_size; i++) {
		cout << c[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}