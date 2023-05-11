class Solution {
public:
	vector<int> check(int a, int b, bool isUpDirection, vector<vector<int>>& mat) {
		vector<int> answer;

		int upDirX[] = { 1, 0 };
		int upDirY[] = { 0, 1 };

		int downDirX[] = { 0, 1 };
		int downDirY[] = { 1, 0 };

		stack<pair<int, int>> st;
		queue<pair<int, int>> q;
		vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
		q.push({ a, b });
		visit[a][b] = true;

		while (!q.empty()) {
			int qSize = q.size();

			for (int k = 0; k < qSize; k++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				answer.push_back(mat[x][y]);

				for (int i = 0; i < 2; i++) {
					int nx, ny;

					if (isUpDirection) {
						nx = x + upDirX[i];
						ny = y + upDirY[i];
					}
					else {
						nx = x + downDirX[i];
						ny = y + downDirY[i];
					}

					if (nx < 0 || ny < 0 || nx >= mat.size() || ny >= mat[0].size()) {
						continue;
					}

					if (visit[nx][ny] == false) {
						visit[nx][ny] = true;
						st.push({ nx ,ny });
					}
				}
			}

			while (!st.empty()) {
				q.push(st.top());
				st.pop();
			}

			if (isUpDirection) {
				isUpDirection = false;
			}
			else {
				isUpDirection = true;
			}
		}

		return answer;
	}

	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		return check(0, 0, true, mat);
	}
};