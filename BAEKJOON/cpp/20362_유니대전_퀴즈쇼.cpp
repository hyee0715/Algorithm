#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, answer = 0;
string winner, win_answer;
vector<pair<string, string>> v;

void input() {
	cin >> n >> winner;

	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		v.push_back({ a, b });
	}
}

void solution() {
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].first == winner) {
			win_answer = v[i].second;
			continue;
		}

		if (v[i].second == win_answer) {
			answer++;
		}
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}