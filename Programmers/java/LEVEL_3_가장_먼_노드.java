import java.util.*;

class Solution {
    private int bfs(Map<Integer, List<Integer>> map, boolean[] visit, int x) {
        int maxNum = 0;
        int maxCnt = 0;

        Queue<int[]> q = new LinkedList<>(); //현재 노드, 지나온 간선 수
        visit[x] = true;
        q.add(new int[] {x, 0});

        while (!q.isEmpty()) {
            int[] node = q.poll();

            int cur = node[0];
            int cnt = node[1];

            if (maxNum < cnt) {
                maxNum = cnt;
                maxCnt = 1;
            } else {
                maxCnt++;
            }

            List<Integer> list = map.get(cur);

            for (int i = 0; i < list.size(); i++) {
                if (visit[list.get(i)] == false) {
                    q.add(new int[] {list.get(i), cnt + 1});
                    visit[list.get(i)] = true;
                }
            }
        }

        return maxCnt;
    }

    public int solution(int n, int[][] edge) {
        int answer = 0;
        Map<Integer, List<Integer>> map = new HashMap<>();
        boolean[] visit = new boolean[n + 1];

        for (int i = 0; i < edge.length; i++) {
            int x = edge[i][0];
            int y = edge[i][1];

            if (!map.containsKey(x)) {
                map.put(x, new ArrayList<>());
            }
            map.get(x).add(y);

            if (!map.containsKey(y)) {
                map.put(y, new ArrayList<>());
            }
            map.get(y).add(x);
        }

        answer = bfs(map, visit, 1);
        return answer;
    }
}