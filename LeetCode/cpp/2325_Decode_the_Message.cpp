class Solution {
public:
	string decodeMessage(string key, string message) {
		string answer;
		unordered_map<char, char> um;

		char alphabet = 'a';

		for (int i = 0; i < key.length(); i++) {
			if (key[i] == ' ' || um.count(key[i]) == 1) {
				continue;
			}

			um[key[i]] = alphabet++;;
		}

		for (int i = 0; i < message.length(); i++) {
			if (message[i] == ' ') {
				answer += ' ';
				continue;
			}

			answer += um[message[i]];
		}

		return answer;
	}
};