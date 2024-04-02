#include <iostream>
#include <vector>
using namespace std;

struct FireBall {
	int x; //x 좌표
	int y; //y 좌표
	int mass; //질량
	int direction; //방향
	int speed; //속력
};

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, m, k; //n : 격자 사이즈, m : 파이어볼 개수, k : 상어의 이동 명령 횟수

vector<FireBall> fireBalls;
vector<vector<vector<FireBall>>> board;

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<vector<FireBall>>(n, vector<FireBall>(0)));

	int r, c, e, s, d;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> e >> s >> d;

		FireBall fb = {r - 1, c - 1, e, d, s};
		fireBalls.push_back(fb);
	}
}

void moveFireBalls() {
	for (int i = 0; i < fireBalls.size(); i++) {
		int x = fireBalls[i].x;
		int y = fireBalls[i].y;
		int dir = fireBalls[i].direction;
		int speed = fireBalls[i].speed;

		for (int j = 0; j < speed; j++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0) {
				nx = board.size() - 1;
			}

			if (ny < 0) {
				ny = board[0].size() - 1;
			}

			if (nx >= board.size()) {
				nx = 0;
			}

			if (ny >= board[0].size()) {
				ny = 0;
			}

			x = nx;
			y = ny;
		}

		fireBalls[i].x = x;
		fireBalls[i].y = y;
	}
}

void settingBoard() {
	board.assign(n, vector<vector<FireBall>>(n, vector<FireBall>(0)));

	for (FireBall fb : fireBalls) {
		board[fb.x][fb.y].push_back(fb);
	}
}

bool validateFireBallsDirections(vector<FireBall>& fbs) {
	//파이어볼 방향이 모두 홀/짝 이면 true 리턴
	//아니면 false 리턴

	bool isEven = false;

	if (fbs[0].direction % 2 == 0) {
		isEven = true;
	}

	for (int i = 1; i < fbs.size(); i++) {
		if (fbs[i].direction % 2 == 0) {
			if (!isEven) {
				return false;
			}
		}
		else {
			if (isEven) {
				return false;
			}
		}
	}

	return true;
}

void proceedFireBalls() {
	int massSum = 0;
	int speedSum = 0;
	int size = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {

			if (board[i][j].size() >= 2) {
				massSum = 0;
				speedSum = 0;

				vector<FireBall> fbs = board[i][j];
				size = fbs.size();

				for (FireBall fb : fbs) {
					massSum += fb.mass;
					speedSum += fb.speed;
				}

				int dividedMass = massSum / 5;
				int dividedSpeed = speedSum / size;

				board[i][j].clear();

				if (dividedMass == 0) {
					continue;
				}

				if (validateFireBallsDirections(fbs)) { //동서남북
					for (int k = 0; k <= 6; k += 2) {
						FireBall nfb = {fbs[0].x, fbs[0].y, dividedMass, k, dividedSpeed};
						board[i][j].push_back(nfb);
					}
				}
				else { //대각선
					for (int k = 1; k <= 7; k += 2) {
						FireBall nfb = { fbs[0].x, fbs[0].y, dividedMass, k, dividedSpeed };
						board[i][j].push_back(nfb);
					}
				}
			}
		}
	}
}

int getMassSum() {
	int sum = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			for (int k = 0; k < board[i][j].size(); k++) {

				sum += board[i][j][k].mass;
			}
		}
	}

	return sum;
}

void renewFireBallsArr() {
	fireBalls.clear();

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				fireBalls.push_back(board[i][j][k]);
			}
		}
	}
}

void solution() {
	for (int cnt = 0; cnt < k; cnt++) {
		moveFireBalls();

		settingBoard();

		proceedFireBalls();

		renewFireBallsArr();
	}

	int answer = getMassSum();
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