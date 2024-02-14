import java.util.*;

class Solution {
    List<Character> opList = new ArrayList<>();
    int count = 0;

    public int solution(int[] numbers, int target) {
        int answer = 0;

        char[] op = new char[]{'+', '-'};

        dfs(0, numbers, target, op);

        answer = count;
        return answer;
    }

    private int calculate(int[] numbers, int target) {
        int sum = 0;

        for (int i = 0; i < numbers.length; i++) {
            if (opList.get(i) == '+') {
                sum += numbers[i];
            } else {
                sum -= numbers[i];
            }
        }

        return sum;
    }

    private void dfs(int cnt, int[] numbers, int target, char[] op) {
        if (cnt == numbers.length) {
            int result = calculate(numbers, target);

            if (result == target) {
                count++;
            }
        } else {
            for (int i = 0; i < op.length; i++) {
                opList.add(op[i]);
                dfs(cnt + 1, numbers, target, op);
                opList.remove(opList.size() - 1);
            }
        }
    }
}