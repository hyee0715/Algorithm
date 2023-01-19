import java.util.Stack;

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < num.length(); i++) {
            while (!stack.isEmpty() && k > 0 && num.charAt(i) - '0' < stack.peek()) {
                stack.pop();
                k--;
                continue;
            }

            stack.push(num.charAt(i) - '0');
        }

        while (k > 0) {
            stack.pop();
            k--;
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append((char)(stack.pop() + '0'));
        }

        sb.reverse();

        for (int i = 0; i < sb.length(); i++) {
            if (sb.toString().charAt(0) == '0') {
                if (i != 0) {
                    break;
                }

                sb.deleteCharAt(0);
                i--;
            }
        }

        if (sb.toString().isEmpty()) {
            return "0";
        }

        return sb.toString();
    }
}