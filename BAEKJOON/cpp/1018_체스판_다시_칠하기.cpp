#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 51
using namespace std;

int n, m, answer = 987654321;
char map[MAX][MAX];
char newMap[8][8];
vector<char> vec;

void input() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void findMinSquare(char map[8][8]) {
	//잘라낸 8x8 체스판에서 다시 칠해야 하는 정사각형을 구한다.
	char copyMap[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	char originalStartChar = map[0][0];
	int changeCnt = 0;
	
	if (originalStartChar != 'W') {
		map[0][0] = 'W';
		changeCnt++;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) { // 행이 짝수번째인 경우
				if (j % 2 == 0) { // 열이 짝수번째인 경우
					if (map[i][j] == 'B') {
						map[i][j] = 'W';
						changeCnt++;
					}
				}
				else { // 열이 홀수번째인 경우
					if (map[i][j] == 'W') {
						map[i][j] = 'B';
						changeCnt++;
					}
				}
			}
			else { // 행이 홀수번째인 경우
				if (j % 2 == 0) { // 열이 짝수번째인 경우
					if (map[i][j] == 'W') {
						map[i][j] = 'B';
						changeCnt++;
					}
				}
				else { // 열이 홀수번째인 경우
					if (map[i][j] == 'B') {
						map[i][j] = 'W';
						changeCnt++;
					}
				}
			}
		}
	}
	
	answer = min(answer, changeCnt);

//---------------------------------

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = copyMap[i][j];
		}
	}

	changeCnt = 0;
	if (originalStartChar != 'B') {
		map[0][0] = 'B';
		changeCnt++;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) { // 행이 짝수번째인 경우
				if (j % 2 == 0) { // 열이 짝수번째인 경우
					if (map[i][j] == 'W') {
						map[i][j] = 'B';
						changeCnt++;
					}
				}
				else { // 열이 홀수번째인 경우
					if (map[i][j] == 'B') {
						map[i][j] = 'W';
						changeCnt++;
					}
				}
			}
			else { // 행이 홀수번째인 경우
				if (j % 2 == 0) { // 열이 짝수번째인 경우
					if (map[i][j] == 'B') {
						map[i][j] = 'W';
						changeCnt++;
					}
				}
				else { // 열이 홀수번째인 경우
					if (map[i][j] == 'W') {
						map[i][j] = 'B';
						changeCnt++;
					}
				}
			}
		}
	}
	
	answer = min(answer, changeCnt);	
}

void mapCutting8x8() {
	// 체스판을 8x8로 잘라낸다.
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {

			int iSize = i;
			int jSize = j;
			int cnt = 0;

			for (int a = iSize; a < iSize + 8; a++) {
				vec.clear();

				for (int b = jSize; b < jSize + 8; b++) {

					vec.push_back(map[a][b]);
				}

				for (int c = 0; c < vec.size(); c++) {
					newMap[cnt][c] = vec[c];
				}
				cnt++;

			}

			findMinSquare(newMap);
		}
	}
}

void solution() {
	mapCutting8x8();

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