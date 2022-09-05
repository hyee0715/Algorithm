#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, x, cnt = 0;
vector<int> v;
set<int> s;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	cin >> x;
}

void solution() {
	for (int i = 0; i < v.size(); i++) {
		if (s.find(v[i]) != s.end()) {
			cnt++;
		}
		else {
			s.insert(x - v[i]);
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