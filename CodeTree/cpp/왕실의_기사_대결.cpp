#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Knight {
	int num;
	int x;
	int y;
	int h;
	int w;
	int health;
	int damage;
	int status; //0: 사라진 상태, 1: 체스판 위
};

int l, n, q; // l: 체스판 크기, n: 기사의 수, q: 명령의 수
vector<vector<int> > board; //0: 빈칸, 1: 함정, 2: 벽
map<int, Knight> knightMap;
vector<pair<int, int> > orders; //기사 번호, 방향
vector<vector<int> > knightBoard, tempKnightBoard;

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> l >> n >> q;

	board.assign(l, vector<int>(l, 0));

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cin >> board[i][j];
		}
	}

	int r, c, h, w, k;
	for (int i = 1; i <= n; i++) {
		cin >> r >> c >> h >> w >> k;

		Knight knight = { i, r - 1, c - 1, h, w, k, 0, 1 };
		knightMap[i] = knight;
	}

	int e, d;
	for (int i = 0; i < q; i++) {
		cin >> e >> d;
		orders.push_back({ e, d });
	}
}

void renewNightBoard() {
	knightBoard.assign(tempKnightBoard.size(), vector<int>(tempKnightBoard[0].size(), 0));

	for (int i = 0; i < tempKnightBoard.size(); i++) {
		for (int j = 0; j < tempKnightBoard[i].size(); j++) {
			knightBoard[i][j] = tempKnightBoard[i][j];
		}
	}
}

void settingKnights() {
	knightBoard.assign(l, vector<int>(l, 0));

	for (pair<int, Knight> knight : knightMap) {
		int num = knight.first;
		int x = knight.second.x;
		int y = knight.second.y;
		int h = knight.second.h;
		int w = knight.second.w;
		int status = knight.second.status;

		if (status == 0) {
			continue;
		}

		for (int i = x; i < x + h; i++) {
			for (int j = y; j < y + w; j++) {
				knightBoard[i][j] = num;
			}
		}
	}
}

bool validateMoving(int knightNum, int direction) {
	int x = knightMap[knightNum].x;
	int y = knightMap[knightNum].y;
	int w = knightMap[knightNum].w;
	int h = knightMap[knightNum].h;

	int nx = x + dx[direction];
	int ny = y + dy[direction];

	for (int i = nx; i < nx + h; i++) {
		for (int j = ny; j < ny + w; j++) {
			if (i < 0 || j < 0 || i >= l || j >= l) {
				return false;
			}

			if (board[i][j] == 2) {
				return false;
			}
		}
	}

	for (int i = nx; i < nx + h; i++) {
		for (int j = ny; j < ny + w; j++) {
			if (knightBoard[i][j] != 0 && knightBoard[i][j] != knightNum) {
				if (validateMoving(knightBoard[i][j], direction) == false) {
					return false;
				}

			}
		}
	}

	return true;
}


void moveKnight(int knightNum, int direction, vector<bool>& visit) {
	int x = knightMap[knightNum].x;
	int y = knightMap[knightNum].y;
	int w = knightMap[knightNum].w;
	int h = knightMap[knightNum].h;

	int nx = x + dx[direction];
	int ny = y + dy[direction];

	visit[knightNum] = true;

	for (int i = nx; i < nx + h; i++) {
		for (int j = ny; j < ny + w; j++) {
			tempKnightBoard[i][j] = knightNum;

			if (knightBoard[i][j] != 0 && knightBoard[i][j] != knightNum) {
				if (visit[knightBoard[i][j]] == false) {
					moveKnight(knightBoard[i][j], direction, visit);
				}
			}
		}
	}
}

vector<int> updateKnightInformation() {
	vector<int> updatedKnightNums;
	vector<bool> visit(n + 1, false);

	for (int i = 0; i < knightBoard.size(); i++) {
		for (int j = 0; j < knightBoard[i].size(); j++) {
			if (tempKnightBoard[i][j] == 0) {
				continue;
			}

			int knightNum = tempKnightBoard[i][j];

			if (visit[knightNum] == false) {
				knightMap[knightNum].x = i;
				knightMap[knightNum].y = j;

				updatedKnightNums.push_back(knightNum);

				visit[knightNum] = true;
			}
		}
	}

	return updatedKnightNums;
}

void updateDamage(int orderedKnightNum, vector<int>& updatedKnightNums) {
	for (int num : updatedKnightNums) {
		if (num == orderedKnightNum) {
			continue;
		}

		int damageCnt = 0;

		for (int i = 0; i < knightBoard.size(); i++) {
			for (int j = 0; j < knightBoard[i].size(); j++) {
				if (knightBoard[i][j] == num && board[i][j] == 1) {
					damageCnt++;
				}
			}
		}

		knightMap[num].damage += damageCnt;
		knightMap[num].health -= damageCnt;

		if (knightMap[num].health <= 0) {
			knightMap[num].status = 0;
		}
	}
}

void solution() {
	for (int orderNum = 0; orderNum < orders.size(); orderNum++) {
		settingKnights();

		int knightNum = orders[orderNum].first;
		int direction = orders[orderNum].second;

		if (knightMap[knightNum].status == 0) {
			continue;
		}

		tempKnightBoard.assign(knightBoard.size(), vector<int>(knightBoard[0].size(), 0));

		if (validateMoving(knightNum, direction)) {
			vector<bool> visit(n + 1, false);
			moveKnight(knightNum, direction, visit);

			vector<int> updatedKnightNums = updateKnightInformation();
			renewNightBoard();

			updateDamage(knightNum, updatedKnightNums);
		}
	}

	int answer = 0;

	for (pair<int, Knight> knight : knightMap) {
		if (knight.second.status == 1) {
			answer += (knight.second.damage);
		}
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