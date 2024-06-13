#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct Group {
	int num;
	int value; //값
	int count; //칸 수
	set<pair<int, int> > st; 
};

int n; //격자 크기
vector<vector<int> > board;
map<int, Group> groupMap;
int answer;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
	cin >> n;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void findGroup(int a, int b, vector<vector<bool> >& visit, int groupNum) {
	int cnt = 0;
	
	set<pair<int, int> > st;

	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;
		st.insert({ x, y });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
		
			if (board[nx][ny] == board[a][b] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	Group group = { groupNum, board[a][b], cnt, st};
	groupMap[groupNum] = group;
}

void setting(int num, vector<vector<int> >& temp) {
	vector<vector<bool> > visit(n, vector<bool>(n, false));

	set<pair<int, int> > st = groupMap[num].st;

	for (pair<int, int> s : st) {
		int x = s.first;
		int y = s.second;

		temp[x][y] = num;
	}
}

vector<vector<int> > setBoard() {
	vector<vector<int> > temp = board;

	for (pair<int, Group> group : groupMap) {
		int num = group.first;

		setting(num, temp);
	}

	return temp;
}

void findGroups() {
	vector<vector<bool> > visit(n, vector<bool>(n, false));
	int groupNum = 1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (visit[i][j] == false) {
				findGroup(i, j, visit, groupNum);

				groupNum++;
			}
		}
	}
}

int getScore(int a, int b, vector<vector<int> >& temp) { //a번 그룹과 b번 그룹의 조화로움 점수 구하기
	int bNum = groupMap[b].num;
	
	int cnt = 0; //서로 맞닿은 변 개수

	set<pair<int, int> > aSet = groupMap[a].st;
	set<pair<int, int> > bSet = groupMap[b].st;

	for (pair<int, int> st : aSet) {
		int x = st.first;
		int y = st.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (bSet.find({ nx, ny }) != bSet.end()) {
				cnt++;
			}
		}
	}

	int score = (groupMap[a].count + groupMap[b].count) * groupMap[a].value * groupMap[b].value * cnt;
	return score;
}

int getArtisticScore() {
	vector<vector<int> > temp = setBoard();

	int artisticScore = 0;
	int groupCnt = groupMap.size();

	for (int i = 1; i <= groupCnt - 1; i++) {
		for (int j = i + 1; j <= groupCnt; j++) {
			int score = getScore(i, j, temp);

			artisticScore += score;
		}
	}

	return artisticScore;
}

void rotateCenter() {
	int size = n / 2;

	queue<int> q;
	
	for (int i = 1; i <= size; i++) {
		q.push(board[size - i][size]);
	}

	for (int i = 1; i <= size; i++) {
		q.push(board[size][size - i]);
	}

	for (int i = 1; i <= size; i++) {
		int n = q.front();
		q.pop();
		board[size][size - i] = n;
	}

	for (int i = 1; i <= size; i++) {
		q.push(board[size + i][size]);
	}

	for (int i = 1; i <= size; i++) {
		int n = q.front();
		q.pop();
		board[size + i][size] = n;
	}

	for (int i = 1; i <= size; i++) {
		q.push(board[size][size + i]);
	}

	for (int i = 1; i <= size; i++) {
		int n = q.front();
		q.pop();
		board[size][size + i] = n;
	}

	for (int i = 1; i <= size; i++) {
		int n = q.front();
		q.pop();
		board[size - i][size] = n;
	}
}

void rotateSideSquare() {
	vector<vector<int> > temp = board;
	int size = n / 2;

	int x = 0;
	int y = 0;

	for (int j = size - 1; j >= 0; j--) {
		for (int i = 0; i < size; i++) {
			temp[i][j] = board[x][y];
			y++;
		}
		x++;
		y = 0;
	}


	x = 0;
	y = size + 1;

	for (int j = n - 1; j > size; j--) {
		for (int i = 0; i < size; i++) {
			temp[i][j] = board[x][y];
			y++;
		}
		x++;
		y = size + 1;
	}

	x = size + 1;
	y = 0;

	for (int j = size - 1; j >= 0; j--) {
		for (int i = size + 1; i < n; i++) {
			temp[i][j] = board[x][y];
			y++;
		}
		x++;
		y = 0;
	}

	x = size + 1;
	y = size + 1;

	for (int j = n - 1; j > size; j--) {
		for (int i = size + 1; i < n; i++) {
			temp[i][j] = board[x][y];
			y++;
		}
		x++;
		y = size + 1;
	}


	board = temp;
}

void rotate() {
	rotateCenter();

	rotateSideSquare();
}

void solution() {
	answer = 0;
	findGroups();

	int artisticScore = getArtisticScore();

	answer += artisticScore;

	for (int round = 1; round <= 3; round++) {
		groupMap.clear();

		rotate();

		findGroups();
		

		int artisticScore = getArtisticScore();

		answer += artisticScore;
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