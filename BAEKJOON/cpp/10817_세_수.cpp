#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void input() {
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
}

void solution() {
	sort(v.begin(), v.end());

	cout << v[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}