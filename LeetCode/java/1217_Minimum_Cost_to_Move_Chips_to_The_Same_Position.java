import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minCostToMoveChips(int[] position) {
        if (position.length == 1) {
            return 0;
        }

        int answer = Integer.MAX_VALUE;
        Map<Integer, Integer> cntMap = new HashMap<>();

        for (int i = 0; i < position.length; i++) {
            cntMap.put(position[i], cntMap.getOrDefault(position[i], 0) + 1);
        }

        for (int i = 0; i < position.length; i++) {
            int moveCnt = 0;

            if (position[i] % 2 == 0) {
                for (Map.Entry<Integer, Integer> map : cntMap.entrySet()) {
                    if (map.getKey() == position[i]) {
                        continue;
                    }

                    if (map.getKey() % 2 != 0) {
                        moveCnt += map.getValue();
                    }
                }

                answer = Math.min(answer, moveCnt);
                continue;
            }

            for (Map.Entry<Integer, Integer> map : cntMap.entrySet()) {
                if (map.getKey() == position[i]) {
                    continue;
                }

                if (map.getKey() % 2 == 0) {
                    moveCnt += map.getValue();
                }
            }

            answer = Math.min(answer, moveCnt);
        }

        return answer;
    }
}