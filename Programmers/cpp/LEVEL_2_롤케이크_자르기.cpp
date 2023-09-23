#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;

	unordered_map<int, int> um1, um2;

	for (int n : topping) {
		um2[n]++;
	}

	for (int n : topping) {
		um1[n]++;
		um2[n]--;

		if (um2[n] == 0) {
			um2.erase(n);
		}

		if (um1.size() == um2.size()) {
			answer++;
		}
	}

	return answer;
}