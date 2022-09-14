#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, min_num = INT_MAX;
vector<int> v;

void input() {
	cin >> n >> m;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	sort(v.begin(), v.end());

	int left = 0, right = 0;

	while (left < n && right < n) {
		if (v[right] - v[left] < m) {
			right++;
		}
		else {
			min_num = min(min_num, v[right] - v[left]);
			left++;
		}
	}

	cout << min_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}