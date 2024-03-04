#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string getUpper(string s) {
	string ret = "";

	for (int i = 0; i < s.length(); i++) {
		ret += toupper(s[i]);
	}

	return ret;
}

void settingMap(unordered_map<string, int>& map, string s) {
	for (int i = 0; i < s.length() - 1; i++) {
		if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) {
			continue;
		}

		if (!(s[i + 1] >= 'a' && s[i + 1] <= 'z') && !(s[i + 1] >= 'A' && s[i + 1] <= 'Z')) {
			continue;
		}

		string str = "";
		str += s[i];
		str += s[i + 1];

		map[str]++;
	}
}

vector<string> getIntersection(unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
	vector<string> intersection;

	for (pair<string, int> m : map1) {
		string map1Name = m.first;
		int map1Cnt = m.second;

		if (map2.count(map1Name) != 0) {
			int map2Cnt = map2[map1Name];

			int size = min(map1Cnt, map2Cnt);

			for (int i = 0; i < size; i++) {
				intersection.push_back(map1Name);
			}
		}
	}

	return intersection;
}

vector<string> getUnion(unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
	vector<string> retUnion;

	for (pair<string, int> m : map1) {
		string map1Name = m.first;
		int map1Cnt = m.second;

		if (map2.count(map1Name) != 0) {
			int map2Cnt = map2[map1Name];

			int size = max(map1Cnt, map2Cnt);

			for (int i = 0; i < size; i++) {
				retUnion.push_back(map1Name);
			}
		}
		else {
			for (int i = 0; i < map1Cnt; i++) {
				retUnion.push_back(map1Name);
			}
		}
	}

	for (pair<string, int> m : map2) {
		string map2Name = m.first;
		int map2Cnt = m.second;

		if (map1.count(map2Name) != 0) {
			continue;
		}

		for (int i = 0; i < map2Cnt; i++) {
			retUnion.push_back(map2Name);
		}
	}

	return retUnion;
}

int solution(string str1, string str2) {
	int answer = 0;

	//대문자로 통일
	str1 = getUpper(str1);
	str2 = getUpper(str2);

	//Map 세팅
	unordered_map<string, int> map1, map2;

	settingMap(map1, str1);
	settingMap(map2, str2);

	//두 문자열의 교집합과 합집합 구하기
	vector<string> stringIntersection = getIntersection(map1, map2);
	vector<string> stringUnion = getUnion(map1, map2);

	int intersecNum = stringIntersection.size();
	int unionNum = stringUnion.size();

	double jaccardSimilarity = 0;

	if (intersecNum == 0 && unionNum == 0) {
		jaccardSimilarity = 1;
	}
	else {
		jaccardSimilarity = (double)intersecNum / unionNum;
	}

	answer = jaccardSimilarity * 65536;

	return answer;
}