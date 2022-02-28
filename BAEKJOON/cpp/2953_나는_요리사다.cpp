#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[5][4];
vector<pair<int, int> > score; // <점수, 참가자 번호>

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	int sum;

	for (int i = 0; i < 5; i++) {
		sum = 0;

		for (int j = 0; j < 4; j++) {
			sum += arr[i][j];
		}

		score.push_back(make_pair(sum, i + 1));
	}

	sort(score.begin(), score.end(), greater<>());

	cout << score[0].second << " " << score[0].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}