#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, c; //n: 격자의 크기, m: 박멸이 진행되는 년 수, k: 제초제의 확산 범위, c: 제초제가 남아있는 년 수
vector<vector<int> > board; //0: 빈 칸, -1: 벽, 1~100: 나무 그루 수
vector<vector<int> > herbicide; //제초제가 유지되는 년 수
int answer;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int diagX[] = { -1, 1, 1, -1 }; //대각선
int diagY[] = { 1, 1, -1, -1 };

void input() {
	cin >> n >> m >> k >> c;

	board.assign(n, vector<int>(n, 0));
	herbicide.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

int getNeighborTreeCount(int x, int y) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		if (board[nx][ny] > 0 && herbicide[nx][ny] == 0) {
			count++;
		}
	}

	return count;
}

void growUp() { //나무 성장
	vector<vector<int> > temp = board;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0 && herbicide[i][j] == 0) {
				int neighborCount = getNeighborTreeCount(i, j);

				temp[i][j] = board[i][j] + neighborCount;
			}
		}
	}

	board = temp;
}

int getNeighborEmptyCount(int x, int y) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		if (board[nx][ny] == 0 && herbicide[nx][ny] == 0) {
			count++;
		}
	}

	return count;
}

void propagateNeighborTree(int x, int y, int propagationCount, vector<vector<int> >& temp) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}


		if (board[nx][ny] == 0 && herbicide[nx][ny] == 0) {
			temp[nx][ny] += propagationCount;

		}
	}
}

void propagate() {
	vector<vector<int> > temp = board;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) {
				int neighborCount = getNeighborEmptyCount(i, j);

				if (neighborCount == 0) {
					continue;
				}

				int propagationCount = board[i][j] / neighborCount;

				propagateNeighborTree(i, j, propagationCount, temp);
			}
		}
	}

	board = temp;
}

int getRemovedCount(int x, int y) {
	int count = board[x][y];

	for (int i = 0; i < 4; i++) { //해당 칸으로부터 대각선 k칸
		for (int j = 1; j <= k; j++) {
			int nx = x + (diagX[i] * j);
			int ny = y + (diagY[i] * j);

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (board[nx][ny] == -1 || board[nx][ny] == 0) {
				break;
			}
			else {
				count += board[nx][ny];
			}
		}
	}

	return count;
}

bool removedTreeCountsCompare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first <= b.first.first) {
		if (a.first.first == b.first.first) {
			if (a.first.second <= b.first.second) {
				if (a.first.second == b.first.second) {
					if (a.second <= b.second) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return false;
	}
	return true;
}

pair<int, int> getRemovedTreeCount() { //제초제 뿌릴 중간 나무 위치 구하기
	vector<pair<pair<int, int>, int> > removedTreeCounts;  //나무 당 박멸되는 나무 수 구하기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) {
				//나무가 있는 칸 중 제초제 뿌렸을 때 박멸되는 나무 수 구하기
				int removedCount = getRemovedCount(i, j);

				removedTreeCounts.push_back({ {removedCount, i}, j });
			}
		}
	}

	if (removedTreeCounts.empty()) {
		return { -1, -1 };
	}

	//가장 많이 박멸되는 칸 찾기
	//정렬 후 맨 앞 값 뽑기
	sort(removedTreeCounts.begin(), removedTreeCounts.end(), removedTreeCountsCompare);

	return { removedTreeCounts[0].first.second, removedTreeCounts[0].second };
}

void removeTrees(int x, int y) {
	answer += board[x][y];
	board[x][y] = 0;
	herbicide[x][y] = c + 1;

	for (int i = 0; i < 4; i++) { //해당 칸으로부터 대각선 k칸
		for (int j = 1; j <= k; j++) {
			int nx = x + (diagX[i] * j);
			int ny = y + (diagY[i] * j);

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			herbicide[nx][ny] = c + 1;

			if (board[nx][ny] > 0) {
				answer += board[nx][ny];
				board[nx][ny] = 0;
				continue;
			}

			if (board[nx][ny] == -1 || board[nx][ny] == 0) {
				break;
			}
		}
	}
}

void setHerbicide() {
	pair<int, int> targetTree = getRemovedTreeCount(); //제초제 뿌릴 중간 나무 위치 구하기. 없으면 -1,-1 리턴

	if (targetTree.first == -1 && targetTree.second == -1) {
		return;
	}

	removeTrees(targetTree.first, targetTree.second);
}

void removeHerbicide() { //제초제 1년 줄이기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (herbicide[i][j] > 0) {
				herbicide[i][j]--;
			}
		}
	}
}

void solution() {
	answer = 0;

	for (int round = 0; round < m; round++) {
		growUp();

		propagate();

		setHerbicide();

		removeHerbicide();
	}

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