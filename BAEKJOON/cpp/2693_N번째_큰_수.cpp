#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

void input() {
	v.clear();

	int n;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		v.push_back(n);
	}
}

void solution() {
	sort(v.begin(), v.end(), greater<>());

	cout << v[2] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}