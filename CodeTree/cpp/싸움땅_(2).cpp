#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct Player {
	int num;
	int x;
	int y;
	int dir;
	int power; //초기 능력치(공격력)
	int gun; //가지고 있는 총의 공격력
	int point; //누적 포인트
};

int n, m, k; //n: 격자의 크기, m: 플레이어의 수, k: 라운드의 수
vector<vector<vector<int> > > board; //0: 빈 칸, 1이상: 총 공격력
map<int, Player> playerMap;

int dx[] = {-1, 0, 1, 0}; //북동남서
int dy[] = {0, 1, 0, -1};

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<vector<int> >(n, vector<int>(0)));

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;

			if (a == 0) {
				continue;
			}

			board[i][j].push_back(a);
		}
	}

	int x, y, d, s;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> d >> s;

		Player player = {i, x - 1, y - 1, d, s, 0, 0};
		playerMap[i] = player;
	}
}

void movePlayer(int playerNum) {
	Player player = playerMap[playerNum];

	int x = player.x;
	int y = player.y;
	int dir = player.dir;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
		dir = (dir + 2) % 4;

		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	playerMap[playerNum].x = nx;
	playerMap[playerNum].y = ny;
	playerMap[playerNum].dir = dir;
}

int checkSpace(int playerNum) { //이동한 칸에 현 플레이어 외의 다른 플레이어가 있는지 체크. 있으면 그 플레이어 번호 반환, 없으면 -1 반환
	int anotherNum = -1;

	int px = playerMap[playerNum].x;
	int py = playerMap[playerNum].y;

	for (pair<int, Player> player : playerMap) {
		int num = player.first;
		int x = player.second.x;
		int y = player.second.y;

		if (px == x && py == y && playerNum != num) {
			anotherNum = num;
		}
	}

	return anotherNum;
}

bool checkPlayerGunStatus(int playerNum) { //플레이어가 총을 가지고 있는지 확인
	if (playerMap[playerNum].gun > 0) {
		return true;
	}

	return false;
}

void checkGunExistence(int playerNum, int x, int y) {// 그 칸에 플레이어가 없는 경우 총이 있는지 확인
	if (!board[x][y].empty()) { //총이 칸에 있는 경우
		if (!checkPlayerGunStatus(playerNum)) { //플레이어가 총을 가지고 있지 않으면 총 획득
			sort(board[x][y].begin(), board[x][y].end());
			int maxGun = board[x][y][board[x][y].size() - 1];

			playerMap[playerNum].gun = maxGun;
			board[x][y].pop_back();
		}
		else { //플레이어가 총을 가지고 있으면
			int playerGun = playerMap[playerNum].gun;
			board[x][y].push_back(playerGun);

			sort(board[x][y].begin(), board[x][y].end());
			int maxGun = board[x][y][board[x][y].size() - 1];

			playerMap[playerNum].gun = maxGun;
			board[x][y].pop_back();
		}
	}
}

void proceedWinner(int playerNum, int score1, int score2) {
	int score = abs(score1 - score2);
	playerMap[playerNum].point += score;
}

void putDownGun(int playerNum) { //총 반납
	int x = playerMap[playerNum].x;
	int y = playerMap[playerNum].y;
	int gun = playerMap[playerNum].gun;

	board[x][y].push_back(gun);
	playerMap[playerNum].gun = 0;
}

bool checkPlayer(int playerNum, int nx, int ny) {
	for (pair<int, Player> player : playerMap) {
		int num = player.second.num;
		int x = player.second.x;
		int y = player.second.y;

		if (num == playerNum) {
			continue;
		}

		if (x == nx && y == ny) {
			return true;
		}
	}

	return false;
}

void moveLoser(int playerNum) {
	int x = playerMap[playerNum].x;
	int y = playerMap[playerNum].y;
	int dir = playerMap[playerNum].dir;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (nx < 0 || ny < 0 || nx >= n || ny >= n || checkPlayer(playerNum, nx, ny)) { //이동하려는 칸에 다른 플레이어가 있거나 범위 밖이면 오른쪽 90도 회전
		dir = (dir + 1) % 4;
		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	playerMap[playerNum].x = nx;
	playerMap[playerNum].y = ny;
	playerMap[playerNum].dir = dir;

	x = playerMap[playerNum].x;
	y = playerMap[playerNum].y;

	if (!board[x][y].empty()) { //이동한 곳에 총이 있으면 가장 공격력 높은 총 획득
		sort(board[x][y].begin(), board[x][y].end());
		int maxGun = board[x][y][board[x][y].size() - 1];

		playerMap[playerNum].gun = maxGun;
		board[x][y].pop_back();
	}
}

void proceedLoser(int playerNum) {
	if (playerMap[playerNum].gun > 0) { //총을 들고 있으면 총 내려놓음
		putDownGun(playerNum);
	}

	moveLoser(playerNum);
}

void updateWinnerGun(int playerNum) {
	int x = playerMap[playerNum].x;
	int y = playerMap[playerNum].y; 
	if (!board[x][y].empty()) {
		if (!checkPlayerGunStatus(playerNum)) { //플레이어가 총을 가지고 있지 않으면 총 획득
			sort(board[x][y].begin(), board[x][y].end());
			int maxGun = board[x][y][board[x][y].size() - 1];

			playerMap[playerNum].gun = maxGun;
			board[x][y].pop_back();
		}
		else { //플레이어가 총을 가지고 있으면
			int playerGun = playerMap[playerNum].gun;
			board[x][y].push_back(playerGun);

			sort(board[x][y].begin(), board[x][y].end());
			int maxGun = board[x][y][board[x][y].size() - 1];

			playerMap[playerNum].gun = maxGun;
			board[x][y].pop_back();
		}
	}
}

void fight(int currentPlayerNum, int anotherPlayerNum) {
	int cpScore = playerMap[currentPlayerNum].power + playerMap[currentPlayerNum].gun;
	int apScore = playerMap[anotherPlayerNum].power + playerMap[anotherPlayerNum].gun;

	int winnerNum = -1;
	int loserNum = -1;

	if (cpScore < apScore) {
		winnerNum = anotherPlayerNum;
		loserNum = currentPlayerNum;
	}
	else if (cpScore > apScore) {
		winnerNum = currentPlayerNum;
		loserNum = anotherPlayerNum;
	}
	else {
		if (playerMap[currentPlayerNum].power < playerMap[anotherPlayerNum].power) {
			winnerNum = anotherPlayerNum;
			loserNum = currentPlayerNum;
		}
		else {
			winnerNum = currentPlayerNum;
			loserNum = anotherPlayerNum;
		}
	}

	proceedWinner(winnerNum, cpScore, apScore); //이긴 플레이어 처리
	
	proceedLoser(loserNum); //진 플레이어 처리

	updateWinnerGun(winnerNum); //이긴 플레이어는 승리한 칸에서 가장 공격력이 높은 총 획득
}

void solution() {
	for (int round = 0; round < k; round++) {
		for (pair<int, Player> player : playerMap) {
			int num = player.first;

			movePlayer(num);

			int anotherPlayerNum = checkSpace(num);
			if (anotherPlayerNum == -1) { //그 칸에 아무도 없으면
				checkGunExistence(num, playerMap[num].x, playerMap[num].y);
			}
			else { //있으면 싸움
				fight(num, anotherPlayerNum);
			}
		}
	}

	for (pair<int, Player> player : playerMap) {
		int point = player.second.point;

		cout << point << " ";
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