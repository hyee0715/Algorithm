class Solution {
    public boolean halvesAreAlike(String s) {
        int mid = s.length() / 2;
        int vowelsCnt1 = 0, vowelsCnt2 = 0;

        for (int i = 0; i < mid; i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'u' || s.charAt(i) == 'o' || s.charAt(i) == 'i' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'U' || s.charAt(i) == 'O' || s.charAt(i) == 'I') {
                vowelsCnt1++;
            }
        }

        for (int i = mid; i < s.length(); i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'u' || s.charAt(i) == 'o' || s.charAt(i) == 'i' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'U' || s.charAt(i) == 'O' || s.charAt(i) == 'I') {
                vowelsCnt2++;
            }
        }

        if (vowelsCnt1 == vowelsCnt2) {
            return true;
        }

        return false;
    }
}