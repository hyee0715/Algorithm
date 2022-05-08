#include <iostream>
#include <cstring>
#include <vector>

#define MAX 11
using namespace std;

int n, cnt = 0;
int cow[MAX];
vector<pair<int, int> > v;


void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a, b });
	}
}

void solution() {
	memset(cow, -1, sizeof(cow));

	for (int i = 0; i < v.size(); i++) {
		if (cow[v[i].first] == -1) {
			cow[v[i].first] = v[i].second;
		}
		else {
			if (cow[v[i].first] == 0 && v[i].second == 1) {
				cnt++;
				cow[v[i].first] = v[i].second;
			}
			else if (cow[v[i].first] == 1 && v[i].second == 0) {
				cnt++;
				cow[v[i].first] = v[i].second;
			}
		}
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}