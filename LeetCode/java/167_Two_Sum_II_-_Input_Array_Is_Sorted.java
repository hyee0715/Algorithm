class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] answer = new int[2];
        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                answer[0] = left + 1;
                answer[1] = right + 1;

                break;
            }

            if (numbers[left] + numbers[right] < target) {
                left++;
                continue;
            }

            right--;
        }

        return answer;
    }
}