class Solution {
public:
	int divisorSubstrings(int num, int k) {
		int answer = 0;

		string s = to_string(num);
		string temp = "";

		for (int i = 0; i < k; i++) {
			temp += s[i];
		}

		int n = stoi(temp);

		if (n != 0) {
			if (num % n == 0) {
				answer++;
			}
		}

		for (int i = k; i < s.size(); i++) {
			temp.erase(temp.begin());
			temp += s[i];

			int n = stoi(temp);

			if (n == 0) {
				continue;
			}

			if (num % n == 0) {
				answer++;
			}
		}

		return answer;
	}
};