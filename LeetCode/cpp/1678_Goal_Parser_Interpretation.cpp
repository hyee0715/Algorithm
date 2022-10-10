class Solution {
public:
	string interpret(string command) {
		string answer, s;
		bool flag = false;

		for (int i = 0; i < command.size(); i++) {
			if (command[i] != '(' && command[i] != ')' && flag == false) {
				answer += command[i];
			}

			if (command[i] != '(' && command[i] != ')' && flag == true) {
				s += command[i];
			}

			if (command[i] == '(') {
				flag = true;
				s.clear();
			}
			else if (command[i] == ')') {
				flag = false;

				if (s.empty()) {
					answer += 'o';
				}
				else {
					answer += s;
				}
			}
		}

		return answer;
	}
};