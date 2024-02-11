import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> basket = new Stack<>();
        Map<Integer, Stack<Integer>> map = new HashMap<>();

        settingMap(board, map);

        for (int move : moves) {
            Stack<Integer> st = map.get(move);

            if (!st.isEmpty()) {
                int doll = st.pop();

                if (!basket.isEmpty()) {
                    if (basket.peek() == doll) {
                        answer += 2;
                        basket.pop();
                    } else {
                        basket.push(doll);
                    }
                } else {
                    basket.push(doll);
                }
            }
        }

        return answer;
    }

    private void settingMap(int[][] board, Map<Integer, Stack<Integer>> map) {
        for (int i = board.length - 1; i >= 0; i--) {
            int[] b = board[i];

            for (int j = 0; j < b.length; j++) {
                if (!map.containsKey(j + 1)) {
                    map.put(j + 1, new Stack<Integer>());
                }

                if (b[j] == 0) {
                    continue;
                }

                map.get(j + 1).push(b[j]);
            }
        }
    }
}