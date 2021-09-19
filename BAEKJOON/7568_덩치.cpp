#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> weight(n);
	vector<int> height(n);
	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> height[i] >> weight[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (height[i] > height[j] && weight[i] > weight[j]) {
				rank[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}