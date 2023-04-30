class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> odd = { 0 };
		vector<int> even = { -1, 1 };

		if (n == 1) {
			return odd;
		}
		else if (n == 2) {
			return even;
		}

		for (int i = 3; i <= n; i++) {
			if (i % 2 == 0) {
				even.push_back(-1 * (i / 2));
				even.push_back(i / 2);
			}
			else {
				odd = even;
				odd.push_back(0);
			}
		}

		if (n % 2 == 0) {
			return even;
		}

		return odd;
	}
};