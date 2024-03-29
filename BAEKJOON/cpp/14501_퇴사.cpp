#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> days; //상담을 완료했을 때 걸리는 시간(days), 상담을 했을 때 받을 수 있는 금액
int answer = 0;
vector<int> v; //조합으로 뽑은 상담 날짜
vector<bool> visit;

void input() {
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		days.push_back({ a, b });
	}
}

int validateConsultationDays() {
	if (v.size() > 1) {
		for (int i = 0; i < v.size() - 1; i++) {
			int idx = v[i]; //상담 날짜
			int nextIdx = v[i + 1];

			int time = days[idx].first; //해당 날에 상담했을 경우 걸리는 시간

			if (idx + time > nextIdx) {
				return -1;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i]; //상담 날짜
		int time = days[idx].first; //해당 날에 상담했을 경우 걸리는 시간

		if (idx + time > n) {
			return -1;
		}
	}

	return 0;
}

int getConsultationFee() {
	if (validateConsultationDays() == -1) {
		return -1;
	}

	int sum = 0; 

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i];

		int fee = days[idx].second;

		sum += fee;
	}

	return sum;
}

void dfs(int idx, int cnt, int limit) {
	if (cnt == limit) {
		if (cnt == 10) {
			int a = 0;
		}

		int fee = getConsultationFee();

		if (fee != -1) {
			answer = max(answer, fee);
		}

		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(i);
		dfs(i, cnt + 1, limit);
		visit[i] = false;
		v.pop_back();
	}
}

void solution() {
	visit.assign(n, false);

	for (int i = 1; i <= n; i++) {
		//조합
		dfs(0, 0, i);
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