class Solution {
    public int bestClosingTime(String customers) {
        int answer = 100001;
        int minCost = 100001;

        int beforeY = 0;
        int beforeN = 0;
        int afterY = 0;
        int afterN = 0;

        for (int i = 0; i < customers.length(); i++) {
            if (customers.charAt(i) == 'Y') {
                afterY++;
            } else {
                afterN++;
            }
        }

        if (minCost > beforeN + afterY) {
            minCost = beforeN + afterY;
            answer = 0;
        }

        int idx = 0;
        while (idx < customers.length()) {
            if (customers.charAt(idx) == 'Y') {
                afterY--;
                beforeY++;
            } else {
                afterN--;
                beforeN++;
            }

            if (minCost > beforeN + afterY) {
                minCost = beforeN + afterY;
                answer = idx + 1;
            }

            idx++;
        }

        return answer;
    }
}