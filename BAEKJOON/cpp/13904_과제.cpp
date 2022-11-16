#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, max_day = -1, answer = 0;
unordered_map<int, vector<int>> um; //남은 일수, 점수
vector<pair<int, int>> v; //점수, 남은 일수
vector<int> task;

void input() {
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		um[a].push_back(b);

		if (max_day < a) {
			max_day = a;
		}
	}
}

void solution() {
	while (max_day > 0) {
		for (int i = 0; i < um[max_day].size(); i++) {
			v.push_back({ um[max_day][i], max_day });
		}

		sort(v.begin(), v.end(), greater<>());
		
		if (v.empty()) {
			max_day--;
			continue;
		}

		task.push_back(v[0].first);

		v.erase(v.begin(), v.begin() + 1);

		max_day--;
	}

	for (int i = 0; i < task.size(); i++) {
		answer += task[i];
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