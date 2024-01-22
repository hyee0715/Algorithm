#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<char, vector<int>> um; //알파벳, 인덱스

	for (int i = 0; i < s.length(); i++) {
		if (um.count(s[i]) != 0) {
			vector<int> v = um[s[i]];
			int num = v[v.size() - 1];

			answer.push_back(i - num);
			um[s[i]].push_back(i);
		}
		else {
			answer.push_back(-1);
			um[s[i]].push_back(i);
		}
	}

	return answer;
}