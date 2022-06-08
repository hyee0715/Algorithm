#include <iostream>
#include <cmath>
#include <vector>

#define INF 0x7FFFFFFF
#define MAX 100001
using namespace std;

int n;
long long arr[MAX];
vector<long long> answer;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int start = 0;
	int end = n - 1;
	long long distance = INF;

	while (start < end) {
		if (distance > abs(arr[start] + arr[end])) {
			distance = abs(arr[start] + arr[end]);

			answer.clear();
			answer.push_back(arr[start]);
			answer.push_back(arr[end]);
		}

		if (arr[start] + arr[end] > 0)
			end--;
		else
			start++;
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