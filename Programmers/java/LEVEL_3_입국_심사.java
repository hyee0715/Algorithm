class Solution {
    private long validate(long num, int[] times) {
        long cnt = 0;
        for (int i = 0; i < times.length; i++) {
            cnt += num / times[i];
        }

        return cnt;
    }

    public long solution(int n, int[] times) {
        long answer = 0;
        long left = 0, right = 0;

        for (int i = 0; i < times.length; i++) {
            right = Math.max(right, (long)times[i]);
        }

        right *= n;
        answer = right;

        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (validate(mid, times) >= n) {
                answer = Math.min(answer, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
}