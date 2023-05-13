class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> answer;
		deque<int> dq;

		sort(deck.begin(), deck.end());

		for (int i = deck.size() - 1; i >= 0; i--) {
			if (!dq.empty()) {
				int n = dq.back();
				dq.pop_back();
				dq.push_front(n);
			}

			dq.push_front(deck[i]);
		}

		while (!dq.empty()) {
			answer.push_back(dq.front());
			dq.pop_front();
		}

		return answer;
	}
};