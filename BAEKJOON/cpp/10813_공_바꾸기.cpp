#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void input() {
	cin >> n >> m;

	v.push_back(-1);

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
}

void solution() {
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		int temp = v[a];
		v[a] = v[b];
		v[b] = temp;
	}

	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << " ";
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