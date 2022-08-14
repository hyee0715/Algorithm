#include <iostream>
#include <unordered_map>
using namespace std;

int n, v;
unordered_map<int, int> um;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		um[a]++;
	}
	
	cin >> v;
}

void solution() {
	cout << um[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}