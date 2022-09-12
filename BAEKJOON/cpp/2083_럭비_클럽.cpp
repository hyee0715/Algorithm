#include <iostream>
#include <string>
using namespace std;

string name;
int age, kg;

void solution() {
	if (age > 17 || kg >= 80) {
		cout << name << " Senior\n";
	}
	else {
		cout << name << " Junior\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> name >> age >> kg;

		if (name == "#" && age == 0 && kg == 0) break;

		solution();

	}

	return 0;
}