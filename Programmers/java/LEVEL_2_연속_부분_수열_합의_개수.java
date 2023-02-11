import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        Map<Integer, Set<Integer>> map = new HashMap<>();
        Set<Integer> removeDup = new HashSet<>();

        for (int i = 0; i < elements.length; i++) {
            int sum = 0, cnt = 1;

            for (int j = i; j < elements.length + i; j++) {
                int idx = j;

                if (idx >= elements.length) {
                    idx = idx - elements.length;
                }

                sum += elements[idx];

                if (!map.containsKey(cnt)) {
                    map.put(cnt, new TreeSet<>());
                }
                map.get(cnt).add(sum);
                cnt++;
            }
        }

        for (int key : map.keySet()) {
            for (int n : map.get(key)) {
                removeDup.add(n);
            }
        }

        answer = removeDup.size();

        return answer;
    }
}