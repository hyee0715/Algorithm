import java.util.PriorityQueue;

class Solution {
    public int minCost(String colors, int[] neededTime) {
        int answer = 0, sameCnt = 0;
        PriorityQueue<Integer> lo = new PriorityQueue<>();

        for (int i = 0; i < colors.length() - 1; i++) {
            if (colors.charAt(i) != colors.charAt(i + 1)) {
                if (!lo.isEmpty()) {
                    while (sameCnt > 1) {
                        answer += lo.poll();

                        sameCnt--;
                    }
                }

                while (!lo.isEmpty()) {
                    lo.poll();
                }

                sameCnt = 0;

                continue;
            }

            if (lo.isEmpty()) {
                lo.add(neededTime[i]);
                sameCnt++;
            }

            lo.add(neededTime[i + 1]);
            sameCnt++;
        }

        if (!lo.isEmpty() && sameCnt > 0) {
            while (sameCnt > 1) {
                answer += lo.poll();
                sameCnt--;
            }
        }

        return answer;
    }
}