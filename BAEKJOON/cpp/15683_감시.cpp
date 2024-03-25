#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> board;

int cctvCnt = 0;
vector<int> temp;
int answer = 0;

vector<pair<int, int>> cctvArr; //x, y좌표

vector<vector<int>> cctv1dx = { {0}, {-1}, {0}, {1} };
vector<vector<int>> cctv1dy = { {1}, {0}, {-1}, {0} };

vector<vector<int>> cctv2dx = { {0, 0}, {-1, 1}, {0, 0}, {-1, 1} };
vector<vector<int>> cctv2dy = { {1, -1}, {0, 0}, {1, -1}, {0, 0} };

vector<vector<int>> cctv3dx = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
vector<vector<int>> cctv3dy = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

vector<vector<int>> cctv4dx = { {0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, {1, 0, -1} };
vector<vector<int>> cctv4dy = { {1, 0, -1}, {0, -1, 0}, {-1, 0, 1}, {0, 1, 0} };

vector<vector<int>> cctv5dx = { {0, -1, 0, 1}, {0, -1, 0, 1}, {0, -1, 0, 1}, {0, -1, 0, 1} };
vector<vector<int>> cctv5dy = { {1, 0, -1, 0}, {1, 0, -1, 0}, {1, 0, -1, 0}, {1, 0, -1, 0} };

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0 && board[i][j] != 6) {
				cctvCnt++;
				cctvArr.push_back({ i, j });
			}
		}
	}

	answer = n * m;
}

void copyBoard(vector<vector<int>>& copy) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = board[i][j];
		}
	}
}

void getDirection(int cctvType, vector<vector<int>>& cctvDirectionDx, vector<vector<int>>& cctvDirectionDy) {
	if (cctvType == 1) {
		cctvDirectionDx = cctv1dx;
		cctvDirectionDy = cctv1dy;
	}
	else if (cctvType == 2) {
		cctvDirectionDx = cctv2dx;
		cctvDirectionDy = cctv2dy;
	}
	else if (cctvType == 3) {
		cctvDirectionDx = cctv3dx;
		cctvDirectionDy = cctv3dy;
	}
	else if (cctvType == 4) {
		cctvDirectionDx = cctv4dx;
		cctvDirectionDy = cctv4dy;
	}
	else {
		cctvDirectionDx = cctv5dx;
		cctvDirectionDy = cctv5dy;
	}
}

void markCctvSpace(vector<vector<int>>& tempBoard, int cctvIdx, int direction) {
	pair<int, int> cctvLocation = cctvArr[cctvIdx];
	int x = cctvLocation.first;
	int y = cctvLocation.second;

	int cctvType = tempBoard[x][y];

	vector<vector<int>> cctvDirectionDx;
	vector<vector<int>> cctvDirectionDy;

	getDirection(cctvType, cctvDirectionDx, cctvDirectionDy);

	vector<int> dx = cctvDirectionDx[direction];
	vector<int> dy = cctvDirectionDy[direction];

	for (int i = 0; i < dx.size(); i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (board[nx][ny] == 6) {
				break;
			}
			else if (board[nx][ny] == 0) {
				tempBoard[nx][ny] = 8;
			}

			nx = nx + dx[i];
			ny = ny + dy[i];
		}
	}
}

void checkCctvSpace() {
	vector<vector<int>> tempBoard(n, vector<int>(m));

	copyBoard(tempBoard);

	for (int i = 0; i < temp.size(); i++) {
		int currentCctvDirection = temp[i];

		markCctvSpace(tempBoard, i, currentCctvDirection);
	}

	int blindSpot = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempBoard[i][j] == 0) {
				blindSpot++;
			}
		}
	}

	answer = min(answer, blindSpot);
}

void dfs(int cnt) {
	if (cnt == cctvCnt) {
		checkCctvSpace();
	}
	else {
		for (int i = 0; i < 4; i++) {
			temp.push_back(i);
			dfs(cnt + 1);
			temp.pop_back();
		}
	}
}

void solution() {
	//중복 순열
	dfs(0);

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