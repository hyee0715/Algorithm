class Solution {
public:
	string removeTrailingZeros(string num) {
		for (int i = num.length() - 1; i >= 0; i--) {
			if (num[i] == '0') {
				num.erase(num.begin() + i);
			}
			else {
				break;
			}
		}

		return num;
	}
};