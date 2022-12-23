#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h, answer = 0;
vector<int> v;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h;
		v.push_back(h);
	}
}

void solution() {
	int max_num = -1;

	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] > max_num) {
			max_num = max(max_num, v[i]);
			answer++;
		}
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