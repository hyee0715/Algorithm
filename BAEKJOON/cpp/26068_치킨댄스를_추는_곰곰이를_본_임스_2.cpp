#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, answer = 0;
vector<string> v;

void input() {
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
}

void solution() {
	string s;
	for (int i = 0; i < v.size(); i++) {
		s = v[i];
		s.erase(s.begin(), s.begin() + 2);

		int day = stoi(s);
		if (day <= 90) {
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