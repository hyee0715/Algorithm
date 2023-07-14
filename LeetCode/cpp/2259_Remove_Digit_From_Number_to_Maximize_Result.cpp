class Solution {
public:
	string removeDigit(string number, char digit) {
		string answer = "";
		vector<int> idx;
		vector<string> v;

		for (int i = 0; i < number.length(); i++) {
			if (number[i] == digit) {
				idx.push_back(i);
			}
		}

		for (int i : idx) {
			string temp = number;

			temp.erase(temp.begin() + i);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		answer = v[v.size() - 1];

		return answer;
	}
};