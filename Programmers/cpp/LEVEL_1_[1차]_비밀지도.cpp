#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string makeBinary(int limitLength, int n) {
	string s;

	while (n > 0) {
		if (n % 2 == 0) {
			s += '0';
		}
		else {
			s += '1';
		}

		n /= 2;
	}

	reverse(s.begin(), s.end());

	while (s.length() < limitLength) {
		s = '0' + s;
	}

	return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	vector<string> map1;
	vector<string> map2;

	for (int i = 0; i < arr1.size(); i++) {
		map1.push_back(makeBinary(n, arr1[i]));
	}

	for (int i = 0; i < arr2.size(); i++) {
		map2.push_back(makeBinary(n, arr2[i]));
	}

	for (int i = 0; i < n; i++) {
		string s;

		for (int j = 0; j < n; j++) {
			if (map1[i][j] == '1' || map2[i][j] == '1') {
				s += '#';
				continue;
			}

			s += ' ';
		}

		answer.push_back(s);
	}

	return answer;
}