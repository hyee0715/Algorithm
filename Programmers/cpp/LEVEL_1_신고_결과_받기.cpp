#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	unordered_map<string, set<string>> userReportedList; //해당 유저를 신고한 유저 목록
	unordered_map<string, set<string>> userReportingList; // 각 유저가 신고한 목록
	set<string> reportList; //k번 이상 신고되어 정지될 유저

	for (string rep : report) {
		string s;
		string userId;
		string reportedId;

		for (int i = 0; i < rep.length(); i++) {
			if (rep[i] == ' ') {
				userId = s;
				s.clear();
				continue;
			}

			s += rep[i];
		}

		reportedId = s;

		userReportedList[reportedId].insert(userId);
		userReportingList[userId].insert(reportedId);
	}

	for (auto list : userReportedList) {
		if (list.second.size() >= k) {
			reportList.insert(list.first);
		}
	}

	for (string name : id_list) {
		set<string> reportSet = userReportingList[name];
		int cnt = 0;

		for (string rp : reportSet) {
			if (reportList.find(rp) != reportList.end()) {
				cnt++;
			}
		}

		answer.push_back(cnt);
	}

	return answer;
}