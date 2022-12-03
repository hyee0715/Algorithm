class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int answer = 0;

        for (String operation : operations) {
            if (operation.charAt(0) == '+' || operation.charAt(operation.length() - 1) == '+') {
                answer++;
                continue;
            }

            if (operation.charAt(0) == '-' || operation.charAt(operation.length() - 1) == '-') {
                answer--;
            }
        }

        return answer;
    }
}