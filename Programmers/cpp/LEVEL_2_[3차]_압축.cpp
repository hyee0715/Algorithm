#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxStrIdx(int cur, string msg, unordered_map<string, int> dic) {
	string s = "";
	s += msg[cur];

	for (int i = cur + 1; i < msg.length(); i++) {
		if (dic.count(s + msg[i]) == 0) {
			return i - 1;
		}
		else {
			s = s + msg[i];
		}
	}

	return msg.length() - 1;
}

vector<int> solution(string msg) {
	vector<int> answer;
	unordered_map<string, int> dictionary;

	int idx = 0;
	char c = 'A';
	string s = "";
	s += (char)(c + idx);

	while (idx <= 25) {
		s = "";
		s += (char)(c + idx);

		dictionary[s] = idx + 1;
		idx++;
	}

	for (int i = 0; i < msg.length(); i++) {
		int endIdx = findMaxStrIdx(i, msg, dictionary); //가능한 문자열 마지막 인덱스 위치 구하기

		s = "";
		for (int j = i; j <= endIdx; j++) {
			s += msg[j];
		}

		i = endIdx;

		if (dictionary.count(s) != 0) {
			answer.push_back(dictionary[s]);
		}

		if (i < msg.length() - 1) {
			dictionary[s + msg[i + 1]] = ++idx;
		}
	}

	return answer;
}