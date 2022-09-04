#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;

		v.push_back(a);
	}
}

void solution() {
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
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