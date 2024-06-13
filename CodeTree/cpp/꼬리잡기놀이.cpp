#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct Team {
	int num;
	vector<pair<int, int> > line;
	int people; //팀 구성원 수
	int head; //머리 사람 위치 (line 인덱스)
	bool dir; //방향 True: (3,2,1), False: (1,2,3)
	int score;
};

int n, m, k; //n: 격자의 크기, m: 팀의 개수, k: 라운드 수
vector<vector<int> > board;
map<int, Team> teamMap;

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

pair<pair<int, int>, vector<pair<int, int> > > getTeams(int a, int b, vector<vector<bool> >& visit) {
	vector<pair<int, int> > line;
	pair<int, int> head;
	pair<int, int> tail;
	int people = 0;

	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		line.push_back({ x, y });

		if (board[x][y] == 1) {
			head = { x, y };
		}

		if (board[x][y] >= 1 && board[x][y] <= 3) {
			people++;
		}


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (board[nx][ny] > 0 && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;

				break;
			}
		}
	}

	int headIdx = 0;

	for (int i = 0; i < line.size(); i++) {
		int x = line[i].first;
		int y = line[i].second;

		if (x == head.first && y == head.second) {
			headIdx = i;
		}
	}

	return { {headIdx, people}, line };
}

bool getDir(vector<pair<int, int> >& line) {
	queue<int> q;
	vector<int> v;

	for (int i = 0; i < line.size(); i++) {
		if (board[line[i].first][line[i].second] >= 1 && board[line[i].first][line[i].second] <= 3) {
			q.push(board[line[i].first][line[i].second]);
		}
	}

	while (q.front() != 1) {
		int n = q.front();
		q.pop();
		q.push(n);
	}

	while (!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}

	if (v[1] == 3) {
		return true;
	}

	return false;
}

void setTeams() {
	vector<vector<bool> > visit(n, vector<bool>(n, false));

	int teamNum = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0 && visit[i][j] == false) {
				pair<pair<int, int>, vector<pair<int, int> > > result = getTeams(i, j, visit); //보드에서 bfs로 팀 찾기

				bool dir = getDir(result.second);

				Team team = { teamNum, result.second, result.first.second, result.first.first, dir, 0 };
				teamMap[teamNum] = team;

				teamNum++;
			}
		}
	}

}

pair<int, int> throwBall(int round) { //공 던지면 부딪히는 사람 좌표 리턴, 없으면 (-1, -1) 리턴
	round--;
	round = round % (4 * n);

	int num = round % n;
	int set = round / n;

	while (set >= 4) {
		set = set / n;
	}

	if (set == 0) {
		for (int j = 0; j < n; j++) {
			if (board[num][j] != 0) {
				return { num, j };
			}

		}

	}
	else if (set == 1) {
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][num] != 0) {
				return { i, num };
			}
		}
	}
	else if (set == 2) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[n - num - 1][j] != 0) {
				return { n - num - 1, j };
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (board[i][n - num - 1] != 0) {
				return { i, n - num - 1 };
			}
		}
	}


	return { -1, -1 };
}

void move() {
	for (pair<int, Team> team : teamMap) {
		int num = team.first;
		vector<pair<int, int> > line = team.second.line;
		int people = team.second.people;
		int head = team.second.head;
		bool dir = team.second.dir;

		if (dir == true) {
			head++;

			head = head % line.size();
			teamMap[num].head = head;
		}
		else {
			head--;

			if (head < 0) {
				head = line.size() - 1;
			}

			teamMap[num].head = head;
		}
	}
}

void settingBoard() {
	board.clear();
	board.assign(n, vector<int>(n, 0));

	for (pair<int, Team> team : teamMap) {
		int num = team.first;
		vector<pair<int, int> > line = team.second.line;
		int people = team.second.people;
		int head = team.second.head;
		bool dir = team.second.dir;

		int idx = head;

		for (int i = 1; i <= people; i++) {
			int x = line[idx].first;
			int y = line[idx].second;

			board[x][y] = i;

			if (!dir) {
				idx++;

				idx = idx % line.size();

			}
			else {
				idx--;

				if (idx < 0) {
					idx = line.size() - 1;
				}
			}
		}
	}
}

int findTeam(int x, int y) {//(x, y)를 line으로 가지고 있는 팀 번호 리턴
	for (pair<int, Team> team : teamMap) {
		int num = team.first;
		vector<pair<int, int> > line = team.second.line;


		for (pair<int, int> l : line) {
			if (l.first == x && l.second == y) {
				return num;
			}
		}
	}

	return -1;
}

void updateTeam(int teamNum) {
	int updateHead = teamMap[teamNum].head;
	bool dir = teamMap[teamNum].dir;

	for (int i = 0; i < teamMap[teamNum].people - 1; i++) {
		if (!dir) {
			updateHead++;

			updateHead = updateHead % teamMap[teamNum].line.size();
		}
		else {
			updateHead--;

			if (updateHead < 0) {
				updateHead = teamMap[teamNum].line.size() - 1;
			}
		}
	}

	teamMap[teamNum].head = updateHead;

	if (dir) {
		teamMap[teamNum].dir = false;
	}
	else {
		teamMap[teamNum].dir = true;
	}
}

int getAnswer() {
	int answer = 0;

	for (pair<int, Team> team : teamMap) {
		int score = team.second.score;
		answer += score;
	}

	return answer;
}

void solution() {
	setTeams();

	for (int round = 1; round <= k; round++) {
		move();

		settingBoard();

		pair<int, int> location = throwBall(round);

		if (location.first == -1 && location.second == -1) {
			continue;
		}

		int teamNum = findTeam(location.first, location.second);

		if (teamNum == -1) {
			continue;
		}

		int plusScore = board[location.first][location.second];
		plusScore = plusScore * plusScore;

		teamMap[teamNum].score += plusScore;

		updateTeam(teamNum);
	}

	int answer = getAnswer();
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