#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	unordered_map<string, int> um;

	for (int i = 0; i < name.size(); i++) {
		um[name[i]] = yearning[i];
	}

	for (vector<string> p : photo) {
		int num = 0;

		for (string name : p) {
			if (um.count(name) != 0) {
				num += um[name];
			}
		}

		answer.push_back(num);
	}

	return answer;
}