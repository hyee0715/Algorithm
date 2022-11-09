class Solution {
    public int findKthPositive(int[] arr, int k) {
        int cnt = 1;
        int answer = 0;

        for (int i = 0; i < arr.length; i++) {
            if (cnt != arr[i]) {
                k--;
                i--;
            }

            if (k == 0) {
                break;
            }

            if (i != arr.length - 1) {
                cnt++;
            }
        }

        while (k > 0) {
            cnt++;
            k--;
        }

        return cnt;
    }
}