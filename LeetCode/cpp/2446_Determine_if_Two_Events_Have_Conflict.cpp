class Solution {
public:
	int extractTime(string time) {
		int ret = 0;

		string temp = "";
		temp += time[0];
		temp += time[1];

		ret += (stoi(temp) * 60);

		temp = "";
		temp += time[3];
		temp += time[4];

		ret += stoi(temp);

		return ret;
	}

	bool haveConflict(vector<string>& event1, vector<string>& event2) {
		int event1Start = extractTime(event1[0]);
		int event1End = extractTime(event1[1]);

		int event2Start = extractTime(event2[0]);
		int event2End = extractTime(event2[1]);

		if (event1End == event2Start || event2End == event1Start || event1Start == event2Start || event1End == event2End) {
			return true;
		}

		if ((event2Start > event1Start && event2Start < event1End) || (event1Start > event2Start && event1Start < event2End)) {
			return true;
		}

		return false;
	}
};