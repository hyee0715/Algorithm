#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int x, int y, int n, vector<bool>& visit) {
	queue<pair<int, int>> q; //현재 숫자, 연산 횟수
	q.push({ x, 0 });
	visit[x] = true;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == y) {
			return cnt;
		}

		int nextNum = num + n;
		if (nextNum <= y && visit[nextNum] == false) {
			q.push({ nextNum, cnt + 1 });
			visit[nextNum] = true;
		}

		nextNum = num * 2;
		if (nextNum <= y && visit[nextNum] == false) {
			q.push({ nextNum, cnt + 1 });
			visit[nextNum] = true;
		}

		nextNum = num * 3;
		if (nextNum <= y && visit[nextNum] == false) {
			q.push({ nextNum, cnt + 1 });
			visit[nextNum] = true;
		}
	}

	return -1;
}

int solution(int x, int y, int n) {
	int answer = 0;
	vector<bool> visit(y + 1, false);

	answer = bfs(x, y, n, visit);
	return answer;
}