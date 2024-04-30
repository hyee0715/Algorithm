#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<char> v;
	int removeCount = 0;

	int idx = 0;
	for (; idx < number.length(); idx++) {
		if (removeCount == k) {
			break;
		}

		char c = number[idx];

		if (v.empty()) {
			v.push_back(c);
		}
		else {
			while (!v.empty() || removeCount == k) {
				if (v[v.size() - 1] < c) {
					v.pop_back();
					removeCount++;

					if (removeCount == k) {
						break;
					}
				}
				else {
					break;
				}
			}

			v.push_back(c);
		}
	}

	if (v.size() >= number.length() - k) {
		for (int i = 0; i < number.length() - k; i++) {
			answer += v[i];
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			answer += v[i];
		}

		while (idx < number.length()) {
			answer += number[idx++];
		}
	}

	return answer;
}