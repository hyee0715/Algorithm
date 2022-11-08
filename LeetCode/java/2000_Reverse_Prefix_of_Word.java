class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder sb = new StringBuilder();
        int idx = -1;

        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                sb.append(word.charAt(i));
                idx = i + 1;
                break;
            }

            sb.append(word.charAt(i));
        }

        if (sb.toString().equals(word)) {
            if (idx == word.length()) {
                sb.reverse();
            }

            return sb.toString();
        }

        sb.reverse();

        if (idx < word.length()) {
            for (int i = idx; i < word.length(); i++) {
                sb.append(word.charAt(i));
            }
        }

        return sb.toString();
    }
}