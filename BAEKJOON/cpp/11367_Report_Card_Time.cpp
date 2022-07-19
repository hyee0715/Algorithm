#include <iostream>
#include <string>
using namespace std;

string s, grade;
int n;

void input() {
	cin >> s >> n;
}

void solution() {
	if (n >= 97)
		grade = "A+";
	else if (n >= 90)
		grade = "A";
	else if (n >= 87)
		grade = "B+";
	else if (n >= 80)
		grade = "B";
	else if (n >= 77)
		grade = "C+";
	else if (n >= 70)
		grade = "C";
	else if (n >= 67)
		grade = "D+";
	else if (n >= 60)
		grade = "D";
	else
		grade = "F";

	cout << s << " " << grade << "\n";
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