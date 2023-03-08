#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//영역 크기 리턴
int bfs(int a, int b, vector<vector<int>>& picture, vector<vector<bool>>& visit) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	int area = 0;

	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		area++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= picture.size() || ny >= picture[0].size()) {
				continue;
			}

			if (picture[nx][ny] == picture[x][y] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);
	vector<vector<bool>> visit(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && visit[i][j] == false) {
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, picture, visit));
			}
		}
	}

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}