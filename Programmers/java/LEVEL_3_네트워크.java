class Solution {
    private void dfs(int[][] computers, boolean[] visit, int x) {
        visit[x] = true;

        for (int i = 0; i < computers[x].length; i++) {
            if (i == x) {
                continue;
            }

            if (computers[x][i] == 1 && visit[i] == false) {
                dfs(computers, visit, i);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visit = new boolean[computers.length];

        for (int i = 0; i < computers.length; i++) {
            if (visit[i] == false) {
                answer++;
                dfs(computers, visit, i);
            }
        }

        return answer;
    }
}