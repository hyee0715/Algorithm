#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Knight {
	int num;
	bool status;
	int health;
	int damage;
	int r; //좌측 상단 행
	int c; //좌측 상단 열
	int h; //높이
	int w; //너비
};

int l, n, q; //l: 체스판의 크기, n: 기사의 수, q: 명령의 수
vector<vector<int> > board; //0: 빈칸, 1: 함정, 2: 벽
map<int, Knight> knightMap;
vector<pair<int, int> > orders; //기사 번호, 방향
vector<vector<int> > knightBoard;

int dx[] = { -1, 0, 1, 0 }; //상우하좌
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
		Knight knight = { i, true, k, 0, r - 1, c - 1, h, w };
		knightMap[i] = knight;
	}

	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		orders.push_back({ a, b });
	}
}

void settingKnightBoard(int num, int r, int c, int h, int w) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			knightBoard[i][j] = num;
		}
	}
}

void settingCurrentKnight() {
	knightBoard.assign(l, vector<int>(l, 0));

	for (pair<int, Knight> knight : knightMap) {
		int num = knight.first;
		int status = knight.second.status;

		if (!status) {
			continue;
		}

		int r = knight.second.r;
		int c = knight.second.c;
		int h = knight.second.h;
		int w = knight.second.w;

		settingKnightBoard(num, r, c, h, w);
	}
}

bool checkBoard(int num, int r, int c, int h, int w) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			if (i < 0 || j < 0 || i >= l || j >= l) { //주어진 영역 밖이면 false 리턴
				return false;
			}

			if (board[i][j] == 2) { //움직이려는 영역에 벽이 있으면 false 리턴
				return false;
			}
		}
	}

	return true;
}

bool movingCheck(int num, int r, int c, int h, int w, int dir) {
	if (!checkBoard(num, r, c, h, w)) { //움직이려는 영역이 주어진 영역 밖이거나, 벽이 있으면 -1리턴
		return false;
	}

	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			if (knightBoard[i][j] != 0 && knightBoard[i][j] != num) {
				int nextKnightNum = knightBoard[i][j];
				int nr = knightMap[nextKnightNum].r + dx[dir];
				int nc = knightMap[nextKnightNum].c + dy[dir];
				int nh = knightMap[nextKnightNum].h;
				int nw = knightMap[nextKnightNum].w;

				if (!movingCheck(nextKnightNum, nr, nc, nh, nw, dir)) {
					return false;
				}
			}
		}
	}

	return true;
}

bool isPossible(int num, int dir) { //명령 수행 가능한지 확인
	int r = knightMap[num].r;
	int c = knightMap[num].c;
	int h = knightMap[num].h;
	int w = knightMap[num].w;

	int nr = r + dx[dir];
	int nc = c + dy[dir];

	return movingCheck(num, nr, nc, h, w, dir);
}

void move(vector<int>& knights, map<int, bool>& visit, int num, int r, int c, int h, int w, int dir) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
			if (knightBoard[i][j] != 0 && knightBoard[i][j] != num && visit[knightBoard[i][j]] == false) {
				int nextKnightNum = knightBoard[i][j];
				int nr = knightMap[nextKnightNum].r + dx[dir];
				int nc = knightMap[nextKnightNum].c + dy[dir];
				int nh = knightMap[nextKnightNum].h;
				int nw = knightMap[nextKnightNum].w;

				visit[nextKnightNum] = true;

				move(knights, visit, nextKnightNum, nr, nc, nh, nw, dir);
			}
		}
	}

	knightMap[num].r = r;
	knightMap[num].c = c;

	knights.push_back(num);
}

vector<int> moveKnights(int num, int dir) {
	vector<int> knights;
	map<int, bool> visit;

	int r = knightMap[num].r;
	int c = knightMap[num].c;
	int h = knightMap[num].h;
	int w = knightMap[num].w;

	int nr = r + dx[dir];
	int nc = c + dy[dir];

	move(knights, visit, num, nr, nc, h, w, dir);

	return knights;
}

void damage(vector<int>& knights) {
	for (int num : knights) {
		int r = knightMap[num].r;
		int c = knightMap[num].c;
		int h = knightMap[num].h;
		int w = knightMap[num].w;

		int cnt = 0;

		for (int i = r; i < r + h; i++) {
			for (int j = c; j < c + w; j++) {
				if (board[i][j] == 1) {
					cnt++;
				}
			}
		}

		knightMap[num].damage += cnt;

		if (knightMap[num].health <= knightMap[num].damage) {
			knightMap[num].status = false;
		}
	}
}

void solution() {
	for (int round = 0; round < q; round++) {
		int orderedKightNum = orders[round].first;
		int orderedDir = orders[round].second;

		if (knightMap[orderedKightNum].status == false) { //사라진 기사면 명령 무시
			continue;
		}

		settingCurrentKnight();

		if (!isPossible(orderedKightNum, orderedDir)) { //벽 때문에 이동이 불가능하면 넘어가기
			continue;
		}

		vector<int> movedKnightNums = moveKnights(orderedKightNum, orderedDir);

		settingCurrentKnight();

		movedKnightNums.pop_back(); //명령 받은 기사는 제외하기

		damage(movedKnightNums); //대결 대미지 입히기

		settingCurrentKnight();
	}

	int answer = 0;

	for (pair<int, Knight> knight : knightMap) {
		int status = knight.second.status;
		int damage = knight.second.damage;

		if (!status) {
			continue;
		}

		answer += damage;
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