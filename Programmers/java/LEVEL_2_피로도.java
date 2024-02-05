import java.util.*;

class Solution {
    int maxNum = 0;

    public int solution(int k, int[][] dungeons) {
        int answer = 0;

        int[] arr = new int[dungeons.length];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }

        boolean[] visit = new boolean[arr.length];
        List<Integer> list = new ArrayList<>();

        dfs(0, arr, visit, list, dungeons, k);

        answer = maxNum;
        return answer;
    }

    private void dfs(int cnt, int[] arr, boolean[] visit, List<Integer> list, int[][] dungeons, int k) {
        if (cnt == arr.length) {
            findMaxNum(list, dungeons, k);

            return;
        } else {
            for (int i = 0; i < arr.length; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                list.add(arr[i]);
                dfs(cnt + 1, arr, visit, list, dungeons, k);
                list.remove(list.size() - 1);
                visit[i] = false;
            }
        }
    }

    private void findMaxNum(List<Integer> list, int[][] dungeons, int k) {
        int cnt = 0;
        int power = k;

        for (int idx : list) {
            int need = dungeons[idx][0];
            int minus = dungeons[idx][1];

            if (need > power) {
                break;
            } else {
                power -= minus;
                cnt++;
            }
        }

        maxNum = Math.max(maxNum, cnt);
    }
}