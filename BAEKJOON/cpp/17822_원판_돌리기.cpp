#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, t; //n: 원판 개수, m: 원판 한 개의 정수 개수, t: 원판 회전 명령 수
vector<vector<int>> boards;
vector<vector<int>> orders;

void input() {
	cin >> n >> m >> t;

	boards.push_back({ -1 });

	int a, b, c;

	for (int i = 0; i < n; i++) {
		vector<int> v;

		for (int j = 0; j < m; j++) {
			cin >> a;
			v.push_back(a);
		}

		boards.push_back(v);
	}

	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;

		orders.push_back({ a, b, c });
	}
}

void moveClockWise(int boardNum) {
	int last = boards[boardNum][boards[boardNum].size() - 1];
	for (int i = boards[boardNum].size() - 2; i >= 0; i--) {
		boards[boardNum][i + 1] = boards[boardNum][i];
	}

	boards[boardNum][0] = last;
}

void moveCounterClockWise(int boardNum) {
	int first = boards[boardNum][0];
	for (int i = 1; i < boards[boardNum].size(); i++) {
		boards[boardNum][i - 1] = boards[boardNum][i];
	}

	boards[boardNum][boards[boardNum].size() - 1] = first;
}

void moveBoard(int boardNum, int dir, int moveCnt) {
	for (int i = 0; i < moveCnt; i++) {
		if (dir == 0) {
			moveClockWise(boardNum);
		}
		else {
			moveCounterClockWise(boardNum);
		}
	}
}

int removeAdjacentSameNumbers() { //인접하면서 같은 수를 지운 경우에는 -1 리턴, 지우지 않은 경우에는 0 리턴
	set<pair<int, int>> removeList;

	for (int i = 1; i < boards.size(); i++) {
		for (int j = 0; j < boards[i].size() - 1; j++) {
			if (boards[i][j] == boards[i][j + 1] && boards[i][j] != -1) {
				removeList.insert({ i, j });
				removeList.insert({ i, j + 1 });
			}
		}

		if (boards[i][0] == boards[i][boards[i].size() - 1] && boards[i][0] != -1) {
			removeList.insert({ i, 0 });
			removeList.insert({ i, boards[i].size() - 1 });
		}
	}


	for (int j = 0; j < boards[1].size(); j++) {
		for (int i = 1; i < boards.size() - 1; i++) {
			if (boards[i][j] == boards[i + 1][j] && boards[i][j] != -1) {
				removeList.insert({ i, j });
				removeList.insert({ i + 1, j });
			}
		}
	}

	if (removeList.empty()) {
		return 0;
	}

	for (pair<int, int> s : removeList) {
		int r = s.first;
		int c = s.second;

		boards[r][c] = -1;
	}

	return -1;
}

double getAverage() {
	int cnt = 0;
	int sum = 0;

	for (int i = 1; i < boards.size(); i++) {
		for (int j = 0; j < boards[i].size(); j++) {
			if (boards[i][j] != -1) {
				cnt++;
				sum += boards[i][j];
			}
		}
	}

	return (double)sum / cnt;
}

void changeNums(double avg) {
	for (int i = 1; i < boards.size(); i++) {
		for (int j = 0; j < boards[i].size(); j++) {
			if (boards[i][j] != -1) {
				if (boards[i][j] > avg) {
					boards[i][j]--;
				}
				else if (boards[i][j] < avg) {
					boards[i][j]++;
				}
			}
		}
	}
}

void solution() {
	for (int tc = 0; tc < t; tc++) {
		int boardNum = orders[tc][0];
		int dir = orders[tc][1];
		int moveCnt = orders[tc][2];

		for (int bNum = 1; bNum <= n; bNum++) {
			if (bNum % boardNum == 0) {
				moveBoard(bNum, dir, moveCnt);
			}
		}
		
		int result = removeAdjacentSameNumbers();
		
		if (result == 0) {
			double avg = getAverage();

			changeNums(avg);
		}
	}
	
	int answer = 0;

	for (int i = 1; i < boards.size(); i++) {
		for (int j = 0; j < boards[i].size(); j++) {
			if (boards[i][j] != -1) {
				answer += boards[i][j];
			}
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