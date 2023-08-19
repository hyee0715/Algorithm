import java.util.Stack;

class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder answer = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            stack.push(s.charAt(i));

            if (stack.size() >= part.length() && stack.peek() == part.charAt(part.length() - 1)) {
                StringBuilder temp = new StringBuilder();

                for (int j = 0; j < part.length(); j++) {
                    temp.append(stack.pop());
                }

                temp.reverse();

                if (!isSame(temp.toString(), part)) {
                    for (int j = 0; j < temp.length(); j++) {
                        stack.push(temp.charAt(j));
                    }
                }
            }
        }

        while (!stack.isEmpty()) {
            answer.append(stack.pop());
        }

        answer.reverse();

        return answer.toString();
    }

    private boolean isSame(String s, String part) {
        if (s.equals(part)) {
            return true;
        }

        return false;
    }
}