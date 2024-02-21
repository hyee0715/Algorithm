#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int n : scoville) {
		pq.push(n);
	}

	while (!pq.empty() && pq.top() < K) {
		int a = pq.top();
		pq.pop();

		if (pq.empty()) {
			answer = -1;
			break;
		}

		int b = pq.top();
		pq.pop();

		int mix = a + (b * 2);

		pq.push(mix);

		answer++;
	}

	return answer;
}