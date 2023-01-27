import java.util.Stack;

class Solution {
    public String makeGood(String s) {
        if (s.length() == 1) {
            return s;
        }

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (stack.isEmpty()) {
                stack.push(s.charAt(i));
            } else {
                if (s.charAt(i) >= 65 && s.charAt(i) <= 90) {
                    if (stack.peek() == (s.charAt(i) + 32)) {
                        stack.pop();
                    } else {
                        stack.push(s.charAt(i));
                    }
                } else if (s.charAt(i) >= 97 && s.charAt(i) <= 122) {
                    if (stack.peek() == (s.charAt(i) - 32)) {
                        stack.pop();
                    } else {
                        stack.push(s.charAt(i));
                    }
                } else {
                    stack.push(s.charAt(i));
                }
            }
        }

        StringBuilder answer = new StringBuilder();
        while (!stack.isEmpty()) {
            answer.append(stack.pop());
        }

        answer.reverse();

        return answer.toString();
    }
}