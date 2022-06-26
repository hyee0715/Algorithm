#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	sort(v.begin(), v.end(), greater<>());

	cout << v[k - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}