class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder answer = new StringBuilder();
        int check = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '(' && s.charAt(i) != ')') {
                answer.append(s.charAt(i));
                continue;
            }

            if (s.charAt(i) == '(') {
                check++;
                answer.append(s.charAt(i));
                continue;
            }

            if (check > 0) { //s.charAt(i) == ')''
                answer.append(s.charAt(i));
                check--;
            }
        }

        int idx = answer.length() - 1;

        while (check > 0) {
            if (idx < 0) {
                break;
            }

            if (answer.charAt(idx) == '(') {
                answer.deleteCharAt(idx);
                check--;
            }

            idx--;
        }

        return answer.toString();
    }
}