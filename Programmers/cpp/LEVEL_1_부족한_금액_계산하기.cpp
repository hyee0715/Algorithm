using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = -1;

	long long updatePrice = 0;

	for (int i = 1; i <= count; i++) {
		updatePrice += (price * i);
	}

	if (money < updatePrice) {
		answer = updatePrice - money;
	}
	else {
		answer = 0;
	}

	return answer;
}