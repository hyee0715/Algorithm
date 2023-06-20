class StringIterator {
public:
	vector<pair<char, int>> v;

	StringIterator(string compressedString) {
		char c;
		string num = "";
		for (int i = 0; i < compressedString.length(); i++) {
			if ((compressedString[i] >= 'a' && compressedString[i] <= 'z') || (compressedString[i] >= 'A' && compressedString[i] <= 'Z')) {
				if (!num.empty()) {
					v.push_back({ c, stoi(num) });
				}

				c = compressedString[i];
				num = "";

				continue;
			}

			num += compressedString[i];
		}

		if (!num.empty()) {
			v.push_back({ c, stoi(num) });
		}
	}

	char next() {
		if (v.empty()) {
			return ' ';
		}

		char ret = v[0].first;
		v[0].second = v[0].second - 1;

		if (v[0].second <= 0) {
			v.erase(v.begin());
		}

		return ret;
	}

	bool hasNext() {
		if (!v.empty()) {
			return true;
		}

		return false;
	}
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */