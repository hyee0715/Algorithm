#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> score;

void input() {
	score.clear();

	int a;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		score.push_back(a);
	}
}

void solution() {
	sort(score.begin(), score.end());

	if (score[score.size() - 2] - score[1] >= 4) {
		cout << "KIN" << "\n";
		return;
	}

	int sum = 0;
	for (int i = 1; i < score.size() - 1; i++) {
		sum += score[i];
	}

	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}