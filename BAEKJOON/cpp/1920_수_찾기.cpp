#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000
using namespace std;

int n, m;
vector<int> answer;
long long n_arr[MAX], m_arr[MAX];
bool flag;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> m_arr[i];
	}
}

void solution() {
	sort(n_arr, n_arr + n);

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		flag = false;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (n_arr[mid] == m_arr[i]) {
				answer.push_back(1);
				flag = true;
				break;
			}
			else if (n_arr[mid] > m_arr[i]) {
				right = mid - 1;
			}
			else { //n_arr[mid] < m_arr[i]
				left = mid + 1;
			}
		}

		if (!flag)
			answer.push_back(0);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
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