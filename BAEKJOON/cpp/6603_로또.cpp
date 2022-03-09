#include <iostream>
#include <vector>
using namespace std;

int k;
int arr[13];
bool visit[13];
vector<int> v;

void bfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < k; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(arr[i]);
		bfs(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> k;

		if (k == 0)
			break;
		
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		bfs(0, 0);
		cout << "\n";
	}

	return 0;
}