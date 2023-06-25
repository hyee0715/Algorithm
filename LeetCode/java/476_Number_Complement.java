class Solution {
    public int findComplement(int num) {
        int answer = 0;
        StringBuilder numBinary = new StringBuilder();

        while (num > 0) {
            if (num % 2 == 0) {
                numBinary.append('0');
            } else {
                numBinary.append('1');
            }
            num /= 2;
        }

        numBinary.reverse();

        for (int i = 0; i < numBinary.length(); i++) {
            if (numBinary.charAt(i) == '0') {
                numBinary.setCharAt(i, '1');
            } else {
                numBinary.setCharAt(i, '0');
            }
        }

        int cnt = 0;
        for (int i = numBinary.length() - 1; i >= 0; i--) {
            answer += ((numBinary.charAt(i) - '0') * Math.pow(2, cnt));
            cnt++;
        }

        return answer;
    }
}