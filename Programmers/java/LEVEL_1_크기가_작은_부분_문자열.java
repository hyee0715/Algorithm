class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        long pNum = Long.parseLong(p);

        int left = 0, right = p.length() - 1;

        StringBuilder s = new StringBuilder();
        for (int i = left; i <= right; i++) {
            s.append(t.charAt(i));
        }

        while (right < t.length()) {
            long num = Long.parseLong(s.toString());

            if (num <= pNum) {
                answer++;
            }

            left++;
            right++;

            if (right == t.length()) {
                break;
            }

            s.deleteCharAt(0);
            s.append(t.charAt(right));
        }

        return answer;
    }
}