#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
int answer = 0;

void input() {
	cin >> n;

	map.assign(n, vector<int>(n));

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			map[i][j] = a;
		}
	}
}

void calculate(int curDx, int curDy, vector<int>& dx, vector<int>& dy, int amount, int amountCopy, vector<double>& rate) {
	for (int i = 0; i < 9; i++) {
		int nx = curDx + dx[i];
		int ny = curDy + dy[i];
		int nextAmount = amount * rate[i];
		amountCopy -= nextAmount;

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			answer += nextAmount;
		}
		else {
			map[nx][ny] += nextAmount;
		}
	}

	int nx = curDx + dx[9];
	int ny = curDy + dy[9];
	if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
		answer += amountCopy;
	}
	else {
		map[nx][ny] += amountCopy;
	}
	map[curDx][curDy] = 0;
}

void solution() {

	vector<int> dx = { 0, 1, 0, -1 };
	vector<int> dy = { -1, 0, 1, 0 };

	vector<double> rate = { 0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01 };

	vector<int> westDx = { 0, 1, -1, 2, 1, -1, -2, 1, -1, 0};
	vector<int> westDy = { -2, -1, -1, 0, 0, 0, 0, 1, 1, -1};
	
	vector<int> eastDx = { 0, -1, 1, -2, -1, 1, 2, -1, 1, 0};
	vector<int> eastDy = { 2, 1, 1, 0, 0, 0, 0, -1, -1, 1 };

	vector<int> northDx = { -2, -1, -1, 0, 0, 0, 0, 1, 1, -1};
	vector<int> northDy = { 0, -1, 1, -2, -1, 1, 2, -1, 1, 0 };

	vector<int> southDx = { 2, 1, 1, 0, 0, 0, 0, -1, -1, 1 };
	vector<int> southDy = { 0, 1, -1, 2, 1, -1, -2, 1, -1, 0 };
	
	int curDx = n / 2, curDy = n / 2;

	int cnt = 1; //움직일 칸 개수 (1부터 1씩 늘어남)
	int dirCnt = 0; //2방향 씩 진행 (서남 - 동북)
	int dir = 0; //진행 방향

	while (1) {
		if (curDx == 0 && curDy == 0) {
			break;
		}

		for (int i = 0; i < cnt; i++) {
			curDx = curDx + dx[dir];
			curDy = curDy + dy[dir];
			int amount = map[curDx][curDy];
			int amountCopy = amount;

			if (dir == 0) {
				calculate(curDx, curDy, westDx, westDy, amount, amountCopy, rate);
			}
			else if (dir == 1) {
				calculate(curDx, curDy, southDx, southDy, amount, amountCopy, rate);
			}
			else if (dir == 2) {
				calculate(curDx, curDy, eastDx, eastDy, amount, amountCopy, rate);
			}
			else {
				calculate(curDx, curDy, northDx, northDy, amount, amountCopy, rate);
			}

			if (curDx == 0 && curDy == 0) {
				break;
			}
		}

		dir++;
		dir = dir % 4;

		dirCnt++;

		if (dirCnt == 2) {
			dirCnt = 0;

			cnt++;
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
