class Solution {
public:
	string digitSum(string s, int k) {
		while (s.length() > k) {
			string temp;
			int cnt = 0;
			int num = 0;

			for (int i = 0; i < s.length(); i++) {
				num += s[i] - '0';
				cnt++;

				if (cnt == k) {
					temp += to_string(num);

					num = 0;
					cnt = 0;
				}
			}

			if (s.length() % k != 0) {
				temp += to_string(num);
			}

			s = temp;
		}

		return s;
	}
};