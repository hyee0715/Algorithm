#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0;

	sort(score.begin(), score.end());

	int cnt = 1;
	for (int i = score.size() - 1; i >= 0; i--) {
		if (cnt == m) {
			answer += (score[i] * m);
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	return answer;
}