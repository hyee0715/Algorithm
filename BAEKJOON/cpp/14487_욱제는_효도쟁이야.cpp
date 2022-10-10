#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<int> v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;

		v.push_back(a);
	}
}

void solution() {
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++) {
		answer += v[i];
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}