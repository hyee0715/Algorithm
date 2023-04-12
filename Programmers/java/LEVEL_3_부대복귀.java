import java.util.*;

class Solution {
    private void bfs(Map<Integer, List<Integer>> map, boolean[] visit, int destination, Set<Integer> sources, int[] tempAnswer) {
        Queue<int[]> q = new LinkedList<>(); //현재 위치, 현재까지의 이동 거리
        q.add(new int[] {destination, 0});
        visit[destination] = true;

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int cur = current[0];
            int cnt = current[1];

            if (sources.contains(cur)) {
                tempAnswer[cur] = cnt;
                sources.remove(cur);
            }

            List<Integer> area = map.get(cur);
            for (int i = 0; i < area.size(); i++) {
                if (visit[area.get(i)] == false) {
                    q.add(new int[] {area.get(i), cnt + 1});
                    visit[area.get(i)] = true;
                }
            }
        }
    }

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        Map<Integer, List<Integer>> map = new HashMap<>();
        boolean[] visit = new boolean[n + 1];
        Set<Integer> sourcesSet = new HashSet<>();
        int[] tempAnswer = new int[n + 1];

        Arrays.fill(tempAnswer, -1);

        for (int source : sources) {
            sourcesSet.add(source);
        }


        for (int[] road : roads) {
            if (!map.containsKey(road[0])) {
                map.put(road[0], new ArrayList<>());
            }
            map.get(road[0]).add(road[1]);

            if (!map.containsKey(road[1])) {
                map.put(road[1], new ArrayList<>());
            }
            map.get(road[1]).add(road[0]);
        }

        bfs(map, visit, destination, sourcesSet, tempAnswer);

        int idx = 0;
        for (int i = 0; i < sources.length; i++) {
            answer[idx++] = tempAnswer[sources[i]];
        }

        return answer;
    }
}