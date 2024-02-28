#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<vector<int>> map;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; //동남서북

void input() {
	cin >> n >> m >> k;

	map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

vector<vector<int>> settingInitialDice() {
	vector<vector<int>> dice(4, vector<int>(3, 0));

	dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;

	return dice;
}

void moveDice(vector<vector<int>>& dice, int direction) {
	if (direction == 0) { //동쪽
		int temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
	}
	else if (direction == 1) { //남쪽
		int temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else if (direction == 2) { //서쪽
		int temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
	}
	else { //북쪽
		int temp = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = temp;
	}
}

int bfs(int a, int b, int num) {
	vector<vector<bool>> visit(map.size(), vector<bool>(map[0].size(), false));

	queue<pair<int, int>> q;

	int cnt = 0; //(a,b)로부터 같은 num을 가지고 있는 칸 개수

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

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}

			if (map[nx][ny] == num && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}

		}
	}

	return cnt;
}

void solution() {
	int answer = 0;

	int curDir = 0; //초기 방향 동쪽 
	int x = 0;
	int y = 0;

	vector<vector<int>> dice = settingInitialDice();

	for (int cnt = 0; cnt < k; cnt++) {
		int nx = x + dx[curDir];
		int ny = y + dy[curDir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
			//이동할 칸이 범위 밖이면
			//반대 방향으로 이동
			curDir = (curDir + 2) % 4;

			nx = x + dx[curDir];
			ny = y + dy[curDir];
		}

		moveDice(dice, curDir);

		int score = map[nx][ny];

		int availbleMovingCnt = bfs(nx, ny, map[nx][ny]);
		score *= availbleMovingCnt;

		answer += score;

		//다음 이동방향 결정
		int curMap = map[nx][ny]; //현재 칸 정수 값
		int curDice = dice[3][1]; //현재 주사위 아랫면

		if (curDice > curMap) {
			//90도 시계 방향
			curDir++;
			curDir %= 4;
		}
		else if (curDice < curMap) {
			//90도 반시계 방향
			curDir--;

			if (curDir < 0) {
				curDir = 3;
			}
		}

		x = nx;
		y = ny;
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
