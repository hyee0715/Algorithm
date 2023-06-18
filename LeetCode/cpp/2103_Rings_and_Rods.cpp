class Solution {
public:
	int countPoints(string rings) {
		int answer = 0;
		unordered_map<int, set<char>> um;

		for (int i = 0; i < rings.length(); i += 2) {
			char color = rings[i];
			int num = rings[i + 1] - 'A';

			um[num].insert(color);
		}

		for (auto m : um) {
			if (m.second.size() == 3) {
				answer++;
			}
		}

		return answer;
	}
};