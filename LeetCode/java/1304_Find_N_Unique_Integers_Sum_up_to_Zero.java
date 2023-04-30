import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] sumZero(int n) {
        List<Integer> odd = new ArrayList<>(Arrays.asList(0));
        List<Integer> even = new ArrayList<>(Arrays.asList(-1, 1));
        int[] answer;

        if (n == 1) {
            answer = new int[odd.size()];
            answer[0] = odd.get(0);
            return answer;
        } else if (n == 2) {
            answer = new int[even.size()];
            answer[0] = even.get(0);
            answer[1] = even.get(1);
            return answer;
        }

        for (int i = 3; i <= n; i++) {
            if (i % 2 == 0) {
                even.add(-1 * (i / 2));
                even.add(i / 2);
            } else {
                odd = new ArrayList<>(even);
                odd.add(0);
            }
        }

        if (n % 2 == 0) {
            answer = new int[even.size()];
            for (int i = 0; i < even.size(); i++) {
                answer[i] = even.get(i);
            }
        } else {
            answer = new int[odd.size()];
            for (int i = 0; i < odd.size(); i++) {
                answer[i] = odd.get(i);
            }
        }

        return answer;
    }
}