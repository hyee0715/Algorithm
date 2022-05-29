#include <string>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

int map[MAX][MAX];
int x1, y1, x2, y2;
vector<int> v, answer;

void map_setting(int row, int col) {
	int num = 1;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			map[i][j] = num++;
		}
	}
}

void turn(int x1, int y1, int x2, int y2) { //행렬 테두리 회전하기
	//윗 가로
	v.push_back(map[x1][y2]);
	int temp = map[x1][y2];

	for (int i = y2 - 1; i >= y1; i--) {
		v.push_back(map[x1][i]);
		map[x1][i + 1] = map[x1][i];
	}

	//왼쪽 세로
	for (int i = x1 + 1; i <= x2; i++) {
		v.push_back(map[i][y1]);
		map[i - 1][y1] = map[i][y1];
	}

	//아래 가로
	for (int i = y1 + 1; i <= y2; i++) {
		v.push_back(map[x2][i]);
		map[x2][i - 1] = map[x2][i];
	}

	//오른쪽 세로
	for (int i = x2 - 1; i >= x1; i--) {
		v.push_back(map[i][y2]);
		map[i + 1][y2] = map[i][y2];
	}

	//temp 처리
	map[x1 + 1][y2] = temp;
}

void find_min() {
	sort(v.begin(), v.end());
	int min_num = v[0];
	answer.push_back(min_num);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	map_setting(rows, columns);

	for (int i = 0; i < queries.size(); i++) {
		x1 = queries[i][0];
		y1 = queries[i][1];
		x2 = queries[i][2];
		y2 = queries[i][3];

		v.clear();

		turn(x1, y1, x2, y2);

		find_min();
	}

	return answer;
}