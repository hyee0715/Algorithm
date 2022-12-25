class Solution {
    public String[] divideString(String s, int k, char fill) {
        int size = s.length() % k == 0 ? s.length() / k : s.length() / k + 1;
        String[] answer = new String[size];

        int idx = 0;
        int cnt = 0;
        StringBuilder temp = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (cnt == k) {
                cnt = 0;
                answer[idx++] = temp.toString();
                temp.setLength(0);
            }

            temp.append(s.charAt(i));
            cnt++;
        }

        if (temp.length() != 0) {
            while (temp.length() < k) {
                temp.append(fill);
            }

            answer[idx] = temp.toString();
        }

        return answer;
    }
}