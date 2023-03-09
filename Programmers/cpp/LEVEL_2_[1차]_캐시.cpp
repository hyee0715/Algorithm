#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	if (cacheSize == 0) {
		answer = (cities.size() * 5);
		return answer;
	}

	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].length(); j++) {
			cities[i][j] = tolower(cities[i][j]);
		}
	}

	int time = 0;

	set<string> st;
	vector<pair<int, string>> v;

	//제일 시간 작은 것을 교체한다.
	//내림차순으로 정렬해서 맨 뒤의 값 제거

	for (int i = 0; i < cities.size(); i++) {
		if (st.find(cities[i]) != st.end()) {
			//캐시에 있으면
			answer += 1;

			//이름 같은 것 시간만 갱신
			for (int j = 0; j < v.size(); j++) {
				if (v[j].second == cities[i]) {
					v[j] = { time, cities[i] };
				}
			}
		}
		else {
			//캐시에 없으면
			answer += 5;

			if (st.size() >= cacheSize) {
				//교체
				sort(v.begin(), v.end(), greater<>());
				string removeCity = v[v.size() - 1].second;
				st.erase(removeCity);
				v.pop_back();

				st.insert(cities[i]);
				v.push_back({ time, cities[i] });
			}
			else {
				//교체 안하고 추가만
				st.insert(cities[i]);
				v.push_back({ time, cities[i] });
			}
		}

		time++;
	}

	return answer;
}