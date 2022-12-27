#include <iostream>
#include <vector>
using namespace std;

double prices[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
vector<double> v;

void input() {
	v.clear();

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
}

void solution() {
	double sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += (prices[i] * v[i]);
	}

	cout << fixed;
	cout.precision(2);

	cout << "$" << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}