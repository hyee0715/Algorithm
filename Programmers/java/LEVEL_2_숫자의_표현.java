import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        List<Integer> sum = new ArrayList<>();
        sum.add(0);

        for (int i = 1; i <= n; i++) {
            sum.add(sum.get(i - 1) + i);
        }

        int left = 0, right = 0;
        while (left < sum.size() && right < sum.size()) {
            if (sum.get(right) - sum.get(left) == n) {
                answer++;
                right++;
                continue;
            }

            if (sum.get(right) - sum.get(left) < n) {
                right++;
                continue;
            }

            left++;
        }

        return answer;
    }
}