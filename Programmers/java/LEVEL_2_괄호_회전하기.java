import java.util.*;

class Solution {
    private boolean check(Queue<Character> q) {
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>(q);

        while (!queue.isEmpty()) {
            char c = queue.poll();

            if (c == '[' || c == '(' || c == '{') {
                stack.push(c);
                continue;
            }

            if (!stack.isEmpty()) {
                if ((c == ']' && stack.peek() == '[') || (c == ')' && stack.peek() == '(') || (c == '}' && stack.peek() == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (!stack.isEmpty()) {
            return false;
        }

        return true;
    }

    public int solution(String s) {
        int answer = 0;

        Queue<Character> q = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            q.add(s.charAt(i));
        }

        if (check(q)) {
            answer++;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            char c = q.poll();
            q.add(c);

            if (check(q)) {
                answer++;
            }
        }

        return answer;
    }
}