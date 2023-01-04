class Solution {
public:
	bool check(string num) {
		if (num.length() == 0) {
			return true;
		}

		if (num.length() == 1) {
			if (num != "0" && num != "1" && num != "8") {
				return false;
			}
		}

		if (!(num[0] == '0' && num[num.length() - 1] == '0') && !(num[0] == '1' && num[num.length() - 1] == '1') && !(num[0] == '8' && num[num.length() - 1] == '8') && !(num[0] == '6' && num[num.length() - 1] == '9') && !(num[0] == '9' && num[num.length() - 1] == '6')) {
			return false;
		}

		if (!check(num.substr(1, num.length() - 2))) {
			return false;
		}

		return true;
	}

	bool isStrobogrammatic(string num) {
		if (check(num)) {
			return true;
		}

		return false;
	}
};