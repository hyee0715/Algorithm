import java.util.Stack;

class Solution {
    public String reverseParentheses(String s) {
        StringBuilder answer = new StringBuilder();;
        Stack<Character> stack = new Stack<>();

        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    temp.append(stack.pop());
                }
                stack.pop();

                for (int j = 0; j < temp.length(); j++) {
                    stack.push(temp.charAt(j));
                }
                temp.setLength(0);
            } else {
                stack.push(s.charAt(i));
            }
        }

        while (!stack.isEmpty()) {
            answer.append(stack.pop());
        }

        answer.reverse();

        return answer.toString();
    }
}