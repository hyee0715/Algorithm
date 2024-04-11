#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct It {
	int x;
	int y;
	int direction; //바라보는 방향
	int rootDirection; // 0: 중앙 -> 밖 / 1: 밖 -> 중앙
	int rootIdx; //루트 인덱스
	int score; //획득 점수
};

struct Player {
	int num;
	int x;
	int y;
	int direction; //바라보는 방향
	bool status; //false: 격자 위에서 사라짐, true: 이상 없음
};

int n, m, h, k; //n: 격자 크기, m: 도망자 수, h: 나무 개수, k: 턴 수
vector<vector<int> > treeBoard; //나무가 있는 곳은 1, 빈 칸은 0
map<int, Player> playerMap;
It it;

vector<pair<int, int> > itRoot;
vector<int> itRootDirections, itRootRevDirections;

int dx[] = { 0, 1, 0, -1 }; //동남서북
int dy[] = { 1, 0, -1, 0 };

void input() {
	cin >> n >> m >> h >> k;

	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;

		Player player = { i, a - 1, b - 1, c - 1, true };
		playerMap[i] = player;
	}

	treeBoard.assign(n, vector<int>(n, 0));

	for (int i = 0; i < h; i++) {
		cin >> a >> b;

		treeBoard[a - 1][b - 1] = 1;
	}
}

void getItRoot() {
	//술래의 달팽이 모양 루트와 루트 방향 구하기
	pair<int, int> it = { n / 2,  n / 2 };
	int dir = 3;

	int nx = it.first;
	int ny = it.second;
	int ndir = dir;
	itRoot.push_back({ nx, ny });

	int num = 1;
	bool flag = false;

	while (1) {

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= num; j++) {
				nx = nx + dx[ndir];
				ny = ny + dy[ndir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					flag = true;
					break;
				}

				itRoot.push_back({ nx, ny });
				itRootDirections.push_back(ndir);

			}

			if (flag) {
				break;
			}

			ndir = (ndir + 1) % 4;
		}

		if (flag) {
			break;
		}

		num++;
	}

	for (int i = 0; i < itRootDirections.size(); i++) {
		itRootRevDirections.push_back((itRootDirections[i] + 2) % 4);
	}
}

bool checkPlayer(Player player) {
	//이동 가능한 도망자이면 true, 아니면 false
	if (player.status == false) {
		return false;
	}

	int distance = abs(it.x - player.x) + abs(it.y - player.y);

	if (distance <= 3) {
		return true;
	}

	return false;
}

void movePlayer(Player player) {
	int ndir = player.direction;
	int nx = player.x + dx[ndir];
	int ny = player.y + dy[ndir];

	if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
		//격자를 벗어나는 경우
		ndir = (player.direction + 2) % 4;
		nx = player.x + dx[ndir];
		ny = player.y + dy[ndir];

		if (it.x == nx && it.y == ny) {
			//술래가 있는 경우 이동 X
			playerMap[player.num].direction = ndir;
		}
		else {
			//술래가 없는 경우 이동 O
			playerMap[player.num].direction = ndir;
			playerMap[player.num].x = nx;
			playerMap[player.num].y = ny;
		}
	}
	else {
		//격자를 안 벗어나는 경우
		if (it.x != nx || it.y != ny) {
			//술래가 없는 경우 이동 O
			playerMap[player.num].x = nx;
			playerMap[player.num].y = ny;
		}
	}
}

void moveIt() {
	if (it.rootIdx == 0 && it.rootDirection == 1) { //밖 -> 중앙으로 끝 칸
		it.rootIdx++;
		it.rootDirection = 0;
		it.direction = itRootDirections[it.rootIdx];
		it.x = itRoot[it.rootIdx].first;
		it.y = itRoot[it.rootIdx].second;
	}
	else if (it.rootIdx == 1 && it.rootDirection == 1) {//밖 -> 중앙 전 칸
		it.rootIdx--;
		it.x = itRoot[it.rootIdx].first;
		it.y = itRoot[it.rootIdx].second;
		it.direction = itRootDirections[it.rootIdx];
	}
	else if (it.rootIdx == itRoot.size() - 2 && it.rootDirection == 0) {//중앙 -> 밖으로 전 칸
		it.rootIdx++;
		it.x = itRoot[it.rootIdx].first;
		it.y = itRoot[it.rootIdx].second;
		it.direction = itRootRevDirections[it.rootIdx - 1];
	}
	else if (it.rootIdx == itRoot.size() - 1 && it.rootDirection == 0) {//중앙 -> 밖으로 끝 칸
		it.rootIdx--;
		it.rootDirection = 1;
		it.direction = itRootRevDirections[it.rootIdx - 1];
		it.x = itRoot[it.rootIdx].first;
		it.y = itRoot[it.rootIdx].second;
	}
	else {
		if (it.rootDirection == 0) {
			it.rootIdx++;
			it.direction = itRootDirections[it.rootIdx];
			it.x = itRoot[it.rootIdx].first;
			it.y = itRoot[it.rootIdx].second;
		}
		else {
			it.rootIdx--;
			it.direction = itRootRevDirections[it.rootIdx - 1];
			it.x = itRoot[it.rootIdx].first;
			it.y = itRoot[it.rootIdx].second;
		}
	}
}

vector<int> findAlivePlayer(int nx, int ny) { //(nx, ny)에 플레이어가 있으면 번호 배열 리턴, 없으면 빈 배열 리턴
	vector<int> nums;

	for (pair<int, Player> player : playerMap) {
		if (player.second.status == false) continue;

		if (player.second.x == nx && player.second.y == ny) {
			nums.push_back(player.first);
		}

	}

	return nums;
}

int catchPlayer() {
	//술래 방향으로부터 3칸. 잡힌 도망자의 수 리턴
	int count = 0;

	int nx = it.x;
	int ny = it.y;

	for (int i = 0; i < 3; i++) {
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		vector<int> playerNums = findAlivePlayer(nx, ny);
		if (treeBoard[nx][ny] == 0) {
			if (!playerNums.empty()) {
				count += playerNums.size();

				for (int j = 0; j < playerNums.size(); j++) {
					playerMap[playerNums[j]].status = false;
				}
			}
		}

		nx = nx + dx[it.direction];
		ny = ny + dy[it.direction];
	}

	return count;
}

void solution() {
	getItRoot();

	it = { n / 2, n / 2, 3, 0, 0, 0 };

	for (int turn = 1; turn <= k; turn++) {
		//턴 k번 반복

		for (pair<int, Player> player : playerMap) {
			//도망자 이동
			if (checkPlayer(player.second) == false) {
				continue;
			}

			movePlayer(player.second);
		}

		//술래 이동
		moveIt();

		int count = catchPlayer(); //잡힌 도망자의 수
		it.score += (turn * count);
	}

	cout << it.score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}