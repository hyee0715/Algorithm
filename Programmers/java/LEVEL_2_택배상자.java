import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        int idx = 0;
        Stack<Integer> stack = new Stack<>();

        for (int i = 1; i <= order.length; i++) {
            if (i != order[idx]) {
                if (stack.isEmpty() || stack.peek() != order[idx]) {
                    stack.push(i);
                    continue;
                }

                while (!stack.isEmpty() && stack.peek() == order[idx]) {
                    answer++;
                    idx++;
                    stack.pop();
                }
                continue;
            }

            answer++;
            idx++;

            while (!stack.isEmpty() && stack.peek() == order[idx]) {
                answer++;
                idx++;
                stack.pop();
            }
        }

        return answer;
    }
}