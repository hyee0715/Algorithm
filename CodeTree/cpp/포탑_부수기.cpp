#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

struct Turret {
	int num;
	int x;
	int y;
	int power; //공격력
	int attackTime; //최근 공격 시점
};

int n, m, k;
vector<vector<Turret> > turretBoard;
map<int, Turret> turretMap; //포탑 맵
Turret attacker; //공격자
Turret target; //공격 대상자

vector<vector<bool> > laserVisit;
vector<Turret> laserShortestPath; //레이저 공격 최단 경로 배열

vector<Turret> attackTurrets; //공격과 관련있는 포탑들

int dx4[] = { 0, 1, 0, -1 }; //동남서북
int dy4[] = { 1, 0, -1, 0 };

int dx8[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; //동쪽부터 시계 방향으로 8방향
int dy8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };


void input() {
	cin >> n >> m >> k;

	turretBoard.assign(n, vector<Turret>(m));

	int num = 0;
	int a;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;

			Turret turret = { num, i, j, a, 0 };
			turretMap[num] = turret;
			turretBoard[i][j] = turret;

			num++;
		}
	}
}

bool checkTurrets() {
	//부서지지 않은 포탑이 1개 이하이면 true, 아니면 false 리턴
	int cnt = 0; //부서지지 않은 포탑 개수

	for (pair<int, Turret> tur : turretMap) {
		int power = tur.second.power;

		if (power > 0) {
			cnt++;
		}
	}

	if (cnt <= 1) {
		return true;
	}

	return false;
}

bool attackerCompare(Turret a, Turret b) {
	//선정 기준: 공격력 낮은 순, 공격시점 큰 순, 행+열 큰 순, 열 큰 순
	int aPower = a.power;
	int bPower = b.power;

	int aAttackTime = a.attackTime;
	int bAttackTime = b.attackTime;

	int aRowColSum = a.x + a.y;
	int bRowColSum = b.x + b.y;

	int aCol = a.y;
	int bCol = b.y;

	if (a.power <= b.power) {
		if (a.power == b.power) {
			if (aAttackTime <= bAttackTime) {
				if (aAttackTime == bAttackTime) {
					if (aRowColSum <= bRowColSum) {
						if (aRowColSum == bRowColSum) {
							if (aCol <= bCol) {
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
			return true;
		}
		return true;
	}
	return false;
}

Turret selectAttacker() {
	vector<Turret> turrets;
	for (pair<int, Turret> tur : turretMap) {
		if (tur.second.power > 0) {
			turrets.push_back(tur.second);
		}
	}

	sort(turrets.begin(), turrets.end(), attackerCompare);

	return turrets[0];
}

void updateAttackerPower() {
	turretMap[attacker.num].power += n + m;
	turretBoard[attacker.x][attacker.y].power += n + m;
	attacker = turretMap[attacker.num];
}

bool targetCompare(Turret a, Turret b) {
	//선정 기준: 공격력 높은 순, 공격시점 낮은 순, 행+열 작은 순, 열 작은 순
	int aPower = a.power;
	int bPower = b.power;

	int aAttackTime = a.attackTime;
	int bAttackTime = b.attackTime;

	int aRowColSum = a.x + a.y;
	int bRowColSum = b.x + b.y;

	int aCol = a.y;
	int bCol = b.y;

	if (a.power <= b.power) {
		if (a.power == b.power) {
			if (aAttackTime <= bAttackTime) {
				if (aAttackTime == bAttackTime) {
					if (aRowColSum <= bRowColSum) {
						if (aRowColSum == bRowColSum) {
							if (aCol <= bCol) {
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
		return false;
	}
	return true;
}

Turret selectTarget() {
	vector<Turret> turrets;
	for (pair<int, Turret> tur : turretMap) {
		if (tur.second.x == attacker.x && tur.second.y == attacker.y) {
			continue;
		}

		if (tur.second.power > 0) {
			turrets.push_back(tur.second);
		}
	}

	sort(turrets.begin(), turrets.end(), targetCompare);

	return turrets[0];
}

void copyLaserShortestPath(vector<Turret>& v) {
	laserShortestPath.clear();

	for (int i = 0; i < v.size(); i++) {
		laserShortestPath.push_back(v[i]);
	}
}

void getLaserShortestPath(int a, int b) {
	queue < pair<pair<int, int>, vector<Turret> > > q;
	q.push({ {a, b}, {} });
	laserVisit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		vector<Turret> v = q.front().second;
		q.pop();

		if (x == target.x && y == target.y) {
			copyLaserShortestPath(v);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx4[i];
			int ny = y + dy4[i];
			vector<Turret> nv = v;

			//가장자리는 반대편으로
			if (nx < 0) {
				nx = turretBoard.size() - 1;
			}

			if (ny < 0) {
				ny = turretBoard[0].size() - 1;
			}

			if (nx >= n) {
				nx = 0;
			}

			if (ny >= m) {
				ny = 0;
			}

			if (nx == attacker.x && ny == attacker.y) continue;

			//power > 0인 포탑과 아직 방문하지 않은 포탑만 방문
			if (turretBoard[nx][ny].power > 0 && laserVisit[nx][ny] == false) {
				laserVisit[nx][ny] = true;
				nv.push_back(turretBoard[nx][ny]);

				q.push({ {nx, ny}, nv });
			}
		}
	}
}

void subtractTurretPower(int num, int x, int y, int pwr) {
	int power = turretMap[num].power;

	if (power - pwr <= 0) {
		turretMap[num].power = 0;
		turretBoard[x][y].power = 0;
	}
	else {
		turretMap[num].power -= pwr;
		turretBoard[x][y].power -= pwr;
	}
}

void laserAttack(int attackPower) {
	for (int i = 0; i < laserShortestPath.size() - 1; i++) {
		subtractTurretPower(laserShortestPath[i].num, laserShortestPath[i].x, laserShortestPath[i].y, attackPower / 2);
	}

	Turret last = laserShortestPath[laserShortestPath.size() - 1];
	subtractTurretPower(last.num, last.x, last.y, attackPower);
	target = turretMap[last.num];
}

vector<Turret> getShellNextLocations(int targetX, int targetY) {
	vector<Turret> shellNextLocations;

	for (int i = 0; i < 8; i++) {
		int nx = targetX + dx8[i];
		int ny = targetY + dy8[i];

		if (nx < 0) {
			nx = turretBoard.size() - 1;
		}

		if (ny < 0) {
			ny = turretBoard[0].size() - 1;
		}

		if (nx >= n) {
			nx = 0;
		}

		if (ny >= m) {
			ny = 0;
		}

		if (nx == attacker.x && ny == attacker.y) continue;

		shellNextLocations.push_back(turretBoard[nx][ny]);
	}

	return shellNextLocations;
}

void shellAttack(vector<Turret>& nextLocations, int attackPower) {
	for (int i = 0; i < nextLocations.size(); i++) {
		subtractTurretPower(nextLocations[i].num, nextLocations[i].x, nextLocations[i].y, attackPower / 2);
	}

	subtractTurretPower(target.num, target.x, target.y, attackPower);
	target = turretMap[target.num];
}

void updateAttackTime(int num, int x, int y, int attackTime) {
	turretMap[num].attackTime = attackTime;
	turretBoard[x][y].attackTime = attackTime;
	attacker = turretMap[num];
}

void doAttack(int attackTime) {
	//레이저 공격 후 안되면 포탄 공격
	laserShortestPath.clear();
	laserVisit.assign(turretBoard.size(), vector<bool>(turretBoard[0].size(), false));

	getLaserShortestPath(attacker.x, attacker.y); //레이저 공격 시 최단 경로 찾기

	int attackPower = attacker.power;

	if (laserShortestPath.empty()) {
		//포탄 공격
		vector<Turret> nextLocations = getShellNextLocations(target.x, target.y);

		shellAttack(nextLocations, attackPower);

		//포탄 공격 관련 포탑들 모두 attackTurrets 배열에 추가
		for (int i = 0; i < nextLocations.size(); i++) {
			attackTurrets.push_back(turretMap[nextLocations[i].num]);
		}

		attackTurrets.push_back(turretMap[target.num]);
	}
	else {
		//레이저 공격 계속 진행
		laserAttack(attackPower);

		//레이저 공격 관련 포탑들 모두 attackTurrets 배열에 추가
		for (int i = 0; i < laserShortestPath.size(); i++) {
			attackTurrets.push_back(turretMap[laserShortestPath[i].num]);
		}
	}

	//공격 시점 업데이트
	updateAttackTime(attacker.num, attacker.x, attacker.y, attackTime);

	attackTurrets.push_back(turretMap[attacker.num]); //공격자 포탑도 공격 관련 배열에 추가
}

void plusTurretPower(int num, int x, int y, int pwr) {
	turretMap[num].power += pwr;
	turretBoard[x][y].power += pwr;
}

void plusPower() {
	//공격과 무관한 포탑들 공격력 + 1
	unordered_set<int> atkTurrets;
	vector<Turret> updateTurrets;

	for (int i = 0; i < attackTurrets.size(); i++) {
		atkTurrets.insert(attackTurrets[i].num);
	}

	for (int i = 0; i < n * m; i++) {
		if (atkTurrets.find(i) == atkTurrets.end()) {
			updateTurrets.push_back(turretMap[i]);
		}
	}

	for (int i = 0; i < updateTurrets.size(); i++) {
		if (updateTurrets[i].power > 0) {
			plusTurretPower(updateTurrets[i].num, updateTurrets[i].x, updateTurrets[i].y, 1);
		}
	}
}

void solution() {
	for (int atkCnt = 1; atkCnt <= k; atkCnt++) {
		if (checkTurrets()) {
			//부서지지 않은 포탑이 1개 이하이면 공격 중지
			break;
		}

		attackTurrets.clear();

		//공격자 선정
		attacker = selectAttacker();

		//공격 대상자 선정
		target = selectTarget();

		//공격자 n + m 증가.
		updateAttackerPower();

		//공격
		doAttack(atkCnt);

		//포탑 정비
		plusPower();
	}

	int maxPower = 0;

	for (pair<int, Turret> turret : turretMap) {
		if (turret.second.power > 0) {
			maxPower = max(maxPower, turret.second.power);
		}
	}

	cout << maxPower;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}