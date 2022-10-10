class Solution {
    public String interpret(String command) {
        StringBuilder answer = new StringBuilder();
        StringBuilder sb = new StringBuilder();
        boolean flag = false;

        for (int i = 0; i < command.length(); i++) {
            if (command.charAt(i) != '(' && command.charAt(i) != ')' && flag == false) {
                answer.append(command.charAt(i));
            }

            if (command.charAt(i) != '(' && command.charAt(i) != ')' && flag == true) {
                sb.append(command.charAt(i));
            }

            if (command.charAt(i) == '(') {
                flag = true;
                sb.setLength(0);
            } else if (command.charAt(i) == ')') {
                flag = false;

                if (sb.length() == 0) {
                    answer.append('o');
                } else {
                    answer.append(sb.toString());
                }
            }
        }

        return answer.toString();
    }
}