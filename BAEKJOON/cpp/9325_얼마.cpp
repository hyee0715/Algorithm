#include <iostream>
#include <vector>
#include <string>
using namespace std;

int car_price, option_count, each_option_count, option_price;

void solution() {
	cin >> car_price >> option_count;

	int sum = car_price;

	for (int i = 0; i < option_count; i++) {
		cin >> each_option_count >> option_price;

		sum += (each_option_count * option_price);
	}

	cout << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		solution();
	}

	return 0;
}