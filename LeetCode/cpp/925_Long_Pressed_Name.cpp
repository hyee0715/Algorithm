class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		char prev = name[0];
		int p1 = 0, p2 = 0;

		if (name.size() > typed.size())
			return false;

		while (p2 < typed.size()) {
			if (name[p1] == typed[p2]) {
				p2++;

				prev = name[p1];
				p1++;
			}
			else {
				if (prev == typed[p2]) {
					p2++;
				}
				else {
					return false;
				}
			}
		}

		if (p1 < name.size())
			return false;

		return true;
	}
};