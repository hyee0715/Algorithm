class Solution {
    public long solution(int[] sequence) {
        long answer = 0;

        if (sequence.length == 1) {
            answer = Math.max(sequence[0] * -1, sequence[0]);
            return answer;
        }

        long[] list1 = new long[sequence.length];
        long[] list2 = new long[sequence.length];

        for (int i = 0; i < sequence.length; i++) {
            if (i % 2 != 0) {
                list1[i] = sequence[i] * -1;
                list2[i] = sequence[i];
            } else {
                list1[i] = sequence[i];
                list2[i] = sequence[i] * -1;
            }
        }

        long dp1 = list1[0];
        long max1 = -1;

        for (int i = 1; i < list1.length; i++) {
            dp1 = Math.max(dp1 + list1[i], list1[i]);

            max1 = Math.max(max1, dp1);
        }

        long dp2 = list2[0];
        long max2 = -1;

        for (int i = 1; i < list2.length; i++) {
            dp2 = Math.max(dp2 + list2[i], list2[i]);

            max2 = Math.max(max2, dp2);
        }

        answer = Math.max(max1, max2);

        return answer;
    }
}