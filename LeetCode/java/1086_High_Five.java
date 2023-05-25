import java.util.*;

class Solution {
    public int[][] highFive(int[][] items) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int[] item : items) {
            if (!map.containsKey(item[0])) {
                map.put(item[0], new ArrayList<>());
            }

            map.get(item[0]).add(item[1]);
        }

        int[][] answer = new int[map.size()][2];
        int idx = 0;

        for (Map.Entry<Integer, List<Integer>> m : map.entrySet()) {
            List<Integer> list = m.getValue();

            Collections.sort(list, Collections.reverseOrder());

            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += list.get(i);
            }

            int avg = sum / 5;

            answer[idx][0] = m.getKey();
            answer[idx][1] = avg;
            idx++;
        }

        Arrays.sort(answer, (x, y) -> {
            if (x[0] < y[0]) {
                return -1;
            }

            if (x[0] > y[0]) {
                return 1;
            }

            return 0;
        });

        return answer;
    }
}