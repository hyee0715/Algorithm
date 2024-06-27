#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int answer = 0;

vector<char> list = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'n', 'm', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<char> v;

void input() {
	cin >> s;
}

bool check() {
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) {
			return false;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (s[i] == 'c') {
			if (v[i] >= '0' && v[i] <= '9') {
				return false;
			}
		}

		if (s[i] == 'd') {
			if (v[i] >= 'a' && v[i] <= 'z') {
				return false;
			}
		}
	}

	return true;
}

void dfs(int cnt) {
	if (cnt == s.length()) {
		if (check()) {
			answer++;
		}

		return;
	}

	for (int i = 0; i < list.size(); i++) {
		v.push_back(list[i]);
		dfs(cnt + 1);
		v.pop_back();
	}
}

void solution() {
	//중복순열
	dfs(0);

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