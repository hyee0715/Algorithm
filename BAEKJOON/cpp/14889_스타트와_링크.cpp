#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> ability;
vector<int> start, link;
vector<bool> visit;
int answer = 100000;

void input() {
	cin >> n;

	ability.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
}

vector<int> getLinkTeam() {
	unordered_set<int> st;
	vector<int> ret;

	for (int i = 0; i < start.size(); i++) {
		st.insert(start[i]);
	}

	for (int i = 0; i < n; i++) {
		if (st.find(i) == st.end()) {
			ret.push_back(i);
		}
	}

	return ret;
}

int getScore(int a, int b) {
	int score = 0;

	score += ability[a][b];
	score += ability[b][a];

	return score;
}

int getPower(bool isStartTeam) {
	int power = 0;

	if (isStartTeam) {
		for (int i = 0; i < start.size() - 1; i++) {
			for (int j = i + 1; j < start.size(); j++) {
				power += getScore(start[i], start[j]);
			}
		}
	}
	else {
		for (int i = 0; i < link.size() - 1; i++) {
			for (int j = i + 1; j < link.size(); j++) {
				power += getScore(link[i], link[j]);
			}
		}
	}

	return power;
}

void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		link.clear();
		link = getLinkTeam();

		int startPower = getPower(true);
		int linkPower = getPower(false);

		int dif = abs(startPower - linkPower);
		answer = min(answer, dif);

		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		start.push_back(i);
		dfs(i, cnt + 1);
		visit[i] = false;
		start.pop_back();
	}
}

void solution() {
	visit.assign(n, false);

	//조합
	dfs(0, 0);

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