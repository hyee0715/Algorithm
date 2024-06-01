class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int sSize = s.length();
        int tSize = t.length();

        if ((s.equals(t)) || (sSize - tSize) > 1 || ((tSize - sSize) > 1)) {
            return false;
        }

        boolean flag = false;
        //사이즈가 같으면 교체만 가능
        if (s.length() == t.length()) {
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != t.charAt(i)) {
                    if (!flag) {
                        flag = true;
                    } else {
                        return false;
                    }
                }
            }
        } else if (s.length() > t.length()) {
            if (t.length() == 0) {
                return true;
            }

            //s사이즈 > t사이즈면 지우기
            int tIdx = 0;
            for (int sIdx = 0; sIdx < s.length(); sIdx++) {
                if (tIdx == t.length() && sIdx == s.length() - 1) {
                    return true;
                }

                if (s.charAt(sIdx) == t.charAt(tIdx)) {
                    tIdx++;
                } else {
                    if (!flag) {
                        flag = true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            if (s.length() == 0) {
                return true;
            }

            //s사이즈 < t사이즈면 삽입하기
            int sIdx = 0;
            for (int tIdx = 0; tIdx < t.length(); tIdx++) {
                if (sIdx == s.length() && tIdx == t.length() - 1) {
                    return true;
                }

                if (s.charAt(sIdx) == t.charAt(tIdx)) {
                    sIdx++;
                } else {
                    if (!flag) {
                        flag = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}