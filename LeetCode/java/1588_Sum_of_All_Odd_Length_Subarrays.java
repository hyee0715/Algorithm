class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int answer = 0;

        for (int i = 1; i <= arr.length; i+= 2) {
            for (int j = 0; j <= arr.length - i; j++) {
                int sum = 0;

                for (int k = 0; k < i; k++) {
                    sum += arr[j + k];
                }

                answer += sum;
            }
        }

        return answer;
    }
}