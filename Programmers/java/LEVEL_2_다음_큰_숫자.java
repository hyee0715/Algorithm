class Solution {
    public int solution(int n) {
        int answer = 0;

        String s = getBinary(n);

        int num = n + 1;
        while (true) {
            String nextNum = getBinary(num);

            if (isSameOneCount(s, nextNum)) {
                answer = num;
                break;
            }

            num++;
        }

        return answer;
    }

    private String getBinary(int n) {
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            sb.append((char)((n % 2) + '0'));
            n = n / 2;
        }

        return sb.reverse().toString();
    }

    private boolean isSameOneCount(String orgNum, String nextNum) {
        int orgNumCnt = 0;
        int nextNumCnt = 0;

        for (int i = 0; i < orgNum.length(); i++) {
            if (orgNum.charAt(i) == '1') {
                orgNumCnt++;
            }
        }

        for (int i = 0; i < nextNum.length(); i++) {
            if (nextNum.charAt(i) == '1') {
                nextNumCnt++;
            }
        }

        if (orgNumCnt == nextNumCnt) {
            return true;
        }

        return false;
    }
}