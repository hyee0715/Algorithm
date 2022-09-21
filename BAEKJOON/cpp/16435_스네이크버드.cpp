#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> v;
bool eat = false;

void input() {
	cin >> n >> l;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= l) {
			l++;
			eat = true;
		}
		else {
			if (eat)
				break;
		}
	}

	cout << l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}