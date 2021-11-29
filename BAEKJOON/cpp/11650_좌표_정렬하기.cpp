#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > vec;

	int first, second;

	for (int i = 0; i < n; i++) {
		cin >> first >> second;
		vec.push_back(make_pair(first, second));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}