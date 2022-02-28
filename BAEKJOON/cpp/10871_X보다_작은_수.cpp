#include <iostream>
#include <vector>

#define MAX 10000
using namespace std;

int n, x;
int arr[MAX];
vector<int> answer;

void input() {
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < x)
			answer.push_back(arr[i]);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
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