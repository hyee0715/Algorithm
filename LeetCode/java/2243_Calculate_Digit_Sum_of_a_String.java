class Solution {
    public String digitSum(String s, int k) {
        while (s.length() > k) {
            StringBuilder temp = new StringBuilder();
            int cnt = 0;
            int num = 0;

            for (int i = 0; i < s.length(); i++) {
                num += s.charAt(i) - '0';
                cnt++;

                if (cnt == k) {
                    temp.append(String.valueOf(num));

                    num = 0;
                    cnt = 0;
                }
            }

            if (s.length() % k != 0) {
                temp.append(String.valueOf(num));
            }

            s = temp.toString();
        }

        return s;
    }
}