class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";

        int cards1Idx = 0;
        int cards2Idx = 0;
        int goalIdx = 0;

        while (true) {
            if (cards1Idx == cards1.length || cards2Idx == cards2.length || goalIdx == goal.length) {
                break;
            }

            if (cards1[cards1Idx].equals(goal[goalIdx])) {
                cards1Idx++;
                goalIdx++;

                continue;
            }

            if (cards2[cards2Idx].equals(goal[goalIdx])) {
                cards2Idx++;
                goalIdx++;
            }
        }

        while (cards1Idx < cards1.length) {
            if (goalIdx == goal.length) {
                break;
            }

            if (cards1[cards1Idx].equals(goal[goalIdx])) {
                cards1Idx++;
                goalIdx++;
            } else {
                break;
            }
        }

        while (cards2Idx < cards2.length) {
            if (goalIdx == goal.length) {
                break;
            }

            if (cards2[cards2Idx].equals(goal[goalIdx])) {
                cards2Idx++;
                goalIdx++;
            } else {
                break;
            }
        }

        if (goalIdx != goal.length) {
            answer = "No";
        }

        return answer;
    }
}