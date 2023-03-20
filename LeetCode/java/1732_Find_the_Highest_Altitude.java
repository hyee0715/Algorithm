class Solution {
    public int largestAltitude(int[] gain) {
        int answer = 0;
        int sum = 0;

        for (int i = 0; i < gain.length; i++) {
            sum += gain[i];
            answer = Math.max(answer, sum);
        }

        return answer;
    }
}