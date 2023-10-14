class Solution {
    public int[] solution(int n, long left, long right) {
        int[] answer = new int[(int)(right - left + 1)];

        int idx = 0;
        boolean start = false;

        for (int i = (int)(left / n); i <= (int)(right / n); i++) {
            for (int j = 0; j < n; j++) {
                if (start == false) {
                    start = true;
                    j = (int)(left % n);
                }

                if (idx == answer.length) {
                    break;
                }

                if (j <= i) {
                    answer[idx++] = i + 1;
                } else {
                    answer[idx++] = j + 1;
                }
            }
        }

        return answer;
    }
}