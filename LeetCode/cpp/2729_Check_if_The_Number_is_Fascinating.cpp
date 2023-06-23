class Solution {
public:
	bool isFascinating(int n) {
		int n_double = n * 2;
		int n_triple = n * 3;

		string s = to_string(n) + to_string(n_double) + to_string(n_triple);

		vector<int> v(10, 0);

		for (int i = 0; i < s.length(); i++) {
			v[s[i] - '0']++;
		}

		for (int i = 1; i <= 9; i++) {
			if (v[i] != 1) {
				return false;
			}
		}

		return true;
	}
};