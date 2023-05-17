class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int answer = 0;
		queue<int> studentsQ, sandwichesQ;

		for (int student : students) {
			studentsQ.push(student);
		}

		for (int sandwich : sandwiches) {
			sandwichesQ.push(sandwich);
		}

		int cnt = 0;
		while (!studentsQ.empty() && !sandwichesQ.empty()) {
			if (studentsQ.front() == sandwichesQ.front()) {
				studentsQ.pop();
				sandwichesQ.pop();
				cnt = 0;
			}
			else {
				int n = studentsQ.front();
				studentsQ.pop();
				studentsQ.push(n);
				cnt++;

				if (cnt > students.size()) {
					break;
				}
			}
		}

		if (!studentsQ.empty()) {
			answer = studentsQ.size();
		}

		return answer;
	}
};