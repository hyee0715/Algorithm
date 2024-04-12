#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, c; //n: 격자의 크기, m: 박멸이 진행되는 년 수, k: 제초제 확산 범위, c: 제초제가 남아있는 년 수
vector<vector<int> > board; //-1: 벽, 0: 빈칸, 1~100: 나무 그루 수
vector<vector<int> > herbicide; //제초제 남은 년 수

vector<vector<int> > dgx, dgy;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int answer = 0;

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

void getDiagonalDirections() {
	dgx.assign(4, vector<int>(0));
	dgy.assign(4, vector<int>(0));

	vector<int> gx = { -1, -1, 1, 1 };
	vector<int> gy = { 1, -1, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int x = 0;
		int y = 0;

		for (int j = 1; j <= k; j++) {
			int nx = x + gx[i];
			int ny = y + gy[i];

			dgx[i].push_back(nx);
			dgy[i].push_back(ny);

			x = nx;
			y = ny;
		}
	}
}

vector<vector<int> > copyBoard() {
	vector<vector<int> > ret(board.size(), vector<int>(board[0].size(), 0));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			ret[i][j] = board[i][j];
		}
	}

	return ret;
}

void renewBoard(vector<vector<int> >& temp) {
	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			board[i][j] = temp[i][j];
		}
	}
}

int countNeightborTreeCount(int x, int y) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		if (board[nx][ny] > 0) {
			count++;
		}
	}

	return count;
}

void growUp() {
	vector<vector<int> > temp = copyBoard();

	//각 나무당 인접한 4개의 칸 중 나무가 있는 칸 수 세기
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0) {
				int count = countNeightborTreeCount(i, j);

				temp[i][j] = board[i][j] + count;
			}
		}
	}

	renewBoard(temp);
}

vector<pair<int, int> > countNeightboarEmptyCount(int x, int y) { //인접 빈칸 좌표 리턴
	vector<pair<int, int> > ret;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		if (board[nx][ny] == 0 && herbicide[nx][ny] == 0) {
			ret.push_back({ nx, ny });
		}
	}

	return ret;
}

void breeding() {
	vector<vector<int> > temp = copyBoard();

	//인접 빈칸 개수 세기(벽, 다른 나무, 제초제 X)
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0) {
				vector<pair<int, int> > ret = countNeightboarEmptyCount(i, j);
				int size = ret.size();

				if (size == 0) {
					continue;
				}

				//현재 나무 그루 수 / 인접 빈칸 수 를 인접 빈칸에 추가.
				int count = board[i][j] / size;

				for (int k = 0; k < ret.size(); k++) {
					int nx = ret[k].first;
					int ny = ret[k].second;

					temp[nx][ny] += count;
				}
			}
		}
	}

	renewBoard(temp);
}

int getDeathTreeCount(int x, int y, int cur) {
	int count = cur;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < dgx[i].size(); j++) {
			int nx = x + dgx[i][j];
			int ny = y + dgy[i][j];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				break;
			}
			else if (board[nx][ny] <= 0) {
				break;
			}
			else {
				count += board[nx][ny];
			}
		}
	}

	return count;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
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

pair<pair<int, int>, int > getDeathTreeSpace() {
	vector<pair<pair<int, int>, int> > trees;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0) {
				//제초제 뿌리는 경우 죽는 나무 수 구하기 (벽, 나무없는 칸이면 멈추기)
				int count = getDeathTreeCount(i, j, board[i][j]);

				trees.push_back({ {count, i}, j });
			}
		}
	}

	if (trees.empty()) {
		return { {-1, -1}, -1 };
	}

	//제초제 뿌릴 장소 정하기
	sort(trees.begin(), trees.end(), compare);

	int selectTreeCount = trees[0].first.first;
	int selectTreeX = trees[0].first.second;
	int selectTreeY = trees[0].second;

	return { {selectTreeX, selectTreeY}, selectTreeCount };
}

void spray(int x, int y) {
	int years = c + 1;

	board[x][y] = 0;
	herbicide[x][y] = years;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < dgx[i].size(); j++) {
			int nx = x + dgx[i][j];
			int ny = y + dgy[i][j];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				break;
			}
			else if (board[nx][ny] <= 0) {
				herbicide[nx][ny] = years;
				break;
			}
			else {
				board[nx][ny] = 0;
				herbicide[nx][ny] = years;
			}
		}
	}
}

void sprayHerbicide() {
	pair<pair<int, int>, int> selectedSpace = getDeathTreeSpace();

	if (selectedSpace.first.first == -1 && selectedSpace.first.second == -1 && selectedSpace.second == -1) {
		return;
	}

	//박멸 나무 수 추가 (answer)
	answer += selectedSpace.second;

	//제초제 뿌릴 장소 정했으면 제초제 뿌림
	spray(selectedSpace.first.first, selectedSpace.first.second);
}

void reduceHerbicideYear() {
	for (int i = 0; i < herbicide.size(); i++) {
		for (int j = 0; j < herbicide[i].size(); j++) {
			if (herbicide[i][j] > 0) {
				herbicide[i][j]--;
			}
		}
	}
}

void solution() {
	getDiagonalDirections();

	for (int years = 1; years <= m; years++) {
		growUp();

		breeding();

		sprayHerbicide();

		reduceHerbicideYear();
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