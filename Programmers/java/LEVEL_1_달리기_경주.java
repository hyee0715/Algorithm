import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < players.length; i++) {
            map.put(players[i], i);
        }

        for (String name : callings) {
            int playerIdx = map.get(name);

            swap(playerIdx, playerIdx - 1, players, map);
        }

        answer = players;
        return answer;
    }

    private void swap(int idx1, int idx2, String[] players, Map<String, Integer> map) {
        String a = players[idx1];
        String b = players[idx2];

        players[idx2] = a;
        players[idx1] = b;

        map.put(a, idx2);
        map.put(b, idx1);
    }
}