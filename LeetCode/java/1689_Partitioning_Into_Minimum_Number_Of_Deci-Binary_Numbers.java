class Solution {
    public int minPartitions(String n) {
        int answer = 0;

        for (int i = 0; i < n.length(); i++) {
            if (n.charAt(i) - '0' > answer) {
                answer = n.charAt(i) - '0';
            }
        }

        return answer;
    }
}