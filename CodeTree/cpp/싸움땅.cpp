#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Player {
	int num;
	int x;
	int y;
	int direction;
	int ability; //초기 능력치
	int gunPower; //총 미소지시 0, 소지 시 총의 공격력
	int point; //획득 포이늩
};

int n, m, k; //n: 격자의 크기, m: 플레이어의 수, k: 라운드의 수
vector<vector<vector<int> > > board; //총의 공격력 보드
map<int, Player> playerMap;

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<vector<int> >(n, vector<int>(0)));

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;

			if (a > 0) {
				board[i][j].push_back(a);
			}
		}
	}

	int x, y, d, s;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> d >> s;

		Player player = { i, x - 1, y - 1, d, s, 0, 0 };
		playerMap[i] = player;
	}
}

int checkPlayerSpace(int x, int y, int exceptNum) {
	//(x, y)에 플레이어가 있으면 (num 플레이어 제외) 플레이어 번호 리턴, 없으면 -1 리턴
	for (pair<int, Player> player : playerMap) {
		int num = player.first;

		if (num == exceptNum) {
			continue;
		}

		int px = player.second.x;
		int py = player.second.y;

		if (x == px && y == py) {
			return num;
		}
	}

	return -1;
}

bool checkGunSpace(int x, int y) {
	//해당 칸에 총이 한 개라도 있으면 true, 없으면 false 리턴
	if (board[x][y].empty()) {
		return false;
	}

	return true;
}

pair<int, int> findWinner(int player1Num, int player2Num) { //이긴 플레이어 번호, 이긴 플레이어가 얻는 포인트 리턴
	int player1Ability = playerMap[player1Num].ability;
	int player1GunPower = playerMap[player1Num].gunPower;

	int player2Ability = playerMap[player2Num].ability;
	int player2GunPower = playerMap[player2Num].gunPower;

	int player1Sum = player1Ability + player1GunPower;
	int player2Sum = player2Ability + player2GunPower;

	if (player1Sum <= player2Sum) {
		if (player1Sum == player2Sum) {
			if (player1Ability < player2Ability) {
				return { player2Num, player2Sum - player1Sum };
			}
			return { player1Num, player1Sum - player2Sum };
		}
		return { player2Num, player2Sum - player1Sum };
	}
	return { player1Num, player1Sum - player2Sum };
}

pair<int, int> fight(int player1Num, int player2Num) { //이긴 플레이어 번호, 진 플레이어 번호 리턴
	pair<int, int> winnerInfo = findWinner(player1Num, player2Num);
	int winnerNum = winnerInfo.first;
	int winnerPoint = winnerInfo.second;

	playerMap[winnerNum].point += winnerPoint;
	
	int loserNum = -1;
	if (winnerNum == player1Num) {
		loserNum = player2Num;
	}
	else {
		loserNum = player1Num;
	}

	return { winnerNum, loserNum };
}

void proceedLoser(int loserNum) {
	int x = playerMap[loserNum].x;
	int y = playerMap[loserNum].y;
	int direction = playerMap[loserNum].direction;
	int gunPower = playerMap[loserNum].gunPower;

	//총을 격자에 내려놓음
	board[x][y].push_back(gunPower);
	playerMap[loserNum].gunPower = 0;

	//이동
	int ndir = direction;
	int nx = x + dx[ndir];
	int ny = y + dy[ndir];

	//이동하려는 칸이 격자 밖이거나 다른 플레이어가 있다면 90도 오른쪽 회전
 	while (nx < 0 || ny < 0 || nx >= n || ny >= n || checkPlayerSpace(nx, ny, loserNum) != -1) {
		ndir = (ndir + 1) % 4;
		nx = x + dx[ndir];
		ny = y + dy[ndir];
	}

	playerMap[loserNum].x = nx;
	playerMap[loserNum].y = ny;
	playerMap[loserNum].direction = ndir;

	//해당 칸에 총이 있으면 가장 공격력 높은 총 획득
	if (checkGunSpace(playerMap[loserNum].x, playerMap[loserNum].y)) {
		int bx = playerMap[loserNum].x;
		int by = playerMap[loserNum].y;

		sort(board[bx][by].begin(), board[bx][by].end());

		playerMap[loserNum].gunPower = board[bx][by][board[bx][by].size() - 1];
		board[bx][by].pop_back();
	}
}

void proceedWinner(int winnerNum) {
	int x = playerMap[winnerNum].x;
	int y = playerMap[winnerNum].y;
	int gunPower = playerMap[winnerNum].gunPower;

	if (checkGunSpace(playerMap[winnerNum].x, playerMap[winnerNum].y)) {
		//해당 칸에 총이 1개 이상 있다면
		int bx = playerMap[winnerNum].x;
		int by = playerMap[winnerNum].y;

		sort(board[bx][by].begin(), board[bx][by].end());

		if (playerMap[winnerNum].gunPower == 0) {
			//플레이어가 총이 없으면 총 획득
			playerMap[winnerNum].gunPower = board[bx][by][board[bx][by].size() - 1];
			board[bx][by].pop_back();
		}
		else {
			//플레이어가 총을 가지고 있다면 공격력 제일 강한 것 획득 후, 나머지는 격자에 두기
			int playerGun = playerMap[winnerNum].gunPower;

			if (playerGun < board[bx][by][board[bx][by].size() - 1]) {
				playerMap[winnerNum].gunPower = board[bx][by][board[bx][by].size() - 1];
				board[bx][by].pop_back();
				board[bx][by].push_back(playerGun);
			}
		}
	}
}

void movePlayer(int playerNum) {
	//플레이어 한 칸 이동
	int num = playerNum;
	int x = playerMap[playerNum].x;
	int y = playerMap[playerNum].y;
	int dir = playerMap[playerNum].direction;

	int ndir = dir;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
		ndir = (dir + 2) % 4;
		nx = x + dx[ndir];
		ny = y + dy[ndir];
	}

	playerMap[num].x = nx;
	playerMap[num].y = ny;
	playerMap[num].direction = ndir;

	int anotherPlayerNum = checkPlayerSpace(playerMap[num].x, playerMap[num].y, num);

	if (anotherPlayerNum != -1) {
		//이동한 칸에 플레이어가 있다면
		pair<int, int> fightResult = fight(num, anotherPlayerNum);

		int winnerNum = fightResult.first;
		int loserNum = fightResult.second;

		proceedLoser(loserNum);

		proceedWinner(winnerNum);
	}
	else {
		//이동한 칸에 플레이어가 없다면
		//해당 칸의 총 유무 확인
		if (checkGunSpace(playerMap[num].x, playerMap[num].y)) {
			//해당 칸에 총이 1개 이상 있다면
			int bx = playerMap[num].x;
			int by = playerMap[num].y;

			sort(board[bx][by].begin(), board[bx][by].end());

			if (playerMap[num].gunPower == 0) {
				//플레이어가 총이 없으면 총 획득
				playerMap[num].gunPower = board[bx][by][board[bx][by].size() - 1];
				board[bx][by].pop_back();
			}
			else {
				//플레이어가 총을 가지고 있다면 공격력 제일 강한 것 획득 후, 나머지는 격자에 두기
				int playerGun = playerMap[num].gunPower;

				if (playerGun < board[bx][by][board[bx][by].size() - 1]) {
					playerMap[num].gunPower = board[bx][by][board[bx][by].size() - 1];
					board[bx][by].pop_back();
					board[bx][by].push_back(playerGun);
				}
			}
		}
	}
}

void solution() {
	for (int round = 1; round <= k; round++) {
		for (int playerNum = 1; playerNum <= m; playerNum++) {
			movePlayer(playerNum);
		}
	}

	for (pair<int, Player> player : playerMap) {
		cout << player.second.point << " ";
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