class Solution {
    public String replaceDigits(String s) {
        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                answer.append(s.charAt(i));
                continue;
            }

            int alphabet = s.charAt(i - 1) - 'a';
            int number = s.charAt(i) - '0';
            char c = (char)((alphabet + number) + 'a');

            answer.append(c);
        }

        return answer.toString();
    }
}