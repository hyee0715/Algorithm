class Solution {
    public int strStr(String haystack, String needle) {
        int answer = -1;

        int idx = -1;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                idx = i;

                boolean flag = true;
                for (int j = 0; j < needle.length(); j++) {
                    if (i + needle.length() > haystack.length()) {
                        flag = false;
                        break;
                    }

                    if (haystack.charAt(i + j) != needle.charAt(j)) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    answer = i;
                    break;
                }
            }
        }

        return answer;
    }
}