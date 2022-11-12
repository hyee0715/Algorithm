#include <iostream>
using namespace std;

int n, m;
int friends[100001];

void input() {
	cin >> n >> m;

	int a, b;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		friends[a]++;
		friends[b]++;
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		cout << friends[i] << "\n";
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