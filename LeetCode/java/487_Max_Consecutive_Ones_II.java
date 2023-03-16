class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int answer = 0;
        int left = 0, right = 0, zeroCnt = 0, sum = 0;

        if (nums[left] == 0) {
            zeroCnt++;
        }

        sum += nums[left];
        right++;

        while (right < nums.length) {
            if (nums[right] == 0 && zeroCnt == 1) {
                right--;

                answer = Math.max(answer, sum + 1);

                while (zeroCnt > 0) {
                    if (nums[left] == 0) {
                        zeroCnt--;
                        left++;
                    } else {
                        sum -= nums[left];
                        left++;
                    }
                }

                right++;
                continue;
            }

            if (nums[right] == 0 && zeroCnt == 0) {
                zeroCnt++;
            }

            sum += nums[right];

            if (right == nums.length - 1) {
                break;
            }

            right++;
        }

        if (zeroCnt == 0) {
            answer = Math.max(answer, sum);
        } else {
            answer = Math.max(answer, sum + 1);
        }

        return answer;
    }
}