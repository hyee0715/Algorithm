#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> vec(n);
	vector<pair<int, string> > pairVec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	for (int i = 0; i < n; i++) {
		pairVec[i] = make_pair(vec[i].size(), vec[i]);
	}

	sort(pairVec.begin(), pairVec.end());

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << pairVec[i].second << "\n";
		}
		else {
			if (pairVec[i - 1].second != pairVec[i].second) {
				cout << pairVec[i].second << "\n";
			}
		}
	}

	return 0;
}
