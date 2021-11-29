#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[100];

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] > max && arr[i] + arr[j] + arr[k] <= m) {
					max = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}

	cout << max;

	return 0;
}