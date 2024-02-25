#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string a, b, c, d;
int k;
vector<pair<int, int>> proceed;

void input() {
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;

		if (i == 0) {
			a = s;
		}
		else if (i == 1) {
			b = s;
		}
		else if (i == 2) {
			c = s;
		}
		else {
			d = s;
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		proceed.push_back({ a, b });
	}
}

int getReverse(int direction) {
	if (direction == 1) {
		return -1;
	}
	
	return 1;
}

string leftDirection(string s) {
	string ret;

	for (int i = 1; i < s.length(); i++) {
		ret += s[i];
	}

	ret += s[0];

	return ret;
}

string rightDirection(string s) {
	string ret;

	ret += s[s.length() - 1];

	for (int i = 0; i < s.length() - 1; i++) {
		ret += s[i];
	}

	return ret;
}

void solution() {
	queue<pair<int, int>> executeQueue;

	int right = 2, left = 6;

	for (int i = 0; i < proceed.size(); i++) {
		int clockNum = proceed[i].first;
		int direction = proceed[i].second;

		if (clockNum == 1) {
			executeQueue.push({ 1, direction });

			if (a[right] != b[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 2, reverseDirection });

				if (b[right] != c[left]) {
					reverseDirection = getReverse(reverseDirection);
					executeQueue.push({ 3, reverseDirection });

					if (c[right] != d[left]) {
						reverseDirection = getReverse(reverseDirection);
						executeQueue.push({ 4, reverseDirection });
					}
				}
			}
		}
		else if (clockNum == 2) {
			executeQueue.push({ 2, direction });

			if (a[right] != b[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 1, reverseDirection });
			}

			if (b[right] != c[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 3, reverseDirection });

				if (c[right] != d[left]) {
					reverseDirection = getReverse(reverseDirection);
					executeQueue.push({ 4, reverseDirection });
				}
			}
		}
		else if (clockNum == 3) {
			executeQueue.push({ 3, direction });

			if (c[right] != d[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 4, reverseDirection });
			}

			if (b[right] != c[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 2, reverseDirection });

				if (a[right] != b[left]) {
					reverseDirection = getReverse(reverseDirection);
					executeQueue.push({ 1, reverseDirection });
				}
			}
		}
		else {
			executeQueue.push({ 4, direction });

			if (c[right] != d[left]) {
				int reverseDirection = getReverse(direction);
				executeQueue.push({ 3, reverseDirection });

				if (b[right] != c[left]) {
					reverseDirection = getReverse(reverseDirection);
					executeQueue.push({ 2, reverseDirection });

					if (a[right] != b[left]) {
						reverseDirection = getReverse(reverseDirection);
						executeQueue.push({ 1, reverseDirection });
					}
				}
			}
		}

		while (!executeQueue.empty()) {
			int clockNum = executeQueue.front().first;
			int dir = executeQueue.front().second;
			executeQueue.pop();

			if (dir == 1) {
				if (clockNum == 1) {
					a = rightDirection(a);
				}
				else if (clockNum == 2) {
					b = rightDirection(b);
				}
				else if (clockNum == 3) {
					c = rightDirection(c);
				}
				else {
					d = rightDirection(d);
				}
			}
			else {
				if (clockNum == 1) {
					a = leftDirection(a);
				}
				else if (clockNum == 2) {
					b = leftDirection(b);
				}
				else if (clockNum == 3) {
					c = leftDirection(c);
				}
				else {
					d = leftDirection(d);
				}
			}
		}
	}

	int answer = 0;

	if (a[0] == '1') {
		answer += 1;
	}

	if (b[0] == '1') {
		answer += 2;
	}

	if (c[0] == '1') {
		answer += 4;
	}

	if (d[0] == '1') {
		answer += 8;
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
