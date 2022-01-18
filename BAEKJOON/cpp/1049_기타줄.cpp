#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<double> package; // 패키지 가격
vector<int> oneString; // 낱개 가격
vector<double> pricePerStringOfPackage; // (패키지 / 6) == 패키지 낱개 가격
double minPricePerString, minOneString, minPackage; // 패키지 낱개 가격과 낱개 가격의 최솟값
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
	// 패키지의 개당 가격 구하기
	findPricePerStringOfPackage();

	// 각 벡터의 최솟값 구하기
	sort(pricePerStringOfPackage.begin(), pricePerStringOfPackage.end());
	minPricePerString = pricePerStringOfPackage[0];

	sort(oneString.begin(), oneString.end());
	minOneString = oneString[0];

	sort(package.begin(), package.end());
	minPackage = package[0];

	// 두 min 값 비교
	if (minPricePerString < minOneString) { // 패키지 개당 가격이 더 저렴할 경우
		answer = minPackage * (n / 6);
		n = n % 6;
	}
	else { // 낱개 가격이 더 저렴할 경우
		answer = minOneString * n;
		cout << answer;
		return;
	}

	// n은 6 미만인 값이 남았을 것이다.
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