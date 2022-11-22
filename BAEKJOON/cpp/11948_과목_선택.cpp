#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum = 0;
vector<int> science, social;

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> n;
		science.push_back(n);
	}

	for (int i = 0; i < 2; i++) {
		cin >> n;
		social.push_back(n);
	}
}

void solution() {
	sort(science.begin(), science.end(), greater<>());
	sort(social.begin(), social.end(), greater<>());

	for (int i = 0; i < 3; i++) {
		sum += science[i];
	}

	sum += social[0];

	cout << sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}