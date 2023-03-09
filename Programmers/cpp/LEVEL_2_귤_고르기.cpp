#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	unordered_map<int, int> um;
	vector<pair<int, int>> v;

	for (int n : tangerine) {
		um[n]++;
	}

	for (auto m : um) {
		v.push_back({ m.second, m.first });
	}

	sort(v.begin(), v.end(), greater<>());

	int idx = 0;

	while (k > 0) {
		answer++;

		k -= v[idx].first;
		idx++;
	}

	return answer;
}