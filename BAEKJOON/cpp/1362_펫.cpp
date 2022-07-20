#include <iostream>
using namespace std;

int o, w, n;
char c;
int senario = 0;
bool die;

void solution() {
	while (1) {
		cin >> c >> n;
		
		if (c == '#' && n == 0)
			break;

		if (!die) {
			if (c == 'E') // 운동
				w -= n;
			else if (c == 'F') // 먹이
				w += n;
		}

		if (w <= 0)
			die = true;
	}

	senario++;
	if (w <= 0)
		cout << senario << " RIP\n";
	else if (w > o / 2 && w < o * 2)
		cout << senario << " :-)\n";
	else
		cout << senario << " :-(\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> o >> w;

		if (o == 0 && w == 0)
			break;

		die = false;
		solution();
	}

	return 0;
}