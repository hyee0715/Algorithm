class Solution {
    public boolean judgeCircle(String moves) {
        int rCnt = 0, lCnt = 0, uCnt = 0, dCnt = 0;

        for (int i = 0; i < moves.length(); i++) {
            if (moves.charAt(i) == 'U') {
                uCnt++;
            }
            else if (moves.charAt(i) == 'D') {
                dCnt++;
            }
            else if (moves.charAt(i) == 'R') {
                rCnt++;
            }
            else {
                lCnt++;
            }
        }

        if ((uCnt != dCnt) || (rCnt != lCnt)) {
            return false;
        }

        return true;
    }
}