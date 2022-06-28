#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int an, bn, sum = 0;
vector<int> a, b;

void initialize() {
	a.clear();
	b.clear();
	sum = 0;
}

void input() {
	cin >> an >> bn;

	int n;
	for (int i = 0; i < an; i++) {
		cin >> n;
		a.push_back(n);
	}

	for (int i = 0; i < bn; i++) {
		cin >> n;
		b.push_back(n);
	}
}

int binary_search(int target) {
	int left = 0;
	int right = b.size() - 1;
	int idx = -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (b[mid] < a[target]) {
			idx = max(idx, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return idx;
}

void solution() {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++) {
		sum += (binary_search(i) + 1);
	}

	cout << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}