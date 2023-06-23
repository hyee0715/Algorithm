class Solution {
    public boolean isFascinating(int n) {
        int nDouble = n * 2;
        int nTriple = n * 3;

        String s = String.valueOf(n) + String.valueOf(nDouble) + String.valueOf(nTriple);

        int[] list = new int[10];

        for (int i = 0; i < s.length(); i++) {
            list[s.charAt(i) - '0']++;
        }

        for (int i = 1; i <= 9; i++) {
            if (list[i] != 1) {
                return false;
            }
        }

        return true;
    }
}