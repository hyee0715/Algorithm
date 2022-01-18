#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<double> package; // ��Ű�� ����
vector<int> oneString; // ���� ����
vector<double> pricePerStringOfPackage; // (��Ű�� / 6) == ��Ű�� ���� ����
double minPricePerString, minOneString, minPackage; // ��Ű�� ���� ���ݰ� ���� ������ �ּڰ�
int answer = 0;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		package.push_back(a);
		oneString.push_back(b);
	}
}

void findPricePerStringOfPackage() {
	for (int i = 0; i < package.size(); i++) {
		pricePerStringOfPackage.push_back(package[i] / 6);
	}
}

void solution() {
	// ��Ű���� ���� ���� ���ϱ�
	findPricePerStringOfPackage();

	// �� ������ �ּڰ� ���ϱ�
	sort(pricePerStringOfPackage.begin(), pricePerStringOfPackage.end());
	minPricePerString = pricePerStringOfPackage[0];

	sort(oneString.begin(), oneString.end());
	minOneString = oneString[0];

	sort(package.begin(), package.end());
	minPackage = package[0];

	// �� min �� ��
	if (minPricePerString < minOneString) { // ��Ű�� ���� ������ �� ������ ���
		answer = minPackage * (n / 6);
		n = n % 6;
	}
	else { // ���� ������ �� ������ ���
		answer = minOneString * n;
		cout << answer;
		return;
	}

	// n�� 6 �̸��� ���� ������ ���̴�.
	if (minOneString * n < minPackage) {
		answer += (minOneString * n);
	}
	else {
		answer += minPackage;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}