import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean allZero(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }

        return true;
    }

    public boolean canThreePartsEqualSum(int[] arr) {
        if (allZero(arr)) {
            return true;
        }

        int totalSum = 0;

        for (int i = 0; i < arr.length; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 3 != 0) {
            return false;
        }

        int dividedSum = totalSum / 3;
        int cnt = 0, currentSum = 0;
        List<Integer> cumSum = new ArrayList<>();
        cumSum.add(arr[0]);

        for (int i = 1; i < arr.length; i++) {
            cumSum.add(arr[i] + cumSum.get(i - 1));
        }

        for (int i = 0; i < cumSum.size(); i++) {
            if (cnt == 0 && cumSum.get(i) == dividedSum) {
                cnt++;
                currentSum = cumSum.get(i);
                continue;
            }

            if (cumSum.get(i) - currentSum == dividedSum) {
                cnt++;
                currentSum = cumSum.get(i);
            }
        }

        if (cnt >= 3) {
            return true;
        }

        return false;
    }
}