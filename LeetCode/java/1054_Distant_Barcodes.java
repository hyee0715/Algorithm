import java.util.*;

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int[] answer = new int[barcodes.length];
        Map<Integer, Integer> map = new HashMap<>();

        for (int n : barcodes) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        List<int[]> list = new ArrayList<>();

        for (int key : map.keySet()) {
            list.add(new int[]{map.get(key), key});
        }

        Collections.sort(list, (x, y) -> {
            if (x[0] < y[0]) {
                return 1;
            }

            if (x[0] > y[0]) {
                return -1;
            }

            return 0;
        });

        int idx = 0;

        for (int i = 0; i < list.size(); i++) {
            int[] n = list.get(i);

            for (int j = 0; j < n[0]; j++) {
                answer[idx] = n[1];

                if (idx == answer.length - 2 || idx == answer.length - 1) {
                    idx = 1;
                } else {
                    idx += 2;
                }
            }
        }

        return answer;
    }
}