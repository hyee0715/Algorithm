import java.util.Stack;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<int[]> stack = new Stack<>();

        for (int i = 0; i < temperatures.length; i++) {
            if (stack.isEmpty() || stack.peek()[0] > temperatures[i]) {
                stack.push(new int[]{temperatures[i], i});
                continue;
            }

            while (!stack.isEmpty() && stack.peek()[0] < temperatures[i]) {
                int[] p = stack.pop();

                answer[p[1]] = i - p[1];
            }

            stack.push(new int[]{temperatures[i], i});
        }

        while (!stack.isEmpty()) {
            int[] p = stack.pop();

            answer[p[1]] = 0;
        }

        return answer;
    }
}