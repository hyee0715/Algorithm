class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		int carry = 0;
		for (int i = num.size() - 1; i >= 0; i--) {
			int n = k % 10;
			k = k / 10;

			int sum = n + num[i] + carry;
			if (sum >= 10) {
				num[i] = sum % 10;
				carry = 1;
			}
			else {
				num[i] = sum;
				carry = 0;
			}
		}

		while (k > 0) {
			int n = k % 10;
			k = k / 10;

			int sum = n + carry;
			if (sum >= 10) {
				sum = sum % 10;
				num.insert(num.begin(), sum);
				carry = 1;
			}
			else {
				num.insert(num.begin(), sum);
				carry = 0;
			}
		}

		if (carry == 1) {
			num.insert(num.begin(), carry);
		}

		return num;
	}
};