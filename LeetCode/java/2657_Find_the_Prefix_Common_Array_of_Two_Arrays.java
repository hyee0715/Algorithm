import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int[] answer = new int[A.length];

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < A.length; i++) {
            map.put(A[i], map.getOrDefault(A[i], 0) + 1);
            map.put(B[i], map.getOrDefault(B[i], 0) + 1);

            int cnt = 0;

            for (int key : map.keySet()) {
                if (map.get(key) > 1) {
                    cnt++;
                }
            }

            answer[i] = cnt;
        }

        return answer;
    }
}