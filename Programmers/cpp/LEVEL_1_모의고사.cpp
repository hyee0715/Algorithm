#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int one[5] = { 1, 2, 3, 4, 5 };
	int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int three[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int correct[4] = { 0, 0, 0, 0 };
	int highestScore;
	queue<int> highestPerson;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == one[i % 5]) {
			correct[1]++;
		}

		if (answers[i] == two[i % 8]) {
			correct[2]++;
		}

		if (answers[i] == three[i % 10]) {
			correct[3]++;
		}
	}

	highestScore = correct[1];
	highestPerson.push(1);
	for (int i = 2; i < 4; i++) {
		if (highestScore < correct[i]) {
			while (!highestPerson.empty()) {
				highestPerson.pop();
			}

			highestScore = correct[i];
			highestPerson.push(i);
		}
		else if (highestScore == correct[i]) {
			highestPerson.push(i);
		}
	}

	while (!highestPerson.empty()) {
		answer.push_back(highestPerson.front());
		highestPerson.pop();
	}

	return answer;
}