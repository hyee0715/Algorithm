#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<int, int> um;

	vector<string> extract1;
	vector<string> extract2;
	vector<vector<int>> extract3;

	//가장 바깥 {} 없애기
	string temp;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == ',' && s[i - 1] == '}' && s[i + 1] == '{') {
			extract1.push_back(temp);
			temp.clear();
			continue;
		}

		temp += s[i];
	}

	extract1.push_back(temp);
	temp.clear();

	//각 튜플의 {} 없애기
	for (string ex : extract1) {
		for (int i = 1; i < ex.length() - 1; i++) {
			temp += ex[i];
		}

		extract2.push_back(temp);
		temp.clear();
	}

	//각 튜플의 숫자 추출
	for (string ext : extract2) {
		vector<int> v;

		for (int i = 0; i < ext.length(); i++) {
			if (ext[i] == ',') {
				v.push_back(stoi(temp));
				temp.clear();
				continue;
			}

			temp += ext[i];
		}

		if (!temp.empty()) {
			v.push_back(stoi(temp));
			temp.clear();
		}

		extract3.push_back(v);
	}

	for (vector<int> vec : extract3) {
		for (int i = 0; i < vec.size(); i++) {
			um[vec[i]]++;
		}
	}

	vector<pair<int, int>> count; //숫자 카운트, 수
	for (pair<int, int> m : um) {
		count.push_back({ m.second, m.first });
	}

	sort(count.begin(), count.end(), greater<>());

	for (int i = 0; i < count.size(); i++) {
		answer.push_back(count[i].second);
	}

	return answer;
}