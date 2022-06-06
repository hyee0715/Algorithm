class Solution {
public:
	set<int> s;

	int singleNumber(vector<int>& nums) {
		for (auto num : nums) {
			if (s.find(num) == s.end()) {
				s.insert(num);
			}
			else {
				s.erase(s.find(num));
			}
		}

		int answer = *s.begin();
		return answer;
	}
};