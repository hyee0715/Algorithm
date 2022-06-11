#include <iostream>
#include <algorithm>

#define MAX 1010
using namespace std;

int n, l, cnt = 1;
int arr[MAX];

void input() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	//오름차순 정렬
	sort(arr, arr + n);

	int point = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] - point + 1 > l) {
			cnt++;
			point = arr[i];
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