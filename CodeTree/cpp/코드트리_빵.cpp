#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct Person {
	int num; //사람 번호
	int x; //현재 x 좌표 (출발 안했을 경우 -1)
	int y; //현재 y 좌표 
	int status; //-1: 아직 출발 안 한 상태, 0: 격자 위 & 편의점에 도착 안 한 상태(베이스캠프 포함), 1: 편의점에 도착한 상태
	int conX; //원하는 편의점 x 좌표
	int conY; //원하는 편의점 y 좌표
};

int n, m; //n: 격자의 크기, m: 사람의 수
vector<vector<int> > board; //0: 빈 공간, 1: 베이스 캠프, 2: 편의점
vector<vector<bool> > totalVisit;
map<int, Person> personMap;

int dx[] = {-1, 0, 0, 1}; //북서동남
int dy[] = {0, -1, 1, 0};

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;

		board[a - 1][b - 1] = 2;

		Person person = {i, -1, -1, -1, a - 1, b - 1};
		personMap[i] = person;
	}
}

bool checkAllArrived() {
	//모든 사람이 원하는 편의점에 도착했다면 true, 도착하지 않았다면 false 리턴
	for (pair<int, Person> person : personMap) {
		if (person.second.status == -1 || person.second.status == 0) {
			return false;
		}
	}

	return true;
}

vector<pair<int, int> > getShortestPath(int startX, int startY, int destX, int destY) {
	//현재 위치로부터 원하는 편의점까지의 최단 경로 찾기
	vector<pair<int, int> > shortestPath;
	vector<vector<bool> > visit(n, vector<bool>(n, false));
	
	queue<pair<pair<int, int>, vector<pair<int, int> > > > q;
	q.push({ { startX, startY }, {} });
	visit[startX][startY] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		vector<pair<int, int> > v = q.front().second;
		q.pop();

		if (x == destX && y == destY) {
			shortestPath = v;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			vector<pair<int, int> > nv = v;

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (totalVisit[nx][ny] == false && visit[nx][ny] == false) {
				nv.push_back({ nx, ny });
				visit[nx][ny] = true;
				q.push({ {nx, ny}, nv });
			}
		}
	}

	return shortestPath;
}

vector<pair<pair<int, int>, int> > getBaseCampInfo(int a, int b) {
	//현재 위치로부터 모든 베이스캠프의 위치와 거리 찾기
	vector<pair<pair<int, int>, int> > baseCamp;
	vector<vector<bool> > visit(n, vector<bool>(n, false));

	queue<pair<pair<int, int>, int> > q; //x, y, distance
	q.push({ { a, b }, 0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (board[x][y] == 1) {
			baseCamp.push_back({ {dist, x}, y });
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (totalVisit[nx][ny] == false && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx, ny}, dist + 1, });
			}
		}
	}
	
	return baseCamp;
}

void solution() {
	totalVisit.assign(n, vector<bool>(n, false));

	int time = 0;

	while (1) {
		//모든 사람들이 원하는 편의점에 도착했는지 체크
		if (checkAllArrived()) {
			break;
		}

		time++;

		//격자 위의 사람들 순회
		vector<pair<int, int> > visitList;

		for (pair<int, Person> person : personMap) {
			int num = person.first;
			int x = person.second.x;
			int y = person.second.y;
			int status = person.second.status;
			int conX = person.second.conX;
			int conY = person.second.conY;

			if (status == 0) {
				//현재 위치로부터 원하는 편의점까지의 최단 경로 찾기
				vector<pair<int, int> > shortestPath = getShortestPath(x, y, conX, conY);

				int nx = shortestPath[0].first;
				int ny = shortestPath[0].second;

				personMap[num].x = nx;
				personMap[num].y = ny;

				//편의점에 도착했다면 편의점 방문 처리
				if (nx == conX && ny == conY) {
					personMap[num].status = 1;
					visitList.push_back({ nx, ny });
				}
			}
		}

		for (int i = 0; i < visitList.size(); i++) {
			int vx = visitList[i].first;
			int vy = visitList[i].second;
			totalVisit[vx][vy] = true;
		}

		visitList.clear();

		//time <= m 이면, time번째 사람을 베이스캠프로 내보냄
		if (time <= m) {
			int conX = personMap[time].conX;
			int conY = personMap[time].conY;

			//원하는 편의점으로부터 방문 안한 가장 가까운 베이스 캠프 찾기
			vector<pair<pair<int, int>, int> > basecamp = getBaseCampInfo(conX, conY);

			sort(basecamp.begin(), basecamp.end());

			int nearestBaseCampX = basecamp[0].first.second;
			int nearestBaseCampY = basecamp[0].second;


			personMap[time].x = nearestBaseCampX;
			personMap[time].y = nearestBaseCampY;
			personMap[time].status = 0;

			totalVisit[nearestBaseCampX][nearestBaseCampY] = true;
		}
	}

	cout << time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}