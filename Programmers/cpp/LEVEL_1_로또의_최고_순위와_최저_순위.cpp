#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	set<int> st(win_nums.begin(), win_nums.end());

	int correctCnt = 0;
	int zeroCnt = 0;
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			zeroCnt++;

			continue;
		}

		if (st.find(lottos[i]) != st.end()) {
			correctCnt++;
		}
	}

	//순위 세팅
	unordered_map<int, int> um; //당첨개수, 순위

	for (int i = 1; i <= 6; i++) {
		um[7 - i] = i;
	}
	um[0] = 6;

	answer.push_back(um[correctCnt + zeroCnt]); //최고 순위
	answer.push_back(um[correctCnt]); //최저 순위
	return answer;
}