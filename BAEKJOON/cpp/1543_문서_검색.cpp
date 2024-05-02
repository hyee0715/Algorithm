#include <iostream>
#include <string>
#include <vector>
using namespace std;

string original, sub;
vector<bool> visit;

void input() {
	getline(cin, original);
	getline(cin, sub);
}

void solution() {
	int answer = 0;
	visit.assign(original.length(), false);

	int left = 0;
	int right = sub.length() - 1;

	string s = "";
	for (int i = left; i <= right; i++) {
		s += original[i];
	}

	if (s == sub) {
		answer++;

		for (int i = left; i <= right; i++) {
			visit[i] = true;
		}
	}

	bool flag = false;

	while (right < original.length()) {
		while (visit[left] == true) {
			s.erase(0, 1);

			left++;
			right++;

			if (right >= original.length()) {
				flag = true;
				break;
			}
			s += original[right];
		}

		if (flag) {
			break;
		}
		
		if (s == sub) {
			answer++;

			for (int i = left; i <= right; i++) {
				visit[i] = true;
			}
		}

		s.erase(0, 1);

		left++;
		right++;

		if (right >= original.length()) {
			break;
		}
		s += original[right];
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}