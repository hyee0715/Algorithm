#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
unordered_map<int, unordered_set<int>> info; //번호, 친한 친구
vector<vector<int>> board;
vector<int> seq;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n;

	board.assign(n, vector<int>(n , 0));
	
	int a, b, c, d, e;
	for (int i = 0; i < n * n; i++) {
		cin >> a >> b >> c >> d >> e;

		info[a].insert(b);
		info[a].insert(c);
		info[a].insert(d);
		info[a].insert(e);

		seq.push_back(a);
	}
}

pair<int, int> check(int x, int y, int studentNum) {
	int fav = 0;
	int empty = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
			continue;
		}

		if (board[nx][ny] == 0) {
			empty++;
		}
		else if (info[studentNum].find(board[nx][ny]) != info[studentNum].end()) {
			fav++;
		}
	}

	return { fav, empty };
}

bool compare(pair<pair<pair<int, int>, int>, int> a, pair<pair<pair<int, int>, int>, int> b) {
	if (a.first.first.first >= b.first.first.first) {
		if (a.first.first.first == b.first.first.first) {
			if (a.first.first.second >= b.first.first.second) {
				if (a.first.first.second == b.first.first.second) {
					if (a.first.second >= b.first.second) {
						if (a.first.second == b.first.second) {
							if (a.second >= b.second) {
								if (a.second < b.second) {
									return true;
								}
								return false;
							}
							return true;
						}
						return false;
					}
					return true;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

pair<int, int> search(int studentNum) {
	vector<pair<pair<pair<int, int>, int>, int>> spaces; //인접한 칸의 좋아하는 학생 수, 비어있는 칸, 행, 열

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				pair<int, int> spaceInfo = check(i, j, studentNum);

				spaces.push_back({{{spaceInfo.first, spaceInfo.second}, i}, j });
			}
		}
	}
	
	sort(spaces.begin(), spaces.end(), compare);

	return { spaces[0].first.second, spaces[0].second };
}

int getSatisfaction(int x, int y) {
	int satisfaction = 0;
	int studentNum = board[x][y];
	unordered_set<int> fav = info[studentNum];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
			continue;
		}

		if (fav.find(board[nx][ny]) != fav.end()) {
			satisfaction++;
		}
	}

	if (satisfaction == 2) {
		return 10;
	}
	else if (satisfaction == 3) {
		return 100;
	}
	else if (satisfaction == 4) {
		return 1000;
	}

	return satisfaction;
}

void solution() {
	int answer = 0;

	for (int student : seq) {
		pair<int, int> sp = search(student);

		board[sp.first][sp.second] = student;
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			answer += getSatisfaction(i, j);
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