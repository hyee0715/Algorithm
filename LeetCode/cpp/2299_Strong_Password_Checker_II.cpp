class Solution {
public:
	bool containsLowercase(string password) {
		for (int i = 0; i < password.length(); i++) {
			if (password[i] >= 'a' && password[i] <= 'z') {
				return true;
			}
		}

		return false;
	}

	bool containsUppercase(string password) {
		for (int i = 0; i < password.length(); i++) {
			if (password[i] >= 'A' && password[i] <= 'Z') {
				return true;
			}
		}

		return false;
	}

	bool containsDigit(string password) {
		for (int i = 0; i < password.length(); i++) {
			if (password[i] >= '0' && password[i] <= '9') {
				return true;
			}
		}

		return false;
	}

	bool containsSpecialCharacter(string password) {
		string sp = "!@#$%^&*()-+";
		set<char> st;
		for (int i = 0; i < sp.length(); i++) {
			st.insert(sp[i]);
		}

		for (int i = 0; i < password.length(); i++) {
			if (st.find(password[i]) != st.end()) {
				return true;
			}
		}

		return false;
	}

	bool strongPasswordCheckerII(string password) {
		if (password.length() < 8) {
			return false;
		}

		for (int i = 0; i < password.length() - 1; i++) {
			if (password[i] == password[i + 1]) {
				return false;
			}
		}

		return containsLowercase(password) && containsUppercase(password) && containsDigit(password) && containsSpecialCharacter(password);
	}
};