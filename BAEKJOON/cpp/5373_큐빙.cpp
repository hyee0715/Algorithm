#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n; //큐브를 돌린 횟수
vector<string> methods;
vector<vector<char> > cube;
vector<vector<pair<int, int> > > locations;

void settingCube() {
	cube[3][3] = cube[3][4] = cube[3][5] = cube[4][3] = cube[4][4] = cube[4][5] = cube[5][3] = cube[5][4] = cube[5][5] = 'w';
	cube[9][3] = cube[9][4] = cube[9][5] = cube[10][3] = cube[10][4] = cube[10][5] = cube[11][3] = cube[11][4] = cube[11][5] = 'y';
	cube[3][0] = cube[3][1] = cube[3][2] = cube[4][0] = cube[4][1] = cube[4][2] = cube[5][0] = cube[5][1] = cube[5][2] = 'g';
	cube[3][6] = cube[3][7] = cube[3][8] = cube[4][6] = cube[4][7] = cube[4][8] = cube[5][6] = cube[5][7] = cube[5][8] = 'b';
	cube[6][3] = cube[6][4] = cube[6][5] = cube[7][3] = cube[7][4] = cube[7][5] = cube[8][3] = cube[8][4] = cube[8][5] = 'r';
	cube[0][3] = cube[0][4] = cube[0][5] = cube[1][3] = cube[1][4] = cube[1][5] = cube[2][3] = cube[2][4] = cube[2][5] = 'o';
}

void initialize() {
	methods.clear();
	cube.clear();
	locations.clear();

	cube.assign(12, vector<char>(9, '-'));

	settingCube();
}

void input() {
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		methods.push_back(s);
	}
}

void setLocations(int side) {
	locations.assign(4, vector<pair<int, int>>(3));

	if (side == 'U') { //윗 면
		locations[0][0] = { 3, 6 };
		locations[0][1] = { 4, 6 };
		locations[0][2] = { 5, 6 };
		locations[1][0] = { 6, 5 };
		locations[1][1] = { 6, 4 };
		locations[1][2] = { 6, 3 };
		locations[2][0] = { 5, 2 };
		locations[2][1] = { 4, 2 };
		locations[2][2] = { 3, 2 };
		locations[3][0] = { 2, 3 };
		locations[3][1] = { 2, 4 };
		locations[3][2] = { 2, 5 };
	}
	else if (side == 'D') { //아랫 면
		locations[0][0] = { 5, 8 };
		locations[0][1] = { 4, 8 };
		locations[0][2] = { 3, 8 };
		locations[1][0] = { 0, 5 };
		locations[1][1] = { 0, 4 };
		locations[1][2] = { 0, 3 };
		locations[2][0] = { 3, 0 };
		locations[2][1] = { 4, 0 };
		locations[2][2] = { 5, 0 };
		locations[3][0] = { 8, 3 };
		locations[3][1] = { 8, 4 };
		locations[3][2] = { 8, 5 };
	}
	else if (side == 'F') { //앞 면
		locations[0][0] = { 5, 6 };
		locations[0][1] = { 5, 7 };
		locations[0][2] = { 5, 8 };
		locations[1][0] = { 9, 5 };
		locations[1][1] = { 9, 4 };
		locations[1][2] = { 9, 3 };
		locations[2][0] = { 5, 0 };
		locations[2][1] = { 5, 1 };
		locations[2][2] = { 5, 2 };
		locations[3][0] = { 5, 3 };
		locations[3][1] = { 5, 4 };
		locations[3][2] = { 5, 5 };
	}
	else if (side == 'B') { //뒷 면
		locations[0][0] = { 3, 8};
		locations[0][1] = { 3, 7 };
		locations[0][2] = { 3, 6};
		locations[1][0] = { 3, 5 };
		locations[1][1] = { 3, 4 };
		locations[1][2] = { 3, 3 };
		locations[2][0] = { 3, 2 };
		locations[2][1] = { 3, 1 };
		locations[2][2] = { 3, 0 };
		locations[3][0] = { 11, 3 };
		locations[3][1] = { 11, 4 };
		locations[3][2] = { 11, 5 };
	}
	else if (side == 'L') { //왼쪽 면
		locations[0][0] = { 3, 3 };
		locations[0][1] = { 4, 3 };
		locations[0][2] = { 5, 3 };
		locations[1][0] = { 6, 3 };
		locations[1][1] = { 7, 3 };
		locations[1][2] = { 8, 3 };
		locations[2][0] = { 9, 3 };
		locations[2][1] = { 10, 3 };
		locations[2][2] = { 11, 3 };
		locations[3][0] = { 0, 3 };
		locations[3][1] = { 1, 3 };
		locations[3][2] = { 2, 3 };
	}
	else { //오른쪽 면
		locations[0][0] = { 11, 5 };
		locations[0][1] = { 10, 5 };
		locations[0][2] = { 9, 5 };
		locations[1][0] = { 8, 5 };
		locations[1][1] = { 7, 5 };
		locations[1][2] = { 6, 5 };
		locations[2][0] = { 5, 5 };
		locations[2][1] = { 4, 5 };
		locations[2][2] = { 3, 5 };
		locations[3][0] = { 2, 5 };
		locations[3][1] = { 1, 5 };
		locations[3][2] = { 0, 5 };
	}
}

void rotate(int x, int y, char direction) {
	vector<int> v;
	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 2; j++) {
			v.push_back(cube[i][j]);
		}
	}

	int idx = 0;

	if (direction == '+') { //시계 방향
		for (int j = y + 2; j >= y; j--) {
			for (int i = x; i <= x + 2; i++) {
				cube[i][j] = v[idx++];
			}
		}

	}
	else { //반시계 방향
		for (int j = y; j <= y + 2; j++) {
			for (int i = x + 2; i >= x; i--) {
				cube[i][j] = v[idx++];
			}
		}
	}
}

void rotateSide(char side, char direction) {
	if (side == 'U') { //윗 면
		rotate(3, 3, direction);
	}
	else if (side == 'D') { //아랫 면
		rotate(9, 3, direction);
	}
	else if (side == 'F') { //앞 면
		rotate(6, 3, direction);
	}
	else if (side == 'B') { //뒷 면
		rotate(0, 3, direction);
	}
	else if (side == 'L') { //왼쪽 면
		rotate(3, 0, direction);
	}
	else { //오른쪽 면
		rotate(3, 6, direction);
	}
}

void rotateSideEdges(char direction) {
	if (direction == '+') { //시계 방향
		int t1 = cube[locations[0][0].first][locations[0][0].second];
		int t2 = cube[locations[0][1].first][locations[0][1].second];
		int t3 = cube[locations[0][2].first][locations[0][2].second];

		cube[locations[0][0].first][locations[0][0].second] = cube[locations[3][0].first][locations[3][0].second];
		cube[locations[0][1].first][locations[0][1].second] = cube[locations[3][1].first][locations[3][1].second];
		cube[locations[0][2].first][locations[0][2].second] = cube[locations[3][2].first][locations[3][2].second];

		cube[locations[3][0].first][locations[3][0].second] = cube[locations[2][0].first][locations[2][0].second];
		cube[locations[3][1].first][locations[3][1].second] = cube[locations[2][1].first][locations[2][1].second];
		cube[locations[3][2].first][locations[3][2].second] = cube[locations[2][2].first][locations[2][2].second];

		cube[locations[2][0].first][locations[2][0].second] = cube[locations[1][0].first][locations[1][0].second];
		cube[locations[2][1].first][locations[2][1].second] = cube[locations[1][1].first][locations[1][1].second];
		cube[locations[2][2].first][locations[2][2].second] = cube[locations[1][2].first][locations[1][2].second];

		cube[locations[1][0].first][locations[1][0].second] = t1;
		cube[locations[1][1].first][locations[1][1].second] = t2;
		cube[locations[1][2].first][locations[1][2].second] = t3;
	}
	else { //반시계 방향
		int t1 = cube[locations[0][0].first][locations[0][0].second];
		int t2 = cube[locations[0][1].first][locations[0][1].second];
		int t3 = cube[locations[0][2].first][locations[0][2].second];

		cube[locations[0][0].first][locations[0][0].second] = cube[locations[1][0].first][locations[1][0].second];
		cube[locations[0][1].first][locations[0][1].second] = cube[locations[1][1].first][locations[1][1].second];
		cube[locations[0][2].first][locations[0][2].second] = cube[locations[1][2].first][locations[1][2].second];

		cube[locations[1][0].first][locations[1][0].second] = cube[locations[2][0].first][locations[2][0].second];
		cube[locations[1][1].first][locations[1][1].second] = cube[locations[2][1].first][locations[2][1].second];
		cube[locations[1][2].first][locations[1][2].second] = cube[locations[2][2].first][locations[2][2].second];

		cube[locations[2][0].first][locations[2][0].second] = cube[locations[3][0].first][locations[3][0].second];
		cube[locations[2][1].first][locations[2][1].second] = cube[locations[3][1].first][locations[3][1].second];
		cube[locations[2][2].first][locations[2][2].second] = cube[locations[3][2].first][locations[3][2].second];

		cube[locations[3][0].first][locations[3][0].second] = t1;
		cube[locations[3][1].first][locations[3][1].second] = t2;
		cube[locations[3][2].first][locations[3][2].second] = t3;
	}
}

void printUpSide() {
	for (int i = 3; i <= 5; i++) {
		for (int j = 3; j <= 5; j++) {
			cout << cube[i][j];
		}
		cout << "\n";
	}
}

void solution() {
	for (int r = 0; r < methods.size(); r++) {
		string method = methods[r];

		char side = method[0];
		char direction = method[1];

		setLocations(side);

		rotateSide(side, direction);

		rotateSideEdges(direction);
	}

	printUpSide();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}