#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int> hi;

	for (int n : works) {
		hi.push(n);
	}

	while (n > 0) {
		if (hi.empty()) {
			break;
		}

		int num = hi.top();
		hi.pop();

		num--;
		if (num > 0) {
			hi.push(num);
		}

		n--;
	}

	while (!hi.empty()) {
		answer += (hi.top() * hi.top());
		hi.pop();
	}

	return answer;
}