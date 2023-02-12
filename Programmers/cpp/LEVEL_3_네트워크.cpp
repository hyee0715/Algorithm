#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& visit, int x) {
	visit[x] = true;

	for (int i = 0; i < computers[x].size(); i++) {
		if (i == x) {
			continue;
		}

		if (computers[x][i] == 1 && visit[i] == false) {
			dfs(computers, visit, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> visit(computers.size(), false);

	for (int i = 0; i < computers.size(); i++) {
		if (visit[i] == false) {
			answer++;
			dfs(computers, visit, i);
		}
	}

	return answer;
}