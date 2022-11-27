#include <iostream>
#include <string>
using namespace std;

string s;

void solution() {
	int sum;

	while (1) {
		sum = 0;

		for (int i = 0; i < s.length(); i++) {
			sum += s[i] - '0';
		}
		
		if (sum < 10) {
			break;
		}

		s = to_string(sum);
	}
	
	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> s;

		if (s == "0") break;

		solution();
	}

	return 0;
}