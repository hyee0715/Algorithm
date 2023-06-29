class Solution {
    public int countSeniors(String[] details) {
        int answer = 0;

        for (String detail : details) {
            StringBuilder age = new StringBuilder();

            age.append(detail.charAt(11));
            age.append(detail.charAt(12));

            if (Integer.parseInt(age.toString()) > 60) {
                answer++;
            }
        }

        return answer;
    }
}