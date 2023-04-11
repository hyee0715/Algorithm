import java.util.Stack;

class Solution {
    public String removeStars(String s) {
        StringBuilder answer = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '*') {
                stack.push(s.charAt(i));
                continue;
            }

            if (!stack.isEmpty()) {
                stack.pop();
            }
        }

        while (!stack.isEmpty()) {
            answer.append(stack.pop());
        }

        answer.reverse();
        return answer.toString();
    }
}