#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(unordered_map<int, vector<int>>& um, vector<bool>& visit, int x) {
	int maxNum = 0;
	int maxCnt = 0;

	queue<pair<int, int>> q; //현재 노드, 지나온 간선 수
	visit[x] = true;
	q.push({ x, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (maxNum < cnt) {
			maxNum = cnt;
			maxCnt = 1;
		}
		else {
			maxCnt++;
		}

		vector<int> v = um[cur];

		for (int i = 0; i < v.size(); i++) {
			if (visit[v[i]] == false) {
				q.push({ v[i], cnt + 1 });
				visit[v[i]] = true;
			}
		}
	}

	return maxCnt;
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	unordered_map<int, vector<int>> um;
	vector<bool> visit(n + 1, false);

	for (int i = 0; i < edge.size(); i++) {
		int x = edge[i][0];
		int y = edge[i][1];

		um[x].push_back(y);
		um[y].push_back(x);
	}

	answer = bfs(um, visit, 1);
	return answer;
}