import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int maxCoins(int[] piles) {
        int answer = 0;

        List<Integer> list = new ArrayList<>();

        for (int n : piles) {
            list.add(n);
        }

        Collections.sort(list, Collections.reverseOrder());

        int left = 1, right = piles.length - 1;

        while (left < right) {
            answer += list.get(left);

            left += 2;
            right--;
        }

        return answer;
    }
}