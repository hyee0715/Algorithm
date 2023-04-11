class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {-1, -1};
        int minLen = 1000001;

        int left = 0, right = 0;
        int sum = sequence[left];

        if (sum == k) {
            answer[0] = left;
            answer[1] = right;
            minLen = right - left + 1;
        }

        while (left < sequence.length && right < sequence.length) {
            if (sum == k) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    answer[0] = left;
                    answer[1] = right;
                }

                right++;

                if (right == sequence.length) {
                    break;
                }

                sum += sequence[right];
            }

            if (sum < k) {
                right++;

                if (right == sequence.length) {
                    break;
                }

                sum += sequence[right];
            }

            if (sum > k) {
                sum -= sequence[left];
                left++;
            }
        }

        return answer;
    }
}