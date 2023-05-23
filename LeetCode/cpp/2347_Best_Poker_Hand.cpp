class Solution {
public:
	bool isFlush(unordered_map<char, int>& map) {
		for (auto m : map) {
			if (m.second == 5) {
				return true;
			}
		}

		return false;
	}

	bool isThree(unordered_map<int, int>& map) {
		for (auto m : map) {
			if (m.second >= 3) {
				return true;
			}
		}

		return false;
	}

	bool isPair(unordered_map<int, int>& map) {
		for (auto m : map) {
			if (m.second == 2) {
				return true;
			}
		}

		return false;
	}

	string bestHand(vector<int>& ranks, vector<char>& suits) {
		string answer;

		unordered_map<int, int> rMap;
		unordered_map<char, int> sMap;

		for (int rank : ranks) {
			rMap[rank]++;
		}

		for (char suit : suits) {
			sMap[suit]++;
		}

		if (isFlush(sMap)) {
			answer = "Flush";
		}
		else if (isThree(rMap)) {
			answer = "Three of a Kind";
		}
		else if (isPair(rMap)) {
			answer = "Pair";
		}
		else {
			answer = "High Card";
		}

		return answer;
	}
};