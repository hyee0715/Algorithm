class Solution {
    boolean isPalindrome(String s) {
        StringBuilder rev = new StringBuilder(s);
        rev.reverse();

        if (s.equals(rev.toString())) {
            return true;
        }

        return false;
    }

    public int removePalindromeSub(String s) {
        if (isPalindrome(s)) {
            return 1;
        }

        return 2;
    }
}