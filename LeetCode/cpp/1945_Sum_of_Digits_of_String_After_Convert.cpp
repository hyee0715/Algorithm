class Solution {
public:
	int getLucky(string s, int k) {
		int sum;
		string convert;

		for (int i = 0; i < s.size(); i++) {
			int charToInt = (s[i] - 'a');
			string intToStr = to_string(charToInt + 1);

			convert += intToStr;
		}

		while (k > 0) {
			sum = 0;

			for (int i = 0; i < convert.size(); i++) {
				sum += (convert[i] - '0');
			}

			convert = to_string(sum);

			k--;
		}

		return sum;
	}
};