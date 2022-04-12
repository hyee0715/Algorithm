#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 8
using namespace std;

int n, answer_max = 0;
int arr[MAX];
vector<int> v;
bool visit[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int find_sum() {
	int sum = 0;

	for (int i = 0; i < n - 1; i++) {
		sum += (abs(v[i] - v[i + 1]));
	}

	return sum;
}

//순열
void dfs(int cnt) {
	if (cnt == n) {
		answer_max = max(answer_max, find_sum());
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
		visit[i] = false;
	}
}

void solution() {
	dfs(0);

	cout << answer_max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}