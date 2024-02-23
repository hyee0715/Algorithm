#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string s = to_string(n);

	vector<char> arr;

	for (int i = 0; i < s.length(); i++) {
		arr.push_back(s[i]);
	}

	sort(arr.begin(), arr.end(), greater<>());

	s = "";
	for (char c : arr) {
		s += c;
	}

	answer = stol(s);

	return answer;
}