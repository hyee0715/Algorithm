#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b) {
	if (a + b <= b + a) {
		return false;
	}

	return true;
}

bool allZeroCheck(vector<int> numbers) {
	for (int n : numbers) {
		if (n != 0) {
			return false;
		}
	}

	return true;
}

string solution(vector<int> numbers) {
	string answer = "";

	if (allZeroCheck(numbers)) {
		return "0";
	}

	vector<string> v;

	for (int i = 0; i < numbers.size(); i++) {
		v.push_back(to_string(numbers[i]));
	}

	sort(v.begin(), v.end(), compare);

	for (string s : v) {
		answer += s;
	}

	return answer;
}