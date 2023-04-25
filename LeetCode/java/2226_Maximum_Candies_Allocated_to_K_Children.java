import java.util.Arrays;

class Solution {
    private boolean check(int[] candies, long k, int mid) {
        long cnt = 0;
        for (int candy : candies) {
            if (mid == 0) {
                break;
            }

            cnt += (candy / mid);
        }

        if (cnt >= k) {
            return true;
        }

        return false;
    }

    public int maximumCandies(int[] candies, long k) {
        int answer = 0;

        if (candies.length == 1) {
            return candies[0] / (int)k;
        }

        Arrays.sort(candies);

        int left = 0;
        int right = candies[candies.length - 1];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(candies, k, mid)) {
                answer = Math.max(answer, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (answer == 0) {
            long total = 0;

            for (int n : candies) {
                total += n;
            }

            if (total >= k) {
                answer = 1;
            }
        }

        return answer;
    }
}