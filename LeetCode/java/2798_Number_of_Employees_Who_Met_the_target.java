class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int answer = 0;

        for (int n : hours) {
            if (n >= target) {
                answer++;
            }
        }

        return answer;
    }
}