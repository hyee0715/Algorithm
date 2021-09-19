#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int ret;
	int m;
	for (int i = 1; i < n; i++) {
		m = i;
		ret = i;

		while (m > 0) {
			ret += (m % 10);
			m = m / 10;
		}

		if (ret == n) {
			cout << i;
			n = 0;
			break;
		}
	}

	if (n != 0)
		cout << 0;

	return 0;
}