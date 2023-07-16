class Solution {
    public int divisorSubstrings(int num, int k) {
        int answer = 0;

        String s = String.valueOf(num);
        StringBuilder temp = new StringBuilder();

        for (int i = 0; i < k; i++) {
            temp.append(s.charAt(i));
        }

        int n = Integer.parseInt(temp.toString());

        if (n != 0) {
            if (num % n == 0) {
                answer++;
            }
        }

        for (int i = k; i < s.length(); i++) {
            temp.deleteCharAt(0);
            temp.append(s.charAt(i));

            n = Integer.parseInt(temp.toString());

            if (n == 0) {
                continue;
            }

            if (num % n == 0) {
                answer++;
            }
        }

        return answer;
    }
}