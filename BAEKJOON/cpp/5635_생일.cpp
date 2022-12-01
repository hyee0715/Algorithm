#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<pair<int, int>, pair<int, string>>> person;

void input() {
	cin >> n;

	string name;
	int a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> name >> a >> b >> c;

		person.push_back({ {c, b}, {a, name} });
	}
}

void solution() {
	sort(person.begin(), person.end());

	cout << person[person.size() - 1].second.second << "\n";
	cout << person[0].second.second;
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