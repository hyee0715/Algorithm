#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> board, copyB;
vector<vector<bool>> cloud, copyC;
vector<pair<int, int>> movingInfomations; //방향, 이동 칸 수

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dgx[] = {-1, -1, 1, 1}; //대각선
int dgy[] = {-1, 1, -1, 1};

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int d, s;

	for (int i = 0; i < m; i++) {
		cin >> d >> s;

		movingInfomations.push_back({ d - 1, s });
	}
}

void settingInitialCloud() {
	cloud.assign(n, vector<bool>(n, false));

	cloud[n - 1][0] = true;
	cloud[n - 1][1] = true;
	cloud[n - 2][0] = true;
	cloud[n - 2][1] = true;
}

void renewClouds() {
	cloud.assign(n, vector<bool>(n, false));

	for (int i = 0; i < cloud.size(); i++) {
		for (int j = 0; j < cloud[i].size(); j++) {
			cloud[i][j] = copyC[i][j];
		}
	}
}

void moveClouds(int dir, int cnt) {
	copyC.assign(n, vector<bool>(n, false));

	for (int i = 0; i < cloud.size(); i++) {
		for (int j = 0; j < cloud[i].size(); j++) {
			if (cloud[i][j] == false) {
				continue;
			}

			int nx = i;
			int ny = j;

			for (int k = 0; k < cnt; k++) {
				nx = nx + dx[dir];
				ny = ny + dy[dir];

				if (nx < 0) {
					nx = n - 1;
				}
				else if (nx >= n) {
					nx = 0;
				}

				if (ny < 0) {
					ny = n - 1;
				}
				else if (ny >= n) {
					ny = 0;
				}
			}

			copyC[nx][ny] = true;
		}
	}

	renewClouds();
}

void plusWaterCount() {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (cloud[i][j] == false) {
				continue;
			}

			board[i][j]++;
		}
	}
}

void copyBoard() {
	copyB.assign(n, vector<int>(n, 0));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			copyB[i][j] = board[i][j];
		}
	}
}

int checkBasketCount(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dgx[i];
		int ny = y + dgy[i];

		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
			continue;
		}

		if (board[nx][ny] > 0) {
			cnt++;
		}
	}

	return cnt;
}

void renewOriginalBoard() {
	board.assign(n, vector<int>(n));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j] = copyB[i][j];
		}
	}
}

void copyWaters() {
	copyBoard();

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (cloud[i][j] == false) {
				continue;
			}

			int cnt = checkBasketCount(i, j);

			copyB[i][j] += cnt;
		}
	}

	renewOriginalBoard();
}

void makeClouds() {
	copyC.assign(n, vector<bool>(n, false));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (cloud[i][j] == true) {
				continue;
			}

			if (board[i][j] >= 2) {
				board[i][j] -= 2;

				copyC[i][j] = true;
			}
		}
	}

	renewClouds();
}

int getWaterSum() {
	int sum = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			sum += board[i][j];
		}
	}

	return sum;
}

void solution() {
	//비바라기 시전
	settingInitialCloud();

	// 구름 이동 반복문 시작
	for (int moving = 0; moving < m; moving++) {
		int dir = movingInfomations[moving].first;
		int movCnt = movingInfomations[moving].second;

		//모든 구름 이동
		moveClouds(dir, movCnt);

		//구름이 위치한 곳 물 + 1
		plusWaterCount();

		//물 복사 진행
		copyWaters();

		//구름 생성
		makeClouds();
	}
	
	int answer = getWaterSum();
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