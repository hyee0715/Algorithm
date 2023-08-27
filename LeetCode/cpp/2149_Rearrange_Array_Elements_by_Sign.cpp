class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int> answer;
		vector<int> v1, v2;

		for (int n : nums) {
			if (n < 0) {
				v2.push_back(n);
			}
			else {
				v1.push_back(n);
			}
		}

		for (int i = 0; i < v1.size(); i++) {
			answer.push_back(v1[i]);
			answer.push_back(v2[i]);
		}

		return answer;
	}
};