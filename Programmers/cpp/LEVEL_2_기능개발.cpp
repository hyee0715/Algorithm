#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> days;
	int count, previousFront;
	int idx = 0;

	for (int i = 0; i < progresses.size(); i++) {
		if ((100 - progresses[i]) % speeds[i] == 0) {
			days.push((100 - progresses[i]) / speeds[i]);
		}
		else {
			days.push(((100 - progresses[i]) / speeds[i]) + 1);
		}
	}

	while (1) {
		count = 0;
		previousFront = days.front();
		days.pop();
		count++;

		while (!days.empty()) {
			if (days.front() <= previousFront) {
				days.pop();
				count++;
			}
			else {
				break;
			}
		}

		answer.push_back(count);

		if (days.empty())
			break;
	}

	return answer;
}