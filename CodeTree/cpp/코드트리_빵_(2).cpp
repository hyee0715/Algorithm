#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct Person {
	int num;
	int x;
	int y;
	int status; //-1: 출발x, 0: 편의점 도착x, 1: 편의점 도착o
};

int n, m; //n: 격자 크기, m: 사람의 수
vector<vector<int> > board; // 0: 빈 공간, 1~m: 편의점 번호, -1: 베이스 캠프, -2: 이동 불가
map<int, Person> personMap;
vector<pair<int, int> > conv;

int dx[] = {-1, 0, 0, 1}; //북서동남
int dy[] = {0, -1, 1, 0};

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n, 0));

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;

			if (a == 1) {
				board[i][j] = -1;
			}
			else {
				board[i][j] = a;
			}
		}
	}

	conv.push_back({ -1, -1 });

	int convNum = 1;
	int b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		conv.push_back({ a - 1, b - 1 });
		board[a - 1][b - 1] = convNum;
		convNum++;
	}
}

void settingPerson() {
	for (int i = 1; i <= m; i++) {
		Person person = {i, -1, -1, -1};
		personMap[i] = person;
	}
}

bool checkPersons() { //모두가 편의점에 도착했으면 true 리턴, 아니면 false 리턴
	for (pair<int, Person> person : personMap) {
		int num = person.first;
		int status = person.second.status;

		if (status == -1 || status == 0) {
			return false;
		}
	}

	return true;
}

vector<pair<int, int> > bfs(int a, int b, int convX, int convY) { //status == 0인 person 중에서 각각 bfs로 현 위치로부터 원하는 편의점까지의 최단 경로 찾기 (board==-2는 이동x), 
	vector<vector<bool> > visit(n, vector<bool>(n, false));
	queue<pair<pair<int, int>, vector<pair<int, int> > > > q; //x, y, 경로 배열
	vector<pair<int, int> > ret;

	q.push({ {a, b}, {} });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		vector<pair<int, int> > path = q.front().second;
		q.pop();

		if (x == convX && y == convY) {
			ret = path;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			vector<pair<int, int> > temp = path;
			if (board[nx][ny] != -2 && visit[nx][ny] == false) {
				temp.push_back({ nx, ny });
				visit[nx][ny] = true;
				q.push({ {nx, ny}, temp });
			}
		}
	}

	return ret;
}

void movePersons() { //status == 0인 person 중에서 각각 bfs로 현 위치로부터 원하는 편의점까지의 최단 경로 찾기 (board == -2는 이동x), 
	for (pair<int, Person> person : personMap) {
		int num = person.first;
		int x = person.second.x;
		int y = person.second.y;
		int status = person.second.status;

		if (status != 0) {
			continue;
		}

		int convX = conv[num].first;
		int convY = conv[num].second;

		vector<pair<int, int> > path = bfs(x, y, convX, convY);

		int targetX = path[0].first;
		int targetY = path[0].second;

		//1칸 이동, person 맵 값 x, y 변경
		personMap[num].x = targetX;
		personMap[num].y = targetY;
	}
}

void updateInfo() { //person (status==0)인 것들 중에, 편의점 도착한 것있으면 status = 1 처리, 편의점 board -2 처리
	for (pair<int, Person> person : personMap) {
		int num = person.first;
		int x = person.second.x;
		int y = person.second.y;
		int status = person.second.status;

		if (status != 0) {
			continue;
		}
		
		int convX = conv[num].first;
		int convY = conv[num].second;

		if (x == convX && y == convY) {
			personMap[num].status = 1;
			board[convX][convY] = -2;
		}
	}
}

vector<pair<pair<int, int>, int> > findBasecamp(int a, int b) { //거리, 행, 열
	vector<pair<pair<int, int>, int> > ret;

	vector<vector<bool> > visit(n, vector<bool>(n, false));
	queue<pair<pair<int, int>, int> > q; //x, y, 거리
	
	q.push({ {a, b}, 0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (board[x][y] == -1) {
			ret.push_back({ {dist, x}, y });
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (board[nx][ny] != -2 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx, ny}, dist + 1 });
			}
		}
	}

	return ret;
}

bool basecampCompare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) { //정렬 후 뽑기 (거리 짧은 순(오름차순), 행 작은 순(오름차순), 열 작은 순(오름차순))
	
	int aDist = a.first.first;
	int bDist = b.first.first;

	int aX = a.first.second;
	int bX = b.first.second;

	int aY = a.second;
	int bY = b.second;

	if (aDist <= bDist) {
		if (aDist == bDist) {
			if (aX <= bX) {
				if (aX == bX) {
					if (aY <= bY) {
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
	return false;
}

void start(int minutes) {//person 베이스캠프 투입 시작
	if (personMap.count(minutes) == 0) { //minutes번째 사람 없으면 수행하지 않음
		return;
	}

	Person person = personMap[minutes];

	int convX = conv[person.num].first;
	int convY = conv[person.num].second;

	vector<pair<pair<int, int>, int> > basecamps = findBasecamp(convX, convY); //사람이 원하는 편의점으로부터 가장 가까운 베이스 캠프 찾기

	sort(basecamps.begin(), basecamps.end(), basecampCompare); //정렬 후 뽑기 (거리 짧은 순(오름차순), 행 작은 순(오름차순), 열 작은 순(오름차순))
	
	int basecampX = basecamps[0].first.second;
	int basecampY = basecamps[0].second;

	personMap[person.num].x = basecampX;
	personMap[person.num].y = basecampY;
	personMap[person.num].status = 0;

	board[basecampX][basecampY] = -2;
}

void solution() {
	settingPerson();

	int minutes = 0;

	while (1) {
		if (checkPersons()) { //모두가 편의점에 도착했는지 체크
			break;
		}
		
		minutes++;

		movePersons();

		updateInfo();

		start(minutes);
	}

	cout << minutes;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}