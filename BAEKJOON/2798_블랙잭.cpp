#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);

	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	int minRemainder = 500000;
	int maxSum = -1;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			for (int k = j + 1; k < vec.size(); k++) {
				if ((vec[i] + vec[j] + vec[k]) <= m) {
					if ((m - (vec[i] + vec[j] + vec[k])) <= minRemainder) {
						minRemainder = m - (vec[i] + vec[j] + vec[k]);
						maxSum = vec[i] + vec[j] + vec[k];
					}
				}
			}
		}
	}

	cout << maxSum;
	return 0;
}