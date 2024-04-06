#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Santa {
	int num;
	int x;
	int y;
	int status; //0: 이상 없음 / 1~2: 기절 / -1: 탈락
};

int n, m, p, c, d;
pair<int, int> rudolphLocation;
map<int, int> santaScore;
map<int, Santa> santas;

int rdx[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //루돌프 8방향
int rdy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int sdx[] = { -1, 0, 1, 0 }; //산타 4방향 (상우하좌)
int sdy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m >> p >> c >> d;

	int a, b;
	cin >> a >> b;
	rudolphLocation = { a - 1, b - 1 };

	int c;

	for (int i = 0; i < p; i++) {
		cin >> a >> b >> c;

		Santa santa = { a, b - 1, c - 1, 0 };
		santas[a] = santa;
	}
}

int getDistance(int r1, int c1, int r2, int c2) {

	return ((r1 - r2) * (r1 - r2)) + ((c1 - c2) * (c1 - c2));
}

vector<pair<int, pair<int, int> > > getSantaDistances(int rx, int ry) {
	vector<pair<int, pair<int, int> > > distances; //산타 거리, 산타 x, 산타 y

	for (pair<int, Santa> santa : santas) {
		int santaNum = santa.first;
		int santaX = santa.second.x;
		int santaY = santa.second.y;
		int santaStatus = santa.second.status;

		if (santaStatus == -1) continue; //산타 탈락 상태면 탐색 X

		int distance = getDistance(rx, ry, santaX, santaY);

		distances.push_back({ distance, {santaX, santaY} });
	}

	return distances;
}

bool santaDistanceCompare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	//산타 거리 작은 순, x 좌표 큰 순, y 좌표 큰 순
	if (a.first <= b.first) {
		if (a.first == b.first) {
			if (a.second.first <= b.second.first) {
				if (a.second.first == b.second.first) {
					if (a.second.second <= b.second.second) {
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

vector<pair<pair<pair<int, int>, int>, int> > getRudolphDirectionDistances(int rx, int ry, int sx, int sy) { //8방향 비교
	vector<pair<pair<pair<int, int>, int>, int> > distances; //거리, 움직일 x 좌표, 움직일 y 좌표, 방향

	for (int i = 0; i < 8; i++) {
		int nx = rx + rdx[i];
		int ny = ry + rdy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		int distance = getDistance(nx, ny, sx, sy);

		distances.push_back({ {{distance, nx}, ny}, i });
	}

	return distances;
}

int findSantaNum(int x, int y) { //x, y자리에 산타가 있다면, 산타 번호 리턴 / 없으면 -1 리턴
	for (pair<int, Santa> sm : santas) {
		int sx = sm.second.x;
		int sy = sm.second.y;

		if (sx == x && sy == y) {
			return sm.first;
		}
	}

	return -1;
}

int findSantaNumExceptSpecificNum(int x, int y, int exceptNum) {
	for (pair<int, Santa> sm : santas) {
		int sx = sm.second.x;
		int sy = sm.second.y;

		if (sx == x && sy == y) {
			if (sm.first == exceptNum) {
				continue;
			}

			return sm.first;
		}
	}

	return -1;
}

void interact(int santaNum, int x, int y, int dir, int version) {
	//santaNum을 제외한 (x,y)에 또다른 산타가 있는 경우, dir 방향으로 한 번 이동시키기
	int anotherSantaNum = findSantaNumExceptSpecificNum(x, y, santaNum);

	if (anotherSantaNum != -1) {
		//또다른 산타가 있으면
		int nx = x;
		int ny = y;

		if (version == 0) {
			//루돌프
			nx = nx + rdx[dir];
			ny = ny + rdy[dir];
		}
		else {
			//산타
			nx = nx + sdx[dir];
			ny = ny + sdy[dir];
		}

		int nextSanta = findSantaNumExceptSpecificNum(nx, ny, anotherSantaNum);

		if (nextSanta != -1) {
			interact(anotherSantaNum, nx, ny, dir, version);
		}

		santas[anotherSantaNum].x = nx;
		santas[anotherSantaNum].y = ny;

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			//범위 밖이면 아웃 처리
			santas[anotherSantaNum].status = -1;
		}
	}
}

void crashFromRudolph(int santaNum, int rudolphMovingDirection) {
	//해당 산타 C만큼 점수 추가
	santaScore[santaNum] += c;

	Santa santa = santas[santaNum];

	int curSx = santa.x;
	int curSy = santa.y;

	int nsx = curSx;
	int nsy = curSy;

	for (int i = 0; i < c; i++) {
		nsx = nsx + rdx[rudolphMovingDirection];
		nsy = nsy + rdy[rudolphMovingDirection];
	}

	//충돌 후 착지한 칸이 게임판 밖이면 탈락 처리
	if (nsx < 0 || nsy < 0 || nsx >= n || nsy >= n) {
		santas[santaNum].status = -1;
		santas[santaNum].x = nsx;
		santas[santaNum].y = nsy;

	}
	else {
		//착지한 칸이 게임판 안일 경우
		//최종 변경
		santas[santaNum].x = nsx;
		santas[santaNum].y = nsy;
		santas[santaNum].status = 2;

		// 상호작용
		interact(santaNum, nsx, nsy, rudolphMovingDirection, 0);
	}
}

void moveRudolph() {
	//루돌프와 모든 산타의 거리 구하기 (탈락 상태가 아닌 산타)
	vector<pair<int, pair<int, int> > > santaDistances = getSantaDistances(rudolphLocation.first, rudolphLocation.second);

	//가장 가까운 산타 찾기
	sort(santaDistances.begin(), santaDistances.end(), santaDistanceCompare);

	int shortestSantaDistance = santaDistances[0].first;
	int shortestSantaX = santaDistances[0].second.first;
	int shortestSantaY = santaDistances[0].second.second;

	//가장 가까운 산타와 가까워질 루돌프 방향 찾기
	vector<pair<pair<pair<int, int>, int>, int> > rudolphDirectionDistances = getRudolphDirectionDistances(rudolphLocation.first, rudolphLocation.second, shortestSantaX, shortestSantaY);

	sort(rudolphDirectionDistances.begin(), rudolphDirectionDistances.end());

	int nx = rudolphDirectionDistances[0].first.first.second;
	int ny = rudolphDirectionDistances[0].first.second;
	int ndir = rudolphDirectionDistances[0].second;

	//찾은 방향으로 루돌프 1칸 전진
	rudolphLocation = { nx, ny };

	//루돌프가 전진한 칸에 산타가 있다면, 충돌 처리
	int locatedSantaNum = findSantaNum(nx, ny);

	if (locatedSantaNum != -1) { //충돌 처리
		crashFromRudolph(locatedSantaNum, ndir); //루돌프가 움직여서 충돌이 일어난 경우 처리
	}
}

vector<pair<int, int> > getSantaDirectionDistances(int santaNum, int sx, int sy) {
	//해당 산타로부터 루돌프까지 가까워 질 수 있는 방향 찾기 (4방향)
	//일단 모든 방향의 거리 구하기
	vector<pair<int, int> > distances; //거리, 방향번호

	for (int i = 0; i < 4; i++) {
		int nx = sx + sdx[i];
		int ny = sy + sdy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		//움직일 칸에 다른 산타 있으면 continue;
		if (findSantaNum(nx, ny) != -1) {
			continue;
		}

		int distance = getDistance(nx, ny, rudolphLocation.first, rudolphLocation.second);

		distances.push_back({ distance, i });
	}

	return distances;
}

void crashFromSanta(int santaNum, int direction) {
	//반대방향으로 밀려남.
	int reverseDirection = (direction + 2) % 4;

	//해당 산타 D만큼 점수 추가
	santaScore[santaNum] += d;

	Santa santa = santas[santaNum];

	int curSx = santa.x;
	int curSy = santa.y;

	int nsx = curSx;
	int nsy = curSy;

	for (int i = 0; i < d; i++) {
		nsx = nsx + sdx[reverseDirection];
		nsy = nsy + sdy[reverseDirection];
	}

	//충돌 후 착지한 칸이 게임판 밖이면 탈락처리
	if (nsx < 0 || nsy < 0 || nsx >= n || nsy >= n) {
		santas[santaNum].status = -1;
		santas[santaNum].x = nsx;
		santas[santaNum].y = nsy;
	}
	else {
		//착지한 칸이 게임판 안일 경우
		//최종 변경
		santas[santaNum].x = nsx;
		santas[santaNum].y = nsy;
		santas[santaNum].status = 2; //기절 처리

		//상호작용
		interact(santaNum, nsx, nsy, reverseDirection, 1);
	}
}

void moveSanta(int santaNum) {
	//해당 산타로부터 루돌프까지 가까워 질 수 있는 방향 찾기 (4방향)
	//일단 모든 방향의 거리 구하기
	Santa santa = santas[santaNum];
	int sx = santa.x;
	int sy = santa.y;

	int currentDistance = getDistance(sx, sy, rudolphLocation.first, rudolphLocation.second);

	vector<pair<int, int> > nextDistances = getSantaDirectionDistances(santaNum, sx, sy); //거리, 방향 번호

	//움직일 수 있는 칸 없으면 움직이지 않음.
	if (nextDistances.empty()) {
		return;
	}

	//가까워지는 칸 아니면 움직이지 않음.
	sort(nextDistances.begin(), nextDistances.end());

	int shortestDist = nextDistances[0].first;

	if (shortestDist >= currentDistance) {
		return;
	}

	//산타 1칸 이동
	int nextDirection = nextDistances[0].second;

	int nx = sx + sdx[nextDirection];
	int ny = sy + sdy[nextDirection];

	santas[santaNum].x = nx; //일단 산타 옮김
	santas[santaNum].y = ny;

	//산타가 이동한 칸에 루돌프가 있다면, 충돌 처리
	if (nx == rudolphLocation.first && ny == rudolphLocation.second) {
		crashFromSanta(santaNum, nextDirection); //산타가 움직여서 충돌이 일어난 경우 처리
	}
}

void plusSantaScore() {
	//살아남은 산타 1점 추가
	for (pair<int, Santa> santa : santas) {
		int santaNum = santa.first;
		int santaStatus = santa.second.status;

		if (santaStatus != -1) {
			santaScore[santaNum]++;
		}
	}
}

void recoverySantaStatus() {
	//기절중인 산타 회복
	for (pair<int, Santa> santa : santas) {
		int santaNum = santa.first;
		int santaStatus = santa.second.status;

		if (santaStatus == 1 || santaStatus == 2) {
			santas[santaNum].status--;
		}
	}
}

bool gameEnd() {
	//산타가 모두 게임 탈락인 경우 true 리턴, 한 명이라도 탈락 아니면 false 리턴
	for (pair<int, Santa> santa : santas) {
		int santaStatus = santa.second.status;

		if (santaStatus != -1) {
			return false;
		}
	}

	return true;
}

void solution() {
	for (int cnt = 0; cnt < m; cnt++) {
		//루돌프 이동
		moveRudolph();

		//산타 이동
		for (int santaNum = 1; santaNum <= p; santaNum++) {
			//기절/탈락 상태인 산타는 이동x
			if (santas[santaNum].status != 0) continue;

			moveSanta(santaNum);
		}

		//턴 끝나면
		//살아남은 산타 1점 추가
		plusSantaScore();

		//턴끝나면 산타 기절 회복처리 -1
		recoverySantaStatus();

		//게임 종료 여부
		if (gameEnd()) {
			break;
		}
	}

	for (pair<int, int> score : santaScore) {
		cout << score.second << " ";
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