class Solution {
    private boolean isSame(int[] list1, int[] list2) {
        for (int i = 0; i < list1.length; i++) {
            if (list1[i] != list2[i]) {
                return false;
            }
        }

        return true;
    }

    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int[] list1 = new int[26];
        int[] list2 = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            list1[s1.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            list2[s2.charAt(i) - 'a']++;
        }

        int left = 0, right = s1.length() - 1;

        while (right < s2.length()) {
            if (isSame(list1, list2)) {
                return true;
            }

            list2[s2.charAt(left) - 'a']--;
            left++;
            right++;

            if (right == s2.length()) {
                break;
            }

            list2[s2.charAt(right) - 'a']++;
        }

        return false;
    }
}