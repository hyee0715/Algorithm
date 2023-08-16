class Solution {
    public String finalString(String s) {
        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'i') {
                answer.reverse();
            } else {
                answer.append(s.charAt(i));
            }
        }

        return answer.toString();
    }
}