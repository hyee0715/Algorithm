class Solution {
    public int countSubstrings(String s) {
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String temp = s.substring(i, j + 1);
                StringBuilder temp_rev = new StringBuilder(temp);
                temp_rev.reverse();

                if (temp_rev.toString().equals(temp)) {
                    answer++;
                }
            }
        }

        return answer;
    }
}