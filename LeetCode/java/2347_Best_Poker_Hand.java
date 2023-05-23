import java.util.HashMap;
import java.util.Map;

class Solution {
    private boolean isFlush(Map<Character, Integer> map) {
        for (Map.Entry<Character, Integer> m : map.entrySet()) {
            if (m.getValue() == 5) {
                return true;
            }
        }

        return false;
    }

    private boolean isThree(Map<Integer, Integer> map) {
        for (Map.Entry<Integer, Integer> m : map.entrySet()) {
            if (m.getValue() >= 3) {
                return true;
            }
        }

        return false;
    }

    private boolean isPair(Map<Integer, Integer> map) {
        for (Map.Entry<Integer, Integer> m : map.entrySet()) {
            if (m.getValue() == 2) {
                return true;
            }
        }

        return false;
    }

    public String bestHand(int[] ranks, char[] suits) {
        String answer;

        Map<Integer, Integer> rMap = new HashMap<>();
        Map<Character, Integer> sMap = new HashMap<>();

        for (int rank : ranks) {
            rMap.put(rank, rMap.getOrDefault(rank, 0) + 1);
        }

        for (char suit : suits) {
            sMap.put(suit, sMap.getOrDefault(suit, 0) + 1);
        }

        if (isFlush(sMap)) {
            answer = "Flush";
        }
        else if (isThree(rMap)) {
            answer = "Three of a Kind";
        }
        else if (isPair(rMap)) {
            answer = "Pair";
        }
        else {
            answer = "High Card";
        }

        return answer;
    }
}