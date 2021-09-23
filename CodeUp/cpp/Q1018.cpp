#include <iostream>
#include <string>
using namespace std;

int main() {
	string time;
	string hour = "", minute = "";
	bool isMinute = false;

	getline(cin, time);

	for (int i = 0; i < time.length(); i++) {
		if (time[i] != ':' && !isMinute) { // �ð�
			hour += time[i];
		}
		else if (time[i] == ':') {
			isMinute = true;
		}
		else if (time[i] != ':' && isMinute) { // ��
			minute += time[i];
		}
	}

	cout << hour << ":" << minute;

	return 0;
}
