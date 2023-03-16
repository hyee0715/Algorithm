import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] answer = new int[length];

        List<Integer> cal = new ArrayList<>();
        int[] cnt = new int[length + 1];

        for (int i = 0; i < updates.length; i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int num = updates[i][2];

            cnt[start] += num;
            cnt[end + 1] += (num * -1);
        }

        cal.add(cnt[0]);
        for (int i = 1; i < cnt.length; i++) {
            cal.add(cal.get(i - 1) + cnt[i]);
        }

        for (int i = 0; i < length; i++) {
            answer[i] = cal.get(i);
        }

        return answer;
    }
}