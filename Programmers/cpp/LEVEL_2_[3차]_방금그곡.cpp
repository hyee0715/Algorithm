#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

char alphabet = 'a';

string replaceMelody(string melody, unordered_map<string, char>& um) {
	string s;

	for (int i = 0; i < melody.length(); i++) {
		if (i < melody.length() - 1 && melody[i] != '#' && melody[i + 1] == '#') {
			string ss;
			ss += melody[i];
			ss += melody[i + 1];

			if (um.count(ss) != 0) {
				s += um[ss];
			}
			else {
				um[ss] = alphabet;
				s += alphabet;

				alphabet++;
			}

			i++;
			continue;
		}

		s += melody[i];
	}

	return s;
}

vector<string> split(string str, char spl) {
	vector<string> v;
	string s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == spl) {
			v.push_back(s);
			s.clear();
		}
		else {
			s += str[i];
		}
	}

	if (!s.empty()) {
		v.push_back(s);
	}

	return v;
}

int getPlayTime(string start, string end) {
	vector<string> starts = split(start, ':');
	vector<string> ends = split(end, ':');

	vector<int> startTimes = { stoi(starts[0]), stoi(starts[1]) };
	vector<int> endTimes = { stoi(ends[0]), stoi(ends[1]) };

	if (endTimes[0] < startTimes[0]) {
		endTimes[0] = endTimes[0] + 24;
	}

	int startMinutes = startTimes[0] * 60 + startTimes[1];
	int endMinutes = endTimes[0] * 60 + endTimes[1];

	return endMinutes - startMinutes;
}

string makePlayLine(int playTime, string score) {
	string playLine;

	if (score.length() < playTime) { //곡의 길이가 재생시간보다 짧다면
		int copy = playTime / score.length();
		int plus = playTime % score.length();

		for (int i = 0; i < copy; i++) {
			playLine += score;
		}

		for (int i = 0; i < plus; i++) {
			playLine += score[i];
		}
	}
	else {
		for (int i = 0; i < playTime; i++) {
			playLine += score[i];
		}
	}

	return playLine;
}

bool findNeoMusic(string playLine, string melody) {
	if (playLine.length() < melody.length()) {
		return false;
	}

	string cur;
	cur += playLine.substr(0, melody.length());

	int idx = melody.length() - 1;

	while (idx < playLine.length()) {
		if (cur == melody) {
			return true;
		}

		cur.erase(0, 1);
		idx++;

		if (idx == playLine.length()) {
			break;
		}

		cur += playLine[idx];
	}

	return false;
}

//재생 시간 제일 긴 순서, 재생 시간이 같을 경우 먼저 입력된 순서
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first >= b.second.first) {

		if (a.second.first == b.second.first) {

			if (a.second.second < b.second.second) {
				return true;
			}

			return false;
		}

		return true;
	}

	return false;
}

string findAnswer(vector<pair<string, pair<int, int>>> musics) {
	sort(musics.begin(), musics.end(), compare);

	return musics[0].first;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	vector<pair<string, pair<int, int>>> answers; //재생 시간, 입력 순서, 음악 제목

	unordered_map<string, char> um; //key: #이 들어간 음, value: 치환 알파벳

	m = replaceMelody(m, um);

	int sequence = 0;

	for (string music : musicinfos) {
		vector<string> infos = split(music, ',');

		string melody = replaceMelody(infos[3], um);

		int playTime = getPlayTime(infos[0], infos[1]);

		string playLine = makePlayLine(playTime, melody);

		if (findNeoMusic(playLine, m)) {
			answers.push_back({ infos[2], {playTime, sequence} }); //재생 시간, 입력 순서, 음악 제목
		}

		sequence++;
	}

	if (answers.size() == 0) {
		answer = "(None)";
	}
	else if (answers.size() == 1) {
		answer = answers[0].first;
	}
	else {
		answer = findAnswer(answers);
	}

	return answer;
}