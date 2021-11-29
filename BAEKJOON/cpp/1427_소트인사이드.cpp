#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	// n�� �ڸ��� ���
	int count = 0, temp = n;
	while (temp > 0) {
		count++;
		temp = temp / 10;
	}

	vector<int> vec(count); // �ڸ�����ŭ�� ���� �迭 ����
	temp = n;
	int index = 0;

	while (temp > 0) {
		vec[index++] = temp % 10;
		temp = temp / 10;
	}

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
}