class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder answer = new StringBuilder();
        int open = 0,  close = 0;

        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                open++;
                temp.append(s.charAt(i));
            } else {
                close++;
                temp.append(s.charAt(i));
            }

            if (open == close) {
                if (open != 1 && close != 1) {
                    for (int j = 1; j < temp.length() - 1; j++) {
                        answer.append(temp.charAt(j));
                    }
                }

                temp = new StringBuilder();
                open = 0;
                close = 0;
            }
        }

        return answer.toString();
    }
}