#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int x;
	int y;
	int speed;
	int direction;
	int size;
};

int dx[] = { 0, 1, 0, -1 }; //동남서북
int dy[] = { 1, 0, -1, 0 };

int r, c, m;
vector<vector<vector<Shark> > > board;
vector<Shark> sharks;
int anglerIdx = -1;
int answer = 0;

int convertDirection(int dir) {
	if (dir == 1) {
		return 3;
	}
	else if (dir == 2) {
		return 1;
	}
	else if (dir == 3) {
		return 0;
	}
	else {
		return 2;
	}
}

void input() {
	cin >> r >> c >> m;

	board.assign(r, vector<vector<Shark>>(c, vector<Shark>(0)));

	int r, c, s, d, z;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> s >> d >> z;

		int dir = convertDirection(d);

		Shark shark = { r - 1, c - 1, s, dir, z };
		sharks.push_back(shark);
	}
}

void settingSharksToBoard() {
	for (Shark shark : sharks) {
		int x = shark.x;
		int y = shark.y;

		board[x][y].push_back(shark);
	}
}

int findSharkIdx(Shark shark) {
	for (int i = 0; i < sharks.size(); i++) {
		int x = sharks[i].x;
		int y = sharks[i].y;
		int speed = sharks[i].speed;
		int direction = sharks[i].direction;
		int size = sharks[i].size;

		if (shark.x == x && shark.y == y && shark.speed == speed && shark.direction == direction && shark.size == size) {
			return i;
		}
	}

	return -1;
}

void removeShark() {
	for (int i = 0; i < board.size(); i++) {
		if (!board[i][anglerIdx].empty()) {
			Shark shark = board[i][anglerIdx][0];

			answer += shark.size;

			int sharkIdx = findSharkIdx(shark);
			sharks.erase(sharks.begin() + sharkIdx);

			board[i][anglerIdx].clear();

			break;
		}
	}
}

void moveSharks() {
	for (int i = 0; i < sharks.size(); i++) {
		int x = sharks[i].x;
		int y = sharks[i].y;
		int speed = sharks[i].speed;
		int direction = sharks[i].direction;

		if (speed == 0) {
			continue;
		}

		if (direction % 2 == 0) {
			speed = speed % ((c - 1) * 2);
		}
		else {
			speed = speed % ((r - 1) * 2);
		}

		int nDir = direction, nx = x, ny = y;

		for (int i = 0; i < speed; i++) {
			nDir = direction;
			nx = x + dx[direction];
			ny = y + dy[direction];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
				nDir = (direction + 2) % 4;
				nx = x + dx[nDir];
				ny = y + dy[nDir];
			}

			x = nx;
			y = ny;
			direction = nDir;
		}

		sharks[i].x = nx;
		sharks[i].y = ny;
		sharks[i].direction = nDir;
	}
}

bool sharkCompare(Shark a, Shark b) {
	if (a.size < b.size) {
		return false;
	}

	return true;
}

void removeDuplicatedShark() {
	//한 칸에 여러 상어가 있는 경우 크기가 가장 큰 상어 제외한 나머지 상어 모두 제거
	sharks.clear();

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j].size() > 1) {
				vector<Shark> v = board[i][j];

				sort(v.begin(), v.end(), sharkCompare);

				Shark shark = v[0];

				board[i][j].clear();
				board[i][j].push_back(shark);
				sharks.push_back(shark);

			}
			else if (board[i][j].size() == 1) {
				sharks.push_back(board[i][j][0]);
			}
		}
	}
}

void solution() {
	while (1) {
		if (sharks.empty()) {
			cout << answer;
			break;
		}

		settingSharksToBoard();

		//낚시왕 오른쪽 한 칸 이동
		anglerIdx++;
		if (anglerIdx == c) {
			cout << answer;
			break;
		}

		//낚시왕이 위치한 열의 상어 중 땅과 가장 가까운 상어 잡기
		removeShark();

		//상어 이동시키기
		moveSharks();

		board.clear();
		board.assign(r, vector<vector<Shark>>(c, vector<Shark>(0)));

		settingSharksToBoard();

		//한 칸에 여러 상어가 있는 경우 크기가 가장 큰 상어 제외한 나머지 상어 모두 제거
		removeDuplicatedShark();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}