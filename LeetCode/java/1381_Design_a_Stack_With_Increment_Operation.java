import java.util.Stack;

class CustomStack {
    Stack<Integer> stack;
    int max = 0;

    public CustomStack(int maxSize) {
        stack = new Stack<>();
        max = maxSize;
    }

    public void push(int x) {
        if (stack.size() < max) {
            stack.push(x);
        }
    }

    public int pop() {
        if (!stack.empty()) {
            return stack.pop();
        } else {
            return -1;
        }
    }

    public void increment(int k, int val) {
        int[] arr = new int[stack.size()];
        int idx = stack.size() - 1;

        while (!stack.empty()) {
            arr[idx--] = stack.pop();
        }

        for (int i = 0; i < k; i++) {
            if (i == arr.length) {
                break;
            }

            arr[i] = arr[i] + val;
        }

        for (int i = 0; i < arr.length; i++) {
            stack.push(arr[i]);
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */