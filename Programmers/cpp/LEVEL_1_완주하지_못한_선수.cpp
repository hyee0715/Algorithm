#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> hash_map;

	for (int i = 0; i < participant.size(); i++) {
		hash_map[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++) {
		hash_map[completion[i]]--;
	}

	for (auto person : hash_map) {
		if (person.second % 2 != 0) {
			answer = person.first;
		}
	}
	return answer;
}