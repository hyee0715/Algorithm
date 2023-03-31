class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> answer;

		vector<set<char>> sv;
		vector<string> v;

		set<char> st;
		st.insert(s[0]);
		sv.push_back(st);

		string str = "";
		str += s[0];
		v.push_back(str);

		for (int i = 1; i < s.length(); i++) {
			bool flag = false;

			for (int j = 0; j < sv.size(); j++) {
				set<char> setchar = sv[j];

				if (setchar.find(s[i]) != setchar.end()) {
					//현재 문자가 어떠한 set에 존재하면
					flag = true;

					for (int k = j + 1; k < sv.size(); k++) {
						for (char c : sv[k]) {
							sv[j].insert(c);
						}

						v[j] += v[k];
					}

					int size = sv.size();
					for (int k = 1; k <= size - j - 1; k++) {
						sv.pop_back();
						v.pop_back();
					}

					sv[j].insert(s[i]);
					v[j] += s[i];

					break;
				}
			}

			if (flag == false) {
				//모든 set에 존재하지 않으면
				st.clear();
				str.clear();

				st.insert(s[i]);
				sv.push_back(st);

				str += s[i];
				v.push_back(str);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			answer.push_back(v[i].length());
		}

		return answer;
	}
};