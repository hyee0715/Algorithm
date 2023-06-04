import java.util.Stack;

class Solution {
    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (stack.isEmpty()) {
                stack.push(s.charAt(i));
                continue;
            }

            if (!stack.isEmpty() && ((stack.peek() == 'A' && s.charAt(i) == 'B') || (stack.peek() == 'C' && s.charAt(i) == 'D'))) {
                stack.pop();
                continue;
            }

            stack.push(s.charAt(i));
        }

        return stack.size();
    }
}