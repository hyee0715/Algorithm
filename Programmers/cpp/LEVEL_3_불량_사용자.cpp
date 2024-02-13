#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<string>> list;
vector<string> strList;

void getList(int cnt, int limit, vector<string>& userId, vector<bool>& visit) {
	if (cnt == limit) {
		vector<string> st(strList.size());
		for (int i = 0; i < strList.size(); i++) {
			st[i] = strList[i];
		}

		list.push_back(st);

		return;
	}
	else {
		for (int i = 0; i < userId.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			strList.push_back(userId[i]);
			getList(cnt + 1, limit, userId, visit);
			visit[i] = false;
			strList.pop_back();
		}
	}
}

bool validateWord(string word, string bannedWord) {
	if (word.length() != bannedWord.length()) {
		return false;
	}

	for (int i = 0; i < word.length(); i++) {
		if (bannedWord[i] == '*') {
			continue;
		}

		if (word[i] != bannedWord[i]) {
			return false;
		}
	}

	return true;
}

vector<vector<string>> searchBannedId(vector<vector<string>>& list, vector<string>& banned_id) {
	vector<vector<string>> ret;

	for (vector<string> str : list) {
		bool flag = true;
		for (int i = 0; i < str.size(); i++) {
			if (!validateWord(str[i], banned_id[i])) {
				flag = false;
			}
		}

		if (flag) {
			vector<string> s(str.size());

			for (int i = 0; i < str.size(); i++) {
				s[i] = str[i];
			}

			ret.push_back(s);
		}
	}

	return ret;
}

int getBannedSize(vector<vector<string>>& bannedList) {
	unordered_set<string> st;

	for (vector<string> s : bannedList) {
		sort(s.begin(), s.end());

		string sb = "";
		for (int i = 0; i < s.size(); i++) {
			sb += s[i];
		}

		st.insert(sb);
	}

	return st.size();
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;

	int listSize = banned_id.size();
	vector<bool> visit(user_id.size(), false);

	getList(0, listSize, user_id, visit);

	vector<vector<string>> bannedList = searchBannedId(list, banned_id);

	answer = getBannedSize(bannedList);

	return answer;
}