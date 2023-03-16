#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> number;
	vector<char> type;
	vector<string> option(3);

	string s;
	int timeCount = -1;
	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			timeCount++; //몇 번째 기회인지 구분

			int n = stoi(s);
			number.push_back(n);
			s.clear();

			type.push_back(dartResult[i]);

			continue;
		}

		if (dartResult[i] == '*') {
			if (timeCount == 0) {
				option[timeCount] += '*';
			}
			else if (timeCount > 0) {
				option[timeCount - 1] += '*';
				option[timeCount] += '*';
			}

			continue;
		}

		if (dartResult[i] == '#') {
			option[timeCount] += '#';

			continue;
		}

		s += dartResult[i];
	}

	for (int i = 0; i < 3; i++) {
		int score = number[i];

		if (type[i] == 'D') {
			score = score * score;
		}
		else if (type[i] == 'T') {
			score = score * score * score;
		}

		for (int j = 0; j < option[i].length(); j++) {
			if (option[i][j] == '*') {
				score *= 2;
				continue;
			}

			//'#'인 경우
			score *= -1;
		}

		answer += score;
	}

	return answer;
}