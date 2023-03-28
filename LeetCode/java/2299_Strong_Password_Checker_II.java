import java.util.HashSet;
import java.util.Set;

class Solution {
    private boolean containsLowercase(String password) {
        for (int i = 0; i < password.length(); i++) {
            if (password.charAt(i) >= 'a' && password.charAt(i) <= 'z') {
                return true;
            }
        }

        return false;
    }

    private boolean containsUppercase(String password) {
        for (int i = 0; i < password.length(); i++) {
            if (password.charAt(i) >= 'A' && password.charAt(i) <= 'Z') {
                return true;
            }
        }

        return false;
    }

    private boolean containsDigit(String password) {
        for (int i = 0; i < password.length(); i++) {
            if (password.charAt(i) >= '0' && password.charAt(i) <= '9') {
                return true;
            }
        }

        return false;
    }

    private boolean containsSpecialCharacter(String password) {
        String sp = "!@#$%^&*()-+";
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < sp.length(); i++) {
            set.add(sp.charAt(i));
        }

        for (int i = 0; i < password.length(); i++) {
            if (set.contains(password.charAt(i))) {
                return true;
            }
        }

        return false;
    }

    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) {
            return false;
        }

        for (int i = 0; i < password.length() - 1; i++) {
            if (password.charAt(i) == password.charAt(i + 1)) {
                return false;
            }
        }

        return containsLowercase(password) && containsUppercase(password) && containsDigit(password) && containsSpecialCharacter(password);
    }
}