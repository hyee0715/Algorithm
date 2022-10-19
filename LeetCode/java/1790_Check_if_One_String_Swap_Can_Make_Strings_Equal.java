class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        char c1 = s1.charAt(0), c2 = s2.charAt(0);
        boolean flag = false, one_swap = false;

        if (s1.equals(s2))
            return true;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (one_swap)
                    return false;

                if (!flag) {
                    c1 = s1.charAt(i);
                    c2 = s2.charAt(i);
                    flag = true;
                } else {
                    if (s1.charAt(i) == c2 && s2.charAt(i) == c1) {
                        one_swap = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        if (one_swap)
            return true;

        return false;
    }
}