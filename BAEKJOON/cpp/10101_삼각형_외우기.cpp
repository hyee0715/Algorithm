#include <iostream>
using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
	
}

void solution() {
	if (a + b + c != 180)
		cout << "Error";
	else if (a == b && b == c)
		cout << "Equilateral";
	else if (a == b || a == c || b == c)
		cout << "Isosceles";
	else 
		cout << "Scalene";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}