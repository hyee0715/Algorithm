class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		string answer;
		set<string> st;

		for (string s : dictionary) {
			st.insert(s);
		}

		vector<string> arr;
		string temp;
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == ' ') {
				arr.push_back(temp);
				temp.clear();
				continue;
			}

			temp += sentence[i];
		}

		if (!temp.empty()) {
			arr.push_back(temp);
		}

		for (string s : arr) {
			string sb;
			bool flag = false;

			for (int i = 0; i < s.length(); i++) {
				sb += s[i];

				if (st.find(sb) != st.end()) {
					answer += sb;
					answer += " ";
					flag = true;
					break;
				}
			}

			if (!flag) {
				answer += sb;
				answer += " ";
			}
		}

		answer.erase(answer.length() - 1, 1);

		return answer;
	}
};