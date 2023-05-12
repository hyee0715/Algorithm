class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int answer = INT_MAX;

		unordered_map<char, int> um;

		for (int i = 0; i < text.length(); i++) {
			um[text[i]]++;
		}

		char alphabet[] = { 'b', 'a', 'l', 'o', 'n' };
		for (char c : alphabet) {
			if (um.count(c) == 0) {
				return 0;
			}
		}

		for (auto m : um) {
			if (m.first == 'b' || m.first == 'a' || m.first == 'n') {
				answer = min(answer, m.second);
				continue;
			}

			if (m.first == 'l' || m.first == 'o') {
				if (m.second < 2) {
					return 0;
				}

				answer = min(answer, m.second / 2);
			}
		}

		return answer;
	}
};