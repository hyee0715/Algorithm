#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v1, v2;
int n, m;

void input() {
	cin >> n >> m;

	int a;
	for (int i = 0; i < n; i++) {
		vector<int> temp;

		for (int j = 0; j < m; j++) {
			cin >> a;
			temp.push_back(a);
		}

		v1.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		vector<int> temp;

		for (int j = 0; j < m; j++) {
			cin >> a;
			temp.push_back(a);
		}

		v2.push_back(temp);
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v1[i][j] + v2[i][j] << " ";
		}
		cout << "\n";
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