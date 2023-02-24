class Solution {
    private boolean isPalindrome(StringBuilder sb) {
        StringBuilder rev = new StringBuilder(sb);

        rev.reverse();

        if (sb.toString().equals(rev.toString())) {
            return true;
        }

        return false;
    }

    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return "";
        }

        StringBuilder temp = new StringBuilder(palindrome);

        for (int j = 0; j < 26; j++) {
            for (int i = 0; i < temp.length(); i++) {
                temp = new StringBuilder(palindrome);

                if (temp.charAt(i) == 'a') {
                    temp.setCharAt(temp.length() - 1 - i, (char)('a' + j));
                } else {
                    temp.setCharAt(i, (char)('a' + j));
                }

                if (!isPalindrome(temp)) {
                    return temp.toString();
                }
            }
        }

        return temp.toString();
    }
}