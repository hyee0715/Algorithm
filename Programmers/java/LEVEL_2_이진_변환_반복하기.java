class Solution {
    int zeroCnt = 0;

    public int[] solution(String s) {
        int[] answer = new int[2];

        int cnt = 0;
        while (!s.equals("1")) {
            s = getBinary(s);
            cnt++;
        }

        answer[0] = cnt;
        answer[1] = zeroCnt;
        return answer;
    }

    private String getBinary(String n) {
        String removeZero = "";

        for (int i = 0; i < n.length(); i++) {
            if (n.charAt(i) != '0') {
                removeZero += String.valueOf(n.charAt(i));
            } else {
                zeroCnt++;
            }
        }

        int num = removeZero.length();

        String ret = "";
        while (num > 0) {
            ret += (char)((num % 2) + '0');
            num /= 2;
        }

        return ret;
    }
}