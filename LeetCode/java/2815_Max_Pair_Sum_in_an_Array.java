import java.util.*;

class Solution {
    public int maxSum(int[] nums) {
        int answer = -1;

        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int n : nums) {
            String s = String.valueOf(n);

            int maxDigit = 0;
            for (int i = 0; i < s.length(); i++) {
                if (maxDigit < (s.charAt(i) - '0')) {
                    maxDigit = s.charAt(i) - '0';
                }
            }

            if (!map.containsKey(maxDigit)) {
                map.put(maxDigit, new ArrayList<>());
            }

            map.get(maxDigit).add(n);
        }

        for (int key : map.keySet()) {
            if (map.get(key).size() == 1) {
                continue;
            }

            List<Integer> list = map.get(key);

            Collections.sort(list);

            answer = Math.max(answer, list.get(list.size() - 1) + list.get(list.size() - 2));
        }

        return answer;
    }
}