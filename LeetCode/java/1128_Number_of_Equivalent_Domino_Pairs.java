import java.util.Arrays;

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int answer = 0;
        for (int i = 0; i < dominoes.length; i++) {
            Arrays.sort(dominoes[i]);
        }

        Arrays.sort(dominoes, (x, y) -> {
            if (x[0] < y[0]) {
                return -1;
            }

            if (x[0] > y[0]) {
                return 1;
            }

            if (x[1] < y[1]) {
                return -1;
            }

            if (x[1] > y[1]) {
                return 1;
            }

            return 0;
        });

        int cnt = 0;
        for (int i = 0; i < dominoes.length - 1; i++) {
            if (dominoes[i][0] == dominoes[i + 1][0] && dominoes[i][1] == dominoes[i + 1][1]) {
                if (cnt == 0) {
                    cnt++;
                }

                cnt++;
            } else {
                answer += (cnt * (cnt - 1)) / 2;
                cnt = 0;
            }
        }

        answer += (cnt * (cnt - 1)) / 2;

        return answer;
    }
}