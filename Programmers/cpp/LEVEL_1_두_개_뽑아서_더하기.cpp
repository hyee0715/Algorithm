#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	vector<int> vec;

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 0; j < numbers.size(); j++) {
			if (i != j)
				vec.push_back(numbers[i] + numbers[j]);
		}
	}

	sort(vec.begin(), vec.end());

	answer.push_back(vec[0]);

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i - 1] != vec[i]) {
			answer.push_back(vec[i]);
		}
	}

	return answer;
}