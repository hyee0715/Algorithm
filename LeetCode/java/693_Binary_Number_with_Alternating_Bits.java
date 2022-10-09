class Solution {
    public boolean hasAlternatingBits(int n) {
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            int a = (n % 2);
            sb.append(Integer.toString(a));

            n = n / 2;
        }

        StringBuffer sbf = new StringBuffer(sb.toString());
        String s = sbf.reverse().toString();

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == s.charAt(i))
                return false;
        }

        return true;
    }
}