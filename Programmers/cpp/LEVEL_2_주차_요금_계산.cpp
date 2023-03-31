#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int getTime(string timeStr) {
	int time = 0;

	string temp = "";
	temp += timeStr[0];
	temp += timeStr[1];
	time += (stoi(temp) * 60);

	temp.clear();
	temp += timeStr[3];
	temp += timeStr[4];
	time += stoi(temp);

	return time;
}

int getFee(int time, int basicTime, int basicFee, int unitTime, int unitFee) {
	//기본 시간 이하면 기본 요금 청구
	if (time <= basicTime) {
		return basicFee;
	}

	int finalFee = basicFee;

	int n = 0;
	if ((time - basicTime) % unitTime != 0) {
		n = (((time - basicTime) / unitTime) + 1) * unitFee;
	}
	else {
		n = ((time - basicTime) / unitTime) * unitFee;
	}

	return finalFee + n;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	int basicTime = fees[0]; //기본 시간
	int basicFee = fees[1]; //기본 요금
	int unitTime = fees[2]; //단위 시간
	int unitFee = fees[3]; //단위 요금

	unordered_map<int, vector<int>> inMap; //입차 기록 (차량 번호, 시간/분)
	unordered_map<int, vector<int>> outMap; //출차 기록 (차량 번호, 시간/분)
	map<int, int> parkingTime; //각 차 누적 주차시간

	for (string record : records) {
		vector<string> v;
		string s = "";

		for (int i = 0; i < record.length(); i++) {
			if (record[i] == ' ') {
				v.push_back(s);
				s.clear();
				continue;
			}

			s += record[i];
		}

		v.push_back(s);

		int carNumber = stoi(v[1]); //차량 번호

		int time = getTime(v[0]); //각 차의 시간 정보

		if (v[2] == "IN") {
			inMap[carNumber].push_back(time);
		}
		else {
			outMap[carNumber].push_back(time);
		}
	}

	//각 차 누적 주차시간 구하기
	for (auto m : inMap) {
		vector<int> parkInTimes = m.second;
		int outNightTime = 23 * 60 + 59;

		if (outMap.count(m.first) == 0) {
			//입차는 있는데 출차가 없는 경우
			int totalParkingTime = outNightTime - parkInTimes[0];
			parkingTime[m.first] = totalParkingTime;
		}
		else if (outMap[m.first].size() != parkInTimes.size()) {
			//입 출차 여러 번, 마지막에 입차하고 출차가 없는 경우
			vector<int> parkOutTimes = outMap[m.first];
			int totalParkingTime = 0;

			for (int i = 0; i < parkInTimes.size() - 1; i++) {
				totalParkingTime += (parkOutTimes[i] - parkInTimes[i]);
			}

			totalParkingTime += outNightTime - parkInTimes[parkInTimes.size() - 1];

			parkingTime[m.first] = totalParkingTime;
		}
		else {
			//입차도 있고 출차 기록도 있는 경우
			vector<int> parkOutTimes = outMap[m.first];
			int totalParkingTime = 0;

			for (int i = 0; i < parkInTimes.size(); i++) {
				totalParkingTime += (parkOutTimes[i] - parkInTimes[i]);
			}

			parkingTime[m.first] = totalParkingTime;
		}
	}

	//최종 주차요금 구하기
	for (auto time : parkingTime) {
		int finalTime = time.second;
		answer.push_back(getFee(finalTime, basicTime, basicFee, unitTime, unitFee));
	}

	return answer;
}