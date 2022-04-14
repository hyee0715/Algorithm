#include <iostream>
#include <cstring>

#define MAX 31
using namespace std;

int n;
bool students[30];

void input() {
	memset(students, false, sizeof(students));

	for (int i = 1; i <= 28; i++) {
		cin >> n;
		students[n] = true;
	}
}

void solution() {
	for (int i = 1; i <= 30; i++) {
		if (students[i] == false) {
			cout << i << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
}