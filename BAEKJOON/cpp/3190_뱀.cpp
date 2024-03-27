#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <deque>
using namespace std;

struct Snake {
	int headX;
	int headY;
	set<pair<int, int>> bodySet;
	deque<pair<int, int>> bodyDq; //머리 ~ 꼬리
	int direction;
};

int n, k, l;
set<pair<int, int>> apples;
unordered_map<int, char> dirInfo; //회전하는 시간(초), 방향
Snake snake;

int dx[] = { 0, 1, 0, -1 }; //동남서북
int dy[] = { 1, 0, -1, 0 };


void input() {
	cin >> n;
	cin >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;

		apples.insert({ a - 1, b - 1 });
	}

	cin >> l;

	char c;
	for (int i = 0; i < l; i++) {
		cin >> a >> c;
		dirInfo[a] = c;
	}
}

void initializeSnake() {
	snake.headX = 0;
	snake.headY = 0;
	snake.bodySet.insert({ 0, 0 });
	snake.bodyDq.push_back({ 0, 0 });
	snake.direction = 0;
}

void solution() {
	initializeSnake();

	int seconds = 1;

	while (1) {
		deque<pair<int, int>> dq;
		dq = snake.bodyDq;

		int nx = snake.headX + dx[snake.direction];
		int ny = snake.headY + dy[snake.direction];

		//이동할 칸이 벽이나 몸이면 종료
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			break;
		}

		if (snake.bodySet.find({ nx, ny }) != snake.bodySet.end()) {
			break;
		}
			
		if (apples.find({ nx, ny }) != apples.end()) {
			snake.headX = nx;
			snake.headY = ny;
			snake.bodySet.insert({ nx, ny });
			snake.bodyDq.push_front({ nx, ny });

			apples.erase({ nx, ny });
		}
		else {
			int tailX = snake.bodyDq.back().first;
			int tailY = snake.bodyDq.back().second;

			snake.bodySet.erase({ tailX, tailY });
			snake.bodyDq.pop_back();

			snake.headX = nx;
			snake.headY = ny;

			snake.bodySet.insert({ nx, ny });
			snake.bodyDq.push_front({ nx, ny });
		}

		if (dirInfo.count(seconds) != 0) { //뱀 회전 시간

			char dir = dirInfo[seconds];

			int nDir = snake.direction;
			if (dir == 'D') {
				nDir = nDir + 1;

				if (nDir == 4) {
					nDir = 0;
				}
			}
			else {
				nDir = nDir - 1;

				if (nDir == -1) {
					nDir = 3;
				}
			}

			snake.direction = nDir;
		}

		seconds++;
	}

	cout << seconds;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}