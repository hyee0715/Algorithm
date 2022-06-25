#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int n, k;
vector<int> nums;

void input() {
	cin >> n >> k >> s;

	string temp = "";
	bool negative = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ',' && s[i] != '-')
			temp += s[i];
		else if (s[i] == '-')
			negative = true;
		else {
			if (negative == true)
				nums.push_back(stoi(temp) * -1);
			else
				nums.push_back(stoi(temp));
			temp = "";
			negative = false;
		}
	}

	if (!temp.empty()) {
		if (negative == true)
			nums.push_back(stoi(temp) * -1);
		else
			nums.push_back(stoi(temp));
		temp = "";
		negative = false;
	}
}

vector<int> calculate(vector<int> nums) {
	vector<int> v;
	
	for (int i = 0; i < nums.size() - 1; i++) {
		v.push_back(nums[i + 1] - nums[i]);
	}

	return v;
}

void solution() {
	while (k > 0) {
		nums = calculate(nums);
		k--;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (i != nums.size() - 1)
			cout << nums[i] << ",";
		else
			cout << nums[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}