#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	unordered_map<int, set<int>> um;
	set<int> removeDup;

	for (int i = 0; i < elements.size(); i++) {
		int sum = 0, cnt = 1;

		for (int j = i; j < elements.size() + i; j++) {
			int idx = j;

			if (idx >= elements.size()) {
				idx = idx - elements.size();
			}

			sum += elements[idx];
			um[cnt].insert(sum);
			cnt++;
		}
	}

	for (pair<int, set<int>> m : um) {
		for (int n : m.second) {
			removeDup.insert(n);
		}
	}

	answer = removeDup.size();

	return answer;
}