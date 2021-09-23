#include <iostream>
using namespace std;

int main() {
	int y, m, d;
	cin >> y;
	cin.ignore(256, '.');
	cin >> m;
	cin.ignore(256, '.');
	cin >> d;

	cout.width(4); cout.fill('0');
	cout << y << ".";

	cout.width(2); cout.fill('0');
	cout << m << ".";

	cout.width(2); cout.fill('0');
	cout << d << endl;

	return 0;

}