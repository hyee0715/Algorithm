class Solution {
    public String reverseOnlyLetters(String s) {
        StringBuilder reverseStr = new StringBuilder();
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < s.length(); i++) {
            if ((s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')) {
                reverseStr.append(s.charAt(i));
            }
        }

        reverseStr.reverse();

        int rev_idx = 0;

        for (int i = 0; i < s.length(); i++) {
            if ((s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')) {
                sb.setCharAt(i, reverseStr.charAt(rev_idx));
                rev_idx++;
            }
        }

        return sb.toString();
    }
}