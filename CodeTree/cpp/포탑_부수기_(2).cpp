#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct Turret {
	int num;
	int x;
	int y;
	int power; //공격력
	int attackTime; //최근 공격 시점
	int damageTime; //최근 피해 시점
};

int n, m, k; //n * m: 격자 크기, k: 턴 수
vector<vector<int> > board;
map<int, Turret> turretMap;
Turret attacker;
Turret target;

int dx[] = { 0, 1, 0, -1 }; //우하좌상
int dy[] = { 1, 0, -1, 0 };

int bdx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int bdy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<int>(m));

	int a;
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;

			Turret turret = { num, i, j, a, 0, 0 };

			board[i][j] = turret.num;
			turretMap[num] = turret;

			num++;
		}
	}
}

bool checkTurrets() {
	int count = 0;

	for (pair<int, Turret> turret : turretMap) {
		int num = turret.first;
		int x = turret.second.x;
		int y = turret.second.y;
		int power = turret.second.power;
		int attackTime = turret.second.attackTime;
		int damageTime = turret.second.damageTime;

		if (power > 0) {
			count++;
		}
	}

	if (count == 1) {
		return true;
	}

	return false;
}
 
bool attackerCompare(Turret a, Turret b) { //공격력 낮은 순(오름), 가장 최근 공격한 순(공격시점 큰 순, 내림), 행+열 큰 순(내림), 열 큰 순(내림)
	int aPower = a.power;
	int bPower = b.power;

	int aAttackTime = a.attackTime;
	int bAttackTime = b.attackTime;

	int aRPlusC = a.x + a.y;
	int bRPlusC = b.x + b.y;

	int aCol = a.y;
	int bCol = b.y;
	
	if (aPower <= bPower) {
		if (aPower == bPower) {
			if (aAttackTime <= bAttackTime) {
				if (aAttackTime == bAttackTime) {
					if (aRPlusC <= bRPlusC) {
						if (aRPlusC == bRPlusC) {
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

int findAttackerTurret() {
	vector<Turret> turrets; //공격력 낮은 순(오름), 가장 최근 공격한 순(공격시점 큰 순, 내림), 행+열 큰 순(내림), 열 큰 순(내림)

	for (pair<int, Turret> turret : turretMap) {
		if (turret.second.power > 0) {
			turrets.push_back(turret.second);
		}
	}

	sort(turrets.begin(), turrets.end(), attackerCompare); //선정기준 뽑아서 배열 정렬 후 가장 앞의 거 찾기

	return turrets[0].num;
}

void selectAttacker(int round) {
	//포탑 (power > 0)인 것 중 가장 약한 거 찾기
	int attackerNum = findAttackerTurret();

	//공격자 공격력 n+m 증가, attacktime = round로 업뎃
	turretMap[attackerNum].power += (n + m);
	turretMap[attackerNum].attackTime = round;

	//공격자 업뎃
	attacker = turretMap[attackerNum];
}

bool targetCompare(Turret a, Turret b) { //공격력 높은 순(내림), 공격한 지 가장 오래된 순(공격시점 작은 순, 오름), 행+열 작은 순(오름), 열 작은 순(오름)
	int aPower = a.power;
	int bPower = b.power;

	int aAttackTime = a.attackTime;
	int bAttackTime = b.attackTime;

	int aRPlusC = a.x + a.y;
	int bRPlusC = b.x + b.y;

	int aCol = a.y;
	int bCol = b.y;
	
	if (aPower <= bPower) {
		if (aPower == bPower) {
			if (aAttackTime <= bAttackTime) {
				if (aAttackTime == bAttackTime) {
					if (aRPlusC <= bRPlusC) {
						if (aRPlusC == bRPlusC) {
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

int findTargetTurret() {
	vector<Turret> turrets; //공격력 높은 순(내림), 공격한 지 가장 오래된 순(공격 시점 작은 순, 오름), 행+열 작은 순(오름), 열 작은 순(오름)

	for (pair<int, Turret> turret : turretMap) {
		if (turret.second.power > 0 && turret.second.num != attacker.num) {
			turrets.push_back(turret.second);
		}
	}

	sort(turrets.begin(), turrets.end(), targetCompare); //선정기준 뽑아서 배열 정렬 후 가장 앞의 거 찾기

	return turrets[0].num;
}

void selectTarget() {
	//포탑(power>0 && attacker.num != num)인 것 중에 가장 강한 포탑 찾기 (공격자 아닌 거)
	int targetNum = findTargetTurret();

	//타겟 업뎃
	target = turretMap[targetNum];
}

vector<int> bfs() { //공격자로부터 bfs로 공격대상까지 최단거리 찾기
    //이동 시 반대로도 이동 가능, 우하좌상 순서, 부서진 포탑(power<=0)으로는 이동하지 않는다.
    //공격자 제외 경로 ~ 경로 대상까지 모든 포탑 번호 리턴

	int attackX = attacker.x;
	int attackY = attacker.y;

	int targetX = target.x;
	int targetY = target.y;

	vector<vector<bool> > visit(n, vector<bool>(m, false));
	vector<int> turretNums; //경로 포탑 번호

	queue<pair<pair<int, int>, vector<int> > > q; //큐에 들어갈 거, x, y, 포탑 번호 배열
	q.push({ {attackX, attackY}, {} });
	visit[attackX][attackY] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		vector<int> path = q.front().second;
		q.pop();

		if (x == targetX && y == targetY) {
			turretNums = path;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0) {
				nx = n - 1;
			}

			if (ny < 0) {
				ny = m - 1;
			}

			if (nx >= n) {
				nx = 0;
			}

			if (ny >= m) {
				ny = 0;
			}

			vector<int> temp = path;
			Turret nTurret = turretMap[board[nx][ny]];

			if (nTurret.power > 0 && visit[nx][ny] == false) {
				temp.push_back(board[nx][ny]);
				visit[nx][ny] = true;
				q.push({ {nx, ny}, temp });
			}
		}
	}

	return turretNums;
}

void bombAttack(int round) {
	//공격 대상 & 주위 8개 방향 공격 & 공격자 제외
	turretMap[target.num].power -= attacker.power;
	turretMap[target.num].damageTime = round; //피해 시점 업데이트

	int x = target.x;
	int y = target.y;

	for (int i = 0; i < 8; i++) {
		int nx = x + bdx[i];
		int ny = y + bdy[i];

		//반대사이드 영향
		if (nx < 0) {
			nx = n - 1;
		}

		if (ny < 0) {
			ny = m - 1;
		}

		if (nx >= n) {
			nx = 0;
		}

		if (ny >= m) {
			ny = 0;
		}

		int nTurretNum = board[nx][ny];
		if (turretMap[nTurretNum].power <= 0) {
			continue;
		}

		if (nTurretNum == attacker.num) {
			continue;
		}

		turretMap[nTurretNum].power -= (attacker.power / 2);
		turretMap[nTurretNum].damageTime = round;
	}
}

void laserAttack(int round) {
	vector<int> path = bfs(); //공격자로부터 bfs로 공격대상까지 최단거리 찾기 (레이저 경로 찾기)

	if (path.empty()) {
		//포탄 공격
		bombAttack(round);
	}
	else {
		//레이저 공격
		for (int i = 0; i < path.size(); i++) {
			if (i == path.size() - 1) {
				turretMap[path[i]].power -= attacker.power;
			}
			else {
				turretMap[path[i]].power -= (attacker.power / 2);
			}

			turretMap[path[i]].damageTime = round;
		}
	}
}

void breakTurrets() {
	for (pair<int, Turret> turret : turretMap) {
		int num = turret.first;
		int power = turret.second.power;

		if (power <= 0) {
			turretMap[num].power = 0;
		}
	}
}

void updateTurrets(int round) {
	for (pair<int, Turret> turret : turretMap) {
		int num = turret.first;
		int x = turret.second.x;
		int y = turret.second.y;
		int power = turret.second.power;
		int attackTime = turret.second.attackTime;
		int damageTime = turret.second.damageTime;

		if (power > 0 && attackTime != round && damageTime != round) {
			turretMap[num].power += 1;
		}
	}
}

int getAnswer() {
	int answer = 0;

	for (pair<int, Turret> turret : turretMap) {
		int power = turret.second.power;

		if (power > 0) {
			answer = max(answer, power);
		}
	}

	return answer;
}

void solution() {
	for (int round = 1; round <= k; round++) {
		if (checkTurrets()) { //부서지지 않은 포탑 1개 되면 중지
			break;
		}

		selectAttacker(round);

		selectTarget();

		laserAttack(round);

		breakTurrets();
		
		updateTurrets(round);
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