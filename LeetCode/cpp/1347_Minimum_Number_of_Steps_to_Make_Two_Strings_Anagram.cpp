class Solution {
public:
	int minSteps(string s, string t) {
		int answer = 0;

		unordered_map<char, int> sMap, tMap;

		for (int i = 0; i < s.length(); i++) {
			sMap[s[i]]++;
			tMap[t[i]]++;
		}

		for (auto map : tMap) {
			if (sMap.count(map.first) == 1) {
				if (sMap[map.first] <= tMap[map.first]) {
					sMap.erase(map.first);
				}
				else {
					sMap[map.first] = sMap[map.first] - tMap[map.first];
				}
			}
		}

		for (auto map : sMap) {
			answer += sMap[map.first];
		}

		return answer;
	}
};