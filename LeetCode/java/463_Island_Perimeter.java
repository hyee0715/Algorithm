class Solution {
    public int islandPerimeter(int[][] grid) {
        int answer = 0;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {

                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || ny < 0 || nx >= grid.length || ny >= grid[0].length) {
                            answer++;
                            continue;
                        }

                        if (grid[nx][ny] == 0) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
}