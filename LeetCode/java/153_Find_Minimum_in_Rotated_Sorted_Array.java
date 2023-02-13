class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int answer = 5001;

        if (nums[0] < nums[nums.length - 1]) {
            return nums[0];
        }

        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                answer = nums[mid];
            }

            if (mid < nums.length - 1 && nums[mid] > nums[mid + 1]) {
                answer = nums[mid + 1];
            }

            if (nums[0] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
}