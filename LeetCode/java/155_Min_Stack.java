import java.util.Map;
import java.util.Stack;
import java.util.TreeMap;

class MinStack {
    Stack<Integer> stack;
    Map<Integer, Integer> map;

    public MinStack() {
        stack = new Stack<>();
        map = new TreeMap<>();
    }

    public void push(int val) {
        stack.push(val);
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    public void pop() {
        int n = stack.pop();
        map.put(n, map.getOrDefault(n, 0) - 1);
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        int n = 0;
        for (int key : map.keySet()) {
            if (map.get(key) > 0) {
                n = key;
                break;
            }
        }

        return n;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */