import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int numberOfBeams(String[] bank) {
        int answer = 0;
        List<Integer> nums = new ArrayList<>();

        for (int i = 0; i < bank.length; i++) {
            int cnt = 0;

            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i].charAt(j) == '1') {
                    cnt++;
                }
            }

            nums.add(cnt);
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < nums.size(); i++) {
            q.add(nums.get(i));
        }

        int prev = 0;
        while (!q.isEmpty()) {
            if (q.peek() != 0) {
                prev = q.poll();
                break;
            } else {
                q.poll();
            }
        }

        while (!q.isEmpty()) {
            if (q.peek() != 0) {
                answer += (prev * q.peek());
                prev = q.poll();
            } else {
                q.poll();
            }
        }

        return answer;
    }
}