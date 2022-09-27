#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<int> v;
string s;

void input() {
	cin >> n >> k >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		if (v.empty()) {
			v.push_back(s[i] - '0');
		}
		else {
			if (v.back() < (s[i] - '0') && k > 0) {
				v.pop_back();
				k--;
			}

			while (!v.empty()) {
				if (v.back() < (s[i] - '0') && k > 0) {
					v.pop_back();
					k--;
				}
				else {
					break;
				}
			}

			v.push_back(s[i] - '0');
		}
	}

	while (k > 0) {
		v.pop_back();
		k--;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}