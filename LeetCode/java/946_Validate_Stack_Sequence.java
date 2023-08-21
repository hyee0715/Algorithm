import java.util.Stack;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int popIdx = 0;
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < pushed.length; i++) {
            while (!stack.isEmpty() && stack.peek() == popped[popIdx]) {
                stack.pop();
                popIdx++;
            }

            stack.push(pushed[i]);
        }

        while (!stack.isEmpty() && stack.peek() == popped[popIdx]) {
            stack.pop();
            popIdx++;
        }

        if (stack.isEmpty()) {
            return true;
        }

        return false;
    }
}