#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;

	unordered_set<int> st;

	for (int n : numbers) {
		st.insert(n);
	}

	for (int i = 0; i <= 9; i++) {
		if (st.find(i) == st.end()) {
			answer += i;
		}
	}

	return answer;
}