#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> op = { "+", "-", "*" };
vector<string> seq;

void getSeq(int cnt, vector<bool>& visit, string s) {
	if (cnt == op.size()) {
		seq.push_back(s);

		return;
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			s = s + op[i];
			getSeq(cnt + 1, visit, s);
			s.erase(s.length() - 1, 1);
			visit[i] = false;
		}
	}
}

vector<string> splitExpression(string ex) {
	vector<string> ret;
	string s = "";

	for (int i = 0; i < ex.length(); i++) {
		if (ex[i] == '-' || ex[i] == '+' || ex[i] == '*') {
			ret.push_back(s);

			s.clear();
			s += ex[i];
			ret.push_back(s);
			s.clear();
		}
		else {
			s += ex[i];
		}
	}

	ret.push_back(s);

	return ret;
}

long long calculate(long long a, long long b, string op) {
	if (op == "+") {
		return a + b;
	}

	if (op == "-") {
		return a - b;
	}

	return a * b;
}

long long solution(string expression) {
	long long answer = 0;

	vector<bool> visit(op.size());
	string s = "";

	getSeq(0, visit, s);

	vector<string> expressions = splitExpression(expression);

	for (int i = 0; i < seq.size(); i++) {
		vector<string> cal;
		vector<string> temp;

		for (int j = 0; j < expressions.size(); j++) {
			temp.push_back(expressions[j]);
		}

		for (int j = 0; j < seq[i].length(); j++) {
			string op = "";
			op += seq[i][j];

			for (int k = 0; k < temp.size(); k++) {
				string element = temp[k];

				if (element == op) {
					long long a = stoll(cal[cal.size() - 1], 0);
					long long b = stoll(temp[k + 1], 0);

					long long result = calculate(a, b, element);

					cal.pop_back();
					k++;
					cal.push_back(to_string(result));
				}
				else {
					cal.push_back(element);
				}
			}

			temp.clear();

			for (string ex : cal) {
				temp.push_back(ex);
			}

			cal.clear();
		}

		long long absNum = abs(stoll(temp[0]));
		answer = max(answer, absNum);
	}

	return answer;
}