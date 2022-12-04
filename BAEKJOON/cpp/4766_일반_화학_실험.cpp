#include <iostream>
using namespace std;

double current_temp, temperature;
bool start = false;

void solution() {
	if (start == false) {
		start = true;
		temperature = current_temp;
		return;
	}

	cout << fixed;
	cout.precision(2);

	cout << current_temp - temperature << "\n";
	temperature = current_temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> current_temp;

		if (current_temp == 999) {
			break;
		}

		solution();
	}

	return 0;
}