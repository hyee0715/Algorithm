#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

void bfs(unordered_map<int, vector<int>>& um, vector<bool>& visit, int destination, set<int>& sources, vector<int>& temp_answer) {
	queue<pair<int, int>> q; // 현재 위치, 현재까지의 이동 거리
	q.push({ destination, 0 });
	visit[destination] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (sources.find(cur) != sources.end()) {
			temp_answer[cur] = cnt;
			sources.erase(cur);
		}

		vector<int> area = um[cur];
		for (int i = 0; i < area.size(); i++) {
			if (visit[area[i]] == false) {
				q.push({ area[i], cnt + 1 });
				visit[area[i]] = true;
			}
		}
	}
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;
	unordered_map<int, vector<int>> um;
	vector<bool> visit(n + 1, false);
	set<int> source_set(sources.begin(), sources.end());
	vector<int> temp_answer(n + 1, -1);

	for (vector<int> road : roads) {
		um[road[0]].push_back(road[1]);
		um[road[1]].push_back(road[0]);
	}

	bfs(um, visit, destination, source_set, temp_answer);

	for (int i = 0; i < sources.size(); i++) {
		answer.push_back(temp_answer[sources[i]]);
	}

	return answer;
}