#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int changeTime(string s) {
	int ret = 0;
	string time = "";
	time += s[0];
	time += s[1];

	ret += (stoi(time) * 60);

	time.clear();
	time += s[3];
	time += s[4];

	ret += stoi(time);
	return ret;
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<pair<int, pair<string, int>>> arr; // 시작 시간, 과목 이름, 플레이 시간
	stack<pair<string, int>> st; // 과목 이름, 남은 플레이 시간

	for (vector<string> plan : plans) {
		int time = changeTime(plan[1]);

		arr.push_back({ time, {plan[0], stoi(plan[2])} });
	}

	sort(arr.begin(), arr.end());

	int curStartTime = arr[0].first;
	string curName = arr[0].second.first;
	int curPlayTime = arr[0].second.second;
	int curEndTime = curStartTime + curPlayTime;

	for (int i = 1; i < arr.size(); i++) {
		int nextStartTime = arr[i].first;
		string nextName = arr[i].second.first;
		int nextPlayTime = arr[i].second.second;

		if (curEndTime < nextStartTime) {
			answer.push_back(curName);

			// 스택이 비어있으면
			if (st.empty()) {
				curStartTime = nextStartTime;
				curName = nextName;
				curPlayTime = nextPlayTime;
				curEndTime = curStartTime + curPlayTime;
				continue;
			}

			//스택이 안비어있으면 스택에서 꺼낸다
			curStartTime = curEndTime;
			curName = st.top().first;
			curPlayTime = st.top().second;
			curEndTime = curStartTime + curPlayTime;

			st.pop();
			i--; //해당 반복문 다시 돌기
			continue;
		}

		if (curEndTime > nextStartTime) {
			int time = curPlayTime - (nextStartTime - curStartTime);
			st.push({ curName, time });

			curStartTime = nextStartTime;
			curName = nextName;
			curPlayTime = nextPlayTime;
			curEndTime = curStartTime + curPlayTime;
			continue;
		}

		if (curEndTime == nextStartTime) {
			answer.push_back(curName);

			curStartTime = nextStartTime;
			curName = nextName;
			curPlayTime = nextPlayTime;
			curEndTime = curStartTime + curPlayTime;
		}
	}

	answer.push_back(curName);

	while (!st.empty()) {
		answer.push_back(st.top().first);
		st.pop();
	}

	return answer;
}