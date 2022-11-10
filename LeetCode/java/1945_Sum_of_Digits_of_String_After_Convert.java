class Solution {
    public int getLucky(String s, int k) {
        int sum = 0;
        StringBuilder convert = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            int charToInt = (s.charAt(i) - 'a');
            String intToStr = String.valueOf(charToInt + 1);

            convert.append(intToStr);
        }

        while (k > 0) {
            sum = 0;

            for (int i = 0; i < convert.length(); i++) {
                sum += (convert.charAt(i) - '0');
            }

            String st = String.valueOf(sum);
            convert = new StringBuilder(st);

            k--;
        }

        return sum;
    }
}