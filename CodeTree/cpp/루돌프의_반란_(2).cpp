#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct Rudolph {
	int x;
	int y;
};

struct Santa {
	int num;
	int x;
	int y;
	bool status; //T: 살아있음, F: 탈락
	int rest; //기절 남은 턴
	int score; //점수
};

int n, m, p, c, d; //n: 게임판 크기, m: 턴 수, p: 산타 수, c: 루돌프 힘, d: 산타 힘
map<int, Santa> santaMap;
Rudolph rudolph;

int rx[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //루돌프 8방향
int ry[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int sx[] = { -1, 0, 1, 0 }; //상우하좌 우선순위 중요 산타 4방향
int sy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m >> p >> c >> d;

	int a, b;
	cin >> a >> b;
	rudolph = { a - 1, b - 1 };

	int c;

	for (int i = 1; i <= p; i++) {
		cin >> a >> b >> c;

		Santa santa = { a, b - 1, c - 1, true, 0, 0 };
		santaMap[a] = santa;
	}
}

int getDistance(int x1, int y1, int x2, int y2) {

	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

bool compareSantaDistances(pair<pair<pair<int, int>, int>, int> a, pair<pair<pair<int, int>, int>, int> b) {
	int aDist = a.first.first.first;
	int bDist = b.first.first.first;

	int aX = a.first.first.second;
	int bX = b.first.first.second;

	int aY = a.first.second;
	int bY = b.first.second;

	if (aDist <= bDist) {
		if (aDist == bDist) {
			if (aX <= bX) {
				if (aX == bX) {
					if (aY <= bY) {
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

int needInteract(int snum, int sx, int sy) { //겹치는거 있으면 그 번호 리턴
	for (pair<int, Santa> santa : santaMap) {
		int num = santa.first;
		int status = santa.second.status;

		if (!status || snum == num) continue;

		int x = santa.second.x;
		int y = santa.second.y;

		if (sx == x && sy == y) {
			return num;
		}
	}

	return -1;
}

void interact(int santaNum, int moving, int dirIdx, int x, int y) {
	//현재 있을 칸에 아무것도 없거나, 범위 밖이면 끝
	santaMap[santaNum].x = x;
	santaMap[santaNum].y = y;

	if (santaMap[santaNum].x < 0 || santaMap[santaNum].y < 0 || santaMap[santaNum].x >= n || santaMap[santaNum].y >= n) {
		santaMap[santaNum].status = false;
		return;
	}

	int dupNum = needInteract(santaNum, santaMap[santaNum].x, santaMap[santaNum].y);

	if (dupNum == -1) {
		return;
	}

	int nx = santaMap[santaNum].x;
	int ny = santaMap[santaNum].y;

	if (moving == 0) {
		nx = santaMap[santaNum].x + rx[dirIdx];
		ny = santaMap[santaNum].y + ry[dirIdx];
	}
	else {
		nx = santaMap[santaNum].x + sx[dirIdx];
		ny = santaMap[santaNum].y + sy[dirIdx];
	}

	interact(dupNum, moving, dirIdx, nx, ny);
}

void crash(int santaNum, int moving, int dirIdx) { //moving: 0 == 루돌프가 움직인 경우, 1 == 산타가 움직인 경우
	if (moving == 0) { //루돌프가 움직여서 충돌한 경우
		santaMap[santaNum].score += c;
		santaMap[santaNum].rest = 2; //기절 처리

		//루돌프 방향으로 c칸 이동
		for (int i = 0; i < c; i++) {
			int nx = santaMap[santaNum].x + rx[dirIdx];
			int ny = santaMap[santaNum].y + ry[dirIdx];

			santaMap[santaNum].x = nx;
			santaMap[santaNum].y = ny;
		}

		if (santaMap[santaNum].x < 0 || santaMap[santaNum].y < 0 || santaMap[santaNum].x >= n || santaMap[santaNum].y >= n) { //범위 밖이면 탈락 처리
			santaMap[santaNum].status = false;
			return;
		}

		if (needInteract(santaNum, santaMap[santaNum].x, santaMap[santaNum].y) != -1) {
			interact(santaNum, 0, dirIdx, santaMap[santaNum].x, santaMap[santaNum].y);
		}
	}
	else { //산타가 움직여서 충돌한 경우
		santaMap[santaNum].score += d;
		santaMap[santaNum].rest = 2; //기절 처리

		//산타 반대 방향으로 D칸 이동
		dirIdx = (dirIdx + 2) % 4;

		for (int i = 0; i < d; i++) {
			int nx = santaMap[santaNum].x + sx[dirIdx];
			int ny = santaMap[santaNum].y + sy[dirIdx];

			santaMap[santaNum].x = nx;
			santaMap[santaNum].y = ny;
		}

		if (santaMap[santaNum].x < 0 || santaMap[santaNum].y < 0 || santaMap[santaNum].x >= n || santaMap[santaNum].y >= n) { //범위 밖이면 탈락 처리
			santaMap[santaNum].status = false;
			return;
		}

		if (needInteract(santaNum, santaMap[santaNum].x, santaMap[santaNum].y) != -1) {
			interact(santaNum, 1, dirIdx, santaMap[santaNum].x, santaMap[santaNum].y);
		}
	}
}

int isCrashed() { //루돌프와 충돌한 산타가 있으면 번호 리턴, 없으면 -1 리턴
	for (pair<int, Santa> santa : santaMap) {
		int num = santa.first;
		int x = santa.second.x;
		int y = santa.second.y;
		int status = santa.second.status;
		int rest = santa.second.rest;

		if (!status) continue;

		if (x == rudolph.x && y == rudolph.y) {
			return num;
		}
	}

	return -1;
}

void moveRudolph() {
	//가장 가까운 산타 찾기
	//탈락이 아닌 모든 산타와 루돌프의 거리 찾기
	vector<pair<pair<pair<int, int>, int>, int> > santaDistances; //거리, x, y, 산타 번호

	for (pair<int, Santa> santa : santaMap) {
		bool status = santa.second.status;
		if (!status) continue;

		int num = santa.first;
		int x = santa.second.x;
		int y = santa.second.y;

		int dist = getDistance(rudolph.x, rudolph.y, x, y);
		santaDistances.push_back({ {{dist, x}, y}, num });
	}

	if (santaDistances.empty()) {
		return;
	}

	//산타 행 열 큰 순 정렬
	sort(santaDistances.begin(), santaDistances.end(), compareSantaDistances);

	//그 산타 쪽으로 8방향 중 한 칸 이동
	int targetSantaNum = santaDistances[0].second;
	int targetSantaX = santaDistances[0].first.first.second;
	int targetSantaY = santaDistances[0].first.second;

	vector<pair<int, int>> distances; //거리, 방향 인덱스

	//루돌프의 인접 8방향 중 타겟 산타로 가장 가까운 방향 선택
	for (int i = 0; i < 8; i++) {
		int nx = rudolph.x + rx[i];
		int ny = rudolph.y + ry[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		int dist = getDistance(nx, ny, targetSantaX, targetSantaY);

		distances.push_back({ dist, i });
	}

	//방향 정렬
	sort(distances.begin(), distances.end());

	//가장 가까운 산타 쪽 방향으로 루돌프 1칸 이동
	int nx = rudolph.x + rx[distances[0].second];
	int ny = rudolph.y + ry[distances[0].second];

	rudolph.x = nx;
	rudolph.y = ny;

	//충돌된 산타가 있는지 확인
	int crashedSantaNum = isCrashed();
	if (crashedSantaNum != -1) { //충돌된 산타 있으면 충돌 처리
		crash(crashedSantaNum, 0, distances[0].second);
	}
}

bool isSantaLocated(int r, int c) {
	for (pair<int, Santa> santa : santaMap) {
		int x = santa.second.x;
		int y = santa.second.y;

		if (r == x && c == y) {
			return true;
		}
	}

	return false;
}

bool isSantaLocatedExceptNum(int r, int c, int num) {
	for (pair<int, Santa> santa : santaMap) {
		int snum = santa.first;
		int x = santa.second.x;
		int y = santa.second.y;

		if (snum == num) continue;

		if (r == x && c == y) {
			return true;
		}
	}

	return false;
}

bool santaMovingDistancesCompare(pair<int, int> a, pair<int, int> b) {
	//거리, 방향 인덱스 (거리 작은 순, 인덱스 작은 순)
	int aDistance = a.first;
	int bDistance = b.first;

	int aDir = a.second;
	int bDir = b.second;

	if (aDistance <= bDistance) {
		if (aDistance == bDistance) {
			if (aDir <= bDir) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void moveSantas() {
	for (pair<int, Santa> santa : santaMap) {//기절x, 탈락x인 산타 1~p 순서대로 움직임 , 루돌프에게 가장 가까워지는 방향으로 1칸 이동
		int num = santa.first;
		int x = santa.second.x;
		int y = santa.second.y;
		int status = santa.second.status;
		int rest = santa.second.rest;

		if (!status || (status && rest > 0)) continue;

		int curDistance = getDistance(x, y, rudolph.x, rudolph.y);

		vector<pair<int, int> > santaMovingDistances; //거리, 방향 인덱스 (거리 작은 순, 인덱스 작은 순)

		//4방향 중 루돌프와 가장 가까운 거리인 방향 찾기
		for (int i = 0; i < 4; i++) { //상우하좌 우선순위 4방향 이동
			int nx = x + sx[i];
			int ny = y + sy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; //범위 밖이면 그 방향 이동 x
			if (isSantaLocatedExceptNum(nx, ny, num)) continue; //다른 산타가 있으면 그 방향 이동x 

			int distance = getDistance(nx, ny, rudolph.x, rudolph.y);
			//움직일 수 있는 칸 있어도 루돌프에게 가까워지지 않으면 이동 x
			if (distance >= curDistance) continue;

			santaMovingDistances.push_back({ distance, i });
		}

		if (santaMovingDistances.empty()) continue; //움직일 수 있는 칸 없으면 이동x

		sort(santaMovingDistances.begin(), santaMovingDistances.end(), santaMovingDistancesCompare);

		int nx = x + sx[santaMovingDistances[0].second];
		int ny = y + sy[santaMovingDistances[0].second];

		santaMap[num].x = nx;
		santaMap[num].y = ny;

		//충돌된 산타가 있는지 확인
		int crashedSantaNum = isCrashed();
		if (crashedSantaNum != -1) { //충돌된 산타 있으면 충돌 처리
			crash(crashedSantaNum, 1, santaMovingDistances[0].second);
		}
	}
}

void updateSantaInfo() {
	for (pair<int, Santa> santa : santaMap) {
		int num = santa.first;
		int status = santa.second.status;
		int rest = santa.second.rest;

		if (!status) continue;

		if (rest > 0) {
			santaMap[num].rest--;
		}

		santaMap[num].score++;
	}
}

void solution() {
	for (int round = 1; round <= m; round++) {
		moveRudolph();

		moveSantas();

		updateSantaInfo();
	}

	for (pair<int, Santa> santa : santaMap) {
		int score = santa.second.score;

		cout << score << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}