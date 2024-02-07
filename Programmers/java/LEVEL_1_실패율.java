import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = {};

        Map<Integer, Integer> allPlayersStage = new HashMap<>(); //스테이지 번호, 스테이지에 도달한 플레이어 수
        Map<Integer, Integer> notClearPlayersStage = new HashMap<>(); //스테이지 번호, 클리어 못한 플레이어 수
        Map<Integer, Double> failureRate = new HashMap<>(); //스테이지 번호, 실패율
        List<Integer> tempAns = new ArrayList<>();

        for (int stage : stages) {
            notClearPlayersStage.put(stage, notClearPlayersStage.getOrDefault(stage, 0) + 1);

            for (int i = 1; i <= stage; i++) {
                allPlayersStage.put(i, allPlayersStage.getOrDefault(i, 0) + 1);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!allPlayersStage.containsKey(i)) {
                allPlayersStage.put(i, 0);
            }
        }

        for (int key : allPlayersStage.keySet()) {
            if (!notClearPlayersStage.containsKey(key)) {
                failureRate.put(key, (double)0);

                continue;
            }

            double rate = getFailureRate(allPlayersStage.get(key), notClearPlayersStage.get(key));

            failureRate.put(key, rate);
        }

        for (int i = 1; i <= N; i++) {
            tempAns.add(i);
        }

        Collections.sort(tempAns, (x, y) -> {
            double xRate = failureRate.get(x);
            double yRate = failureRate.get(y);

            if (xRate < yRate) {
                return 1;
            }

            if (xRate > yRate) {
                return -1;
            }

            if (x < y) {
                return -1;
            }

            if (x > y) {
                return 1;
            }

            return 0;
        });

        answer = new int[tempAns.size()];

        for (int i = 0; i < tempAns.size(); i++) {
            answer[i] = tempAns.get(i);
        }

        return answer;
    }

    private double getFailureRate(int allPlayers, int notClearPlayers) {

        return (double)notClearPlayers / allPlayers;
    }
}