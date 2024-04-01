#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, q;
vector<vector<int>> board;
vector<int> magic;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> q;

	board.assign(pow(2, n), vector<int>(pow(2, n)));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cin >> board[i][j];
		}
	}

	int a;
	for (int i = 0; i < q; i++) {
		cin >> a;

		magic.push_back(a);
	}
}

void rotate(int row, int col, int size) {
	queue<int> q;

	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			q.push(board[i][j]);
		}
	}

	for (int j = col + size - 1; j >= col; j--) {
		for (int i = row; i < row + size; i++) {
			board[i][j] = q.front();
			q.pop();
		}
	}
}

vector<vector<int>> copyBoard() {
	vector<vector<int>> temp(board.size(), vector<int>(board[0].size()));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			temp[i][j] = board[i][j];
		}
	}

	return temp;
}

void renewBoard(vector<vector<int>>& temp) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			board[i][j] = temp[i][j];
		}
	}
}

int getIceSum() {
	int sum = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			sum += board[i][j];
		}
	}

	return sum;
}

pair<int, int> getMaxIceLocation() {
	int maxNum = -1;
	int x = 0, y = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (maxNum < board[i][j]) {
				maxNum = board[i][j];
				x = i;
				y = j;
			}
		}
	}

	return { x, y };
}

int bfs(int a, int b, vector<vector<bool>>& visit) {
	int cnt = 0;

	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		cnt++;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
				continue;
			}
		
			if (board[nx][ny] > 0 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return cnt;
}

int getBiggestIce() {
	vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
	int biggestIceSize = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != 0 && visit[i][j] == false) {
				int size = bfs(i, j, visit);
				biggestIceSize = max(biggestIceSize, size);
			}
		}
	}

	return biggestIceSize;
}

void solution() {
	for (int cnt = 0; cnt < q; cnt++) {
		int l = magic[cnt]; //단계 L

		int divideSize = pow(2, l);

		//2^l * 2^l 크기의 부분 격자로 나누기
		//부분 격자들을 시계방향 90도 돌리기
		for (int i = 0; i < board.size(); i += divideSize) {
			for (int j = 0; j < board[i].size(); j += divideSize) {

				rotate(i, j, divideSize);
			}
		}

		vector<vector<int>> temp = copyBoard();

		//다 돌린 후, 얼음의 인접 얼음 칸이 3개 미만이면 얼음 수치 -1
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 0) {
					continue;
				}

				int cnt = 0;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == 0) {
						continue;
					}

					cnt++;
				}

				if (cnt < 3) {
					temp[i][j] = board[i][j] - 1;
				}
			}
		}

		renewBoard(temp);
	}

	//남아있는 얼음의 합
	int iceSum = getIceSum();

	if (iceSum == 0) {
		cout << "0\n0";
		return;
	}

	//남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
	int iceCnt = getBiggestIce();

	cout << iceSum << "\n" << iceCnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}