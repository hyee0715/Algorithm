class Solution {
public:
	bool isSameAfterReversals(int num) {
		string s = to_string(num);

		if (s.size() == 1)
			return true;

		string r = s;
		reverse(r.begin(), r.end());

		while (1) {
			if (r[0] == '0') {
				r.erase(0, 1);
			}
			else {
				break;
			}
		}

		reverse(r.begin(), r.end());

		if (r == s)
			return true;
		return false;
	}
};