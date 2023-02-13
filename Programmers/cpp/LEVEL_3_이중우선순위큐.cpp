#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int> hi;
	priority_queue<int, vector<int>, greater<>> lo;

	for (int i = 0; i < operations.size(); i++) {
		stringstream str(operations[i]);
		char op;
		int num;

		str >> op >> num;

		if (op == 'I') {
			hi.push(num);
			continue;
		}

		if (op == 'D') {
			if (num == 1) {
				if (!hi.empty()) {
					hi.pop();
				}

				continue;
			}

			if (num == -1) {
				while (!hi.empty()) {
					lo.push(hi.top());
					hi.pop();
				}

				if (lo.empty()) {
					continue;
				}

				lo.pop();

				while (!lo.empty()) {
					hi.push(lo.top());
					lo.pop();
				}
			}
		}
	}

	if (hi.empty()) {
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}

	answer.push_back(hi.top());

	while (!hi.empty()) {
		lo.push(hi.top());
		hi.pop();
	}

	answer.push_back(lo.top());

	return answer;
}