import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int r, c, t;
    public static int[][] map;
    public static int[] dx = new int[]{0, 0, 1, -1};
    public static int[] dy = new int[]{1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        String[] s = br.readLine().split(" ");
        r = Integer.parseInt(s[0]);
        c = Integer.parseInt(s[1]);
        t = Integer.parseInt(s[2]);

        map = new int[r][c];

        for (int i = 0; i < r; i++) {
            s = br.readLine().split(" ");

            for (int j = 0; j < c; j++) {
                map[i][j] = Integer.parseInt(s[j]);
            }
        }
    }

    private static void solution() throws IOException {
        int[][] cleanerLocation = findCleanerLocation();
        Queue<int[]> q = new LinkedList<>(); //확산 시킬 x, y 좌표, 먼지 양

        for (int cnt = 0; cnt < t; cnt++) {
            for (int i = 0; i < map.length; i++) {
                for (int j = 0; j < map[i].length; j++) {
                    if (map[i][j] != -1) { //해당 칸이 청소기 위치가 아니라면
                        addDustToQueueToSpread(i, j, q);
                    }
                }
            }

            spreadDust(q);

            startCleanerCounterclockwiseDirection(cleanerLocation[0]); //반시계 방향
            startCleanerClockwiseDirection(cleanerLocation[1]); //시계 방향
        }

        int answer = getAnswer();
        bw.write(String.valueOf(answer));
    }

    private static void addDustToQueueToSpread(int x, int y, Queue<int[]> q) {
        int dust = map[x][y];
        int diffusedDust = dust / 5;

        int areaCount = 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= map.length || ny >= map[0].length || map[nx][ny] == -1) {
                continue;
            }

            areaCount++;
            q.add(new int[]{nx, ny, diffusedDust});
        }

        int remainDust = dust - (diffusedDust * areaCount);
        map[x][y] = remainDust;
    }

    private static int[][] findCleanerLocation() {
        int[] a = new int[]{-1, -1};
        int[] b = new int[]{-1, -1};

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                if (map[i][j] == -1) {
                    if (a[0] == -1) {
                        a = new int[]{i, j};
                    } else {
                        b = new int[]{i, j};
                    }
                }
            }
        }

        return new int[][]{a, b};
    }

    private static void spreadDust(Queue<int[]> q) {
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int dust = cur[2];

            map[x][y] += dust;
        }
    }

    private static void startCleanerCounterclockwiseDirection(int[] cleanerLocation) {
        int x = cleanerLocation[0];
        int y = cleanerLocation[1];

        List<Integer> list = new ArrayList<>();

        for (int i = y; i < map[0].length; i++) {
            list.add(map[x][i]);

            if (i == y) {
                list.add(0);
            }
        }

        for (int i = x - 1; i >= 0; i--) {
            list.add(map[i][map[0].length - 1]);
        }

        for (int i = map[0].length - 2; i > 0; i--) {
            list.add(map[0][i]);
        }

        for (int i = 0; i < x; i++) {
            list.add(map[i][0]);
        }

        for (int i = 0; i < y; i++) {
            list.add(map[x][i]);
        }

        list.remove(list.size() - 1);

        int idx = 0;
        for (int i = y; i < map[0].length - 1; i++) {
            map[x][i] = list.get(idx++);
        }

        for (int i = x; i > 0; i--) {
            map[i][map[0].length - 1] = list.get(idx++);
        }

        for (int i = map[0].length - 1; i > 0; i--) {
            map[0][i] = list.get(idx++);
        }

        for (int i = 0; i < x; i++) {
            map[i][0] = list.get(idx++);
        }

        for (int i = 0; i < y; i++) {
            map[x][i] = list.get(idx++);
        }
    }

    private static void startCleanerClockwiseDirection(int[] cleanerLocation) {
        int x = cleanerLocation[0];
        int y = cleanerLocation[1];

        List<Integer> list = new ArrayList<>();

        for (int i = y; i < map[0].length; i++) {
            list.add(map[x][i]);

            if (i == y) {
                list.add(0);
            }
        }

        for (int i = x + 1; i < map.length; i++) {
            list.add(map[i][map[0].length - 1]);
        }

        for (int i = map[0].length - 2; i > 0; i--) {
            list.add(map[map.length - 1][i]);
        }

        for (int i = map.length - 1; i > x; i--) {
            list.add(map[i][0]);
        }

        for (int i = 0; i < y; i++) {
            list.add(map[x][i]);
        }

        list.remove(list.size() - 1);

        int idx = 0;
        for (int i = y; i < map[0].length - 1; i++) {
            map[x][i] = list.get(idx++);
        }

        for (int i = x; i < map.length - 1; i++) {
            map[i][map[0].length - 1] = list.get(idx++);
        }

        for (int i = map[0].length - 1; i > 0; i--) {
            map[map.length - 1][i] = list.get(idx++);
        }

        for (int i = map.length - 1; i > x; i--) {
            map[i][0] = list.get(idx++);
        }

        for (int i = 0; i < y; i++) {
            map[x][i] = list.get(idx++);
        }
    }

    private static int getAnswer() {
        int sum = 0;

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (map[i][j] == -1) {
                    continue;
                }

                sum += map[i][j];
            }
        }

        return sum;
    }
}