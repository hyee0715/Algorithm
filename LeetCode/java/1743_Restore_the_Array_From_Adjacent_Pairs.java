import java.util.*;

class Solution {
    private Map<Integer, List<Integer>> makeMap(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int[] pairs : adjacentPairs) {
            int a = pairs[0];
            int b = pairs[1];

            if (!map.containsKey(a)) {
                map.put(a, new ArrayList<>());
            }

            map.get(a).add(b);

            if (!map.containsKey(b)) {
                map.put(b, new ArrayList<>());
            }

            map.get(b).add(a);
        }

        return map;
    }

    private Map<Integer, Integer> makeCntMap(int[][] adjacentPairs) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int[] pairs : adjacentPairs) {
            int a = pairs[0];
            int b = pairs[1];

            map.put(a, map.getOrDefault(a, 0) + 1);
            map.put(b, map.getOrDefault(b, 0) + 1);
        }

        return map;
    }

    private Set<Integer> initializeVisit(int[][] adjacentPairs) {
        Set<Integer> visit = new HashSet<>();

        for (int[] pairs : adjacentPairs) {
            int a = pairs[0];
            int b = pairs[1];

            visit.add(a);
            visit.add(b);
        }

        return visit;
    }

    private int[] findOneCountNumber(Map<Integer, Integer> cntMap) {
        int[] pair = new int[] {Integer.MAX_VALUE, Integer.MAX_VALUE};

        for (Map.Entry<Integer, Integer> map : cntMap.entrySet()) {
            if (map.getValue() == 1) {
                if (pair[0] == Integer.MAX_VALUE) {
                    pair = new int[] {map.getKey(), Integer.MAX_VALUE};
                } else {
                    pair = new int[] {pair[0], map.getKey()};
                }
            }
        }

        return pair;
    }

    private int[] bfs(int start, Map<Integer, List<Integer>> map, Map<Integer, Integer> cntMap, Set<Integer> visit) {
        int[] answer = new int[map.size()];
        int idx = 0;

        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visit.remove(start);

        while (!q.isEmpty()) {
            int x = q.poll();

            answer[idx++] = x;

            if (map.containsKey(x)) {
                List<Integer> list = map.get(x);

                for (int i = 0; i < list.size(); i++) {
                    if (cntMap.get(list.get(i)) == 2 && visit.contains(list.get(i))) {
                        q.add(list.get(i));
                        visit.remove(list.get(i));
                    }
                }
            }
        }

        return answer;
    }

    public int[] restoreArray(int[][] adjacentPairs) {
        int[] answer;

        Map<Integer, List<Integer>> map = makeMap(adjacentPairs);
        Map<Integer, Integer> cntMap = makeCntMap(adjacentPairs);

        Set<Integer> visit = initializeVisit(adjacentPairs);

        int[] oneCnt = findOneCountNumber(cntMap);

        answer = bfs(oneCnt[0], map, cntMap, visit);
        answer[answer.length - 1] = oneCnt[1];

        return answer;
    }
}