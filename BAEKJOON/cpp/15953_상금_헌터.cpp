#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t;
vector<vector<int>> score;
map<int, int> prize1, prize2;

void input() {
	cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		score.push_back({ a, b });
	}
}

void settingMap() {
	int m1[] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
	int p1[] = { 1, 3, 6, 10, 15, 21 };

	for (int i = 0; i < 6; i++) {
		prize1[p1[i]] = m1[i];
	}

	int m2[] = {5120000, 2560000, 1280000, 640000, 320000 };
	int p2[] = {1, 3, 7, 15, 31};

	for (int i = 0; i < 5; i++) {
		prize2[p2[i]] = m2[i];
	}
}

void solution() {
	settingMap();

	for (int i = 0; i < t; i++) {
		int sum = 0;

		int score1 = score[i][0];
		int score2 = score[i][1];

		if (score1 != 0) {
			for (pair<int, int> p : prize1) {
				if (score1 <= p.first) {
					sum += p.second;
					break;
				}
			}
		}

		if (score2 != 0) {
			for (pair<int, int> p : prize2) {
				if (score2 <= p.first) {
					sum += p.second;
					break;
				}
			}
		}
	
		cout << sum << "\n";
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}