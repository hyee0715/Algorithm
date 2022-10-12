#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, answer = 0;
string jinho;
vector<string> v;

void input() {
	cin >> jinho;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		v.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < v.size(); i++) {
		if (jinho == v[i])
			answer++;
	}

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