#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int days = 0;


	while (a > 1) {
		a = a - 1;

		if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
			days += 31;
		}
		else if (a == 4 || a == 6 || a == 9 || a == 11) {
			days += 30;
		}
		else { // a == 2
			days += 29;
		}
	}

	days += b - 1;

	int idx = days % 7;

	switch (idx) {
	case 0:
		answer += "FRI"; break;
	case 1:
		answer += "SAT"; break;
	case 2:
		answer += "SUN"; break;
	case 3:
		answer += "MON"; break;
	case 4:
		answer += "TUE"; break;
	case 5:
		answer += "WED"; break;
	case 6:
		answer += "THU"; break;
	}

	return answer;
}