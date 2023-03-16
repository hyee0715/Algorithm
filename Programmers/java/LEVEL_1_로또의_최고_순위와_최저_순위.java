import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        Set<Integer> set = new HashSet<>();

        for (int n : win_nums) {
            set.add(n);
        }

        int correctCnt = 0;
        int zeroCnt = 0;
        for (int i = 0; i < lottos.length; i++) {
            if (lottos[i] == 0) {
                zeroCnt++;

                continue;
            }

            if (set.contains(lottos[i])) {
                correctCnt++;
            }
        }

        //순위 세팅
        Map<Integer, Integer> map = new HashMap<>();

        for (int i =1; i <= 6; i++) {
            map.put(7 - i, i);
        }
        map.put(0, 6);

        answer[0] = map.get(correctCnt + zeroCnt); //최고 순위
        answer[1] = map.get(correctCnt); //최저 순위
        return answer;
    }
}