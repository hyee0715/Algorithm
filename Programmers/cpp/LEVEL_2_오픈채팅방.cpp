#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> splitRecord(string rec) {
	vector<string> ret;
	string s;

	for (int i = 0; i < rec.length(); i++) {
		if (rec[i] == ' ') {
			ret.push_back(s);
			s.clear();
		}
		else {
			s += rec[i];
		}
	}

	if (!s.empty()) {
		ret.push_back(s);
	}

	return ret;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	unordered_map<string, string> mp; //uid, 닉네임
	vector<pair<string, string>> list; //{출입, uid}

	for (string rec : record) {
		vector<string> str = splitRecord(rec);

		if (str[0] == "Enter") {
			mp[str[1]] = str[2];
			list.push_back({ str[0], str[1] });
		}
		else if (str[0] == "Leave") {
			list.push_back({ str[0], str[1] });
		}
		else {
			mp[str[1]] = str[2];
		}
	}

	for (pair<string, string> rec : list) {
		if (rec.first == "Enter") {
			string nickName = mp[rec.second];
			string s = nickName + "님이 들어왔습니다.";
			answer.push_back(s);
		}
		else {
			string nickName = mp[rec.second];
			string s = nickName + "님이 나갔습니다.";
			answer.push_back(s);
		}
	}

	return answer;
}