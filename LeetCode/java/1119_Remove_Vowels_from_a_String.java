class Solution {
    public String removeVowels(String s) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'a' && s.charAt(i) != 'i' && s.charAt(i) != 'u' && s.charAt(i) != 'e' && s.charAt(i) != 'o') {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }
}