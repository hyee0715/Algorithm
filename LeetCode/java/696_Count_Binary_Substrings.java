import java.util.ArrayList;
import java.util.List;

class Solution {
    public int countBinarySubstrings(String s) {
        int answer = 0;
        List<Integer> nums = new ArrayList<>();

        int cnt = 1;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                cnt++;
                continue;
            }

            nums.add(cnt);
            cnt = 1;
        }

        nums.add(cnt);

        for (int i = 0; i < nums.size() - 1; i++) {
            answer += Math.min(nums.get(i), nums.get(i + 1));
        }

        return answer;
    }
}