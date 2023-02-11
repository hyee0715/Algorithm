import java.util.*;

class Solution {
    private boolean check(Map<String, Integer> wantMap, Map<String, Integer> discountMap) {
        for (String key : wantMap.keySet()) {
            if (!discountMap.containsKey(key) || discountMap.get(key) < wantMap.get(key)) {
                return false;
            }
        }

        return true;
    }

    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;

        Map<String, Integer> wantMap = new HashMap<>();
        Map<String, Integer> discountMap = new HashMap<>();

        for (int i = 0; i < want.length; i++) {
            wantMap.put(want[i], number[i]);
        }

        for (int i = 0; i < 10; i++) {
            discountMap.put(discount[i], discountMap.getOrDefault(discount[i], 0) + 1);
        }

        if (check(wantMap, discountMap)) {
            answer++;
        }

        int left = 0, right = 9;

        while (right < discount.length - 1) {
            discountMap.put(discount[left], discountMap.getOrDefault(discount[left], 0) - 1);
            left++;
            right++;
            discountMap.put(discount[right], discountMap.getOrDefault(discount[right], 0) + 1);

            if (check(wantMap, discountMap)) {
                answer++;
            }
        }

        return answer;
    }
}