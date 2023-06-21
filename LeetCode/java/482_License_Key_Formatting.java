import java.util.Stack;

class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder answer = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        s = s.toUpperCase();

        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '-') {
                continue;
            }

            stack.push(s.charAt(i));
            cnt++;

            if (i != 0 && cnt == k) {
                cnt = 0;
                stack.push('-');
            }
        }

        if (!stack.isEmpty() && stack.peek() == '-') {
            stack.pop();
        }

        while (!stack.isEmpty()) {
            answer.append(stack.pop());
        }

        return answer.toString();
    }
}