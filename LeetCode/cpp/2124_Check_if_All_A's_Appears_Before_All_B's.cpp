class Solution {
public:
	bool checkString(string s) {
		bool flag = false;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'b')
				flag = true;
			else {
				if (flag == true)
					return false;
			}
		}

		return true;
	}
};