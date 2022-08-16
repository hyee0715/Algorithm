#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> arr, v;
vector<bool> visit;

void input() {
	cin >> l >> c;

	char a;
	for (int i = 0; i < c; i++) {
		cin >> a;
		arr.push_back(a);
	}
}

void check() {
	int vowel = 0, consonant = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			vowel++;
		}
	}

	consonant = l - vowel;

	if (vowel >= 1 && consonant >= 2) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << "\n";
	}
}

void dfs(int idx, int cnt) {
	if (cnt == l) {
		check();
	}
	else {
		for (int i = idx; i < arr.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(arr[i]);
			dfs(i, cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}

void solution() {
	visit.assign(c, false);

	sort(arr.begin(), arr.end());

	dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}