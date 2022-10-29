class Solution {
public:
	bool areNumbersAscending(string s) {
		vector<string> v;
		vector<int> nums;
		string temp;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				v.push_back(temp);
				temp.clear();
			}
			else {
				temp += s[i];
			}
		}

		if (!temp.empty()) {
			v.push_back(temp);
			temp.clear();
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i][0] >= '0' && v[i][0] <= '9') {
				nums.push_back(stoi(v[i]));
			}
		}

		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] >= nums[i + 1]) {
				return false;
			}
		}

		return true;
	}
};