#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	long num = x;
	while (n > 0) {
		answer.push_back(num);
		num += x;

		n--;
	}

	return answer;
}