import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] answer = new int[arr.length];
        int[] copy_arr = new int[arr.length];
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < arr.length; i++) {
            copy_arr[i] = arr[i];
        }

        Arrays.sort(copy_arr);

        int rank = 1;

        for (int n : copy_arr) {
            if (map.containsKey(n)) {
                continue;
            }

            if (!map.containsKey(n)) {
                map.put(n, rank);
                rank++;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            answer[i] = map.get(arr[i]);
        }

        return answer;
    }
}