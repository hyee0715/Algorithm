import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int m, n, h, cnt = 0;
    public static int[][][] map;
    public static boolean[][][] visit;

    static Queue<Pair> q = new LinkedList<>();

    public static int[] dx = {0, 0, 1, -1, 0, 0};
    public static int[] dy = {1, -1, 0, 0, 0, 0};
    public static int[] dz = {0, 0, 0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        map = new int[n][m][h];
        visit = new boolean[n][m][h];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < m; k++) {
                    map[j][k][i] = Integer.parseInt(st.nextToken());
                    if (map[j][k][i] == 1) {
                        Pair pair = new Pair(j, k, i);
                        q.add(pair);
                        visit[j][k][i] = true;
                    }
                }
            }
        }

        if (isAllRipe()) { //저장될 때 부터 모든 토마토가 익어있으면 0을 출력
            System.out.println("0");
            return;
        }

        bfs();

        if (!isAllRipe()) //모두 익어있는지 다시 한 번 확인한 후, 모든 토마토가 익지 못했으면 -1 출력
            System.out.println("-1");
        else //모두 익었다면 최소 일 수 출력
            System.out.println(cnt);
    }

    public static void bfs() {
        while (!q.isEmpty()) {
            int qSize = q.size();

            for (int k = 0; k < qSize; k++) {
                int x = q.peek().x;
                int y = q.peek().y;
                int z = q.peek().z;
                q.poll();

                for (int i = 0; i < 6; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nz = z + dz[i];

                    if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;

                    if (map[nx][ny][nz] == 0 && visit[nx][ny][nz] == false) {
                        Pair pair = new Pair(nx, ny, nz);
                        q.add(pair);
                        map[nx][ny][nz] = 1;
                        visit[nx][ny][nz] = true;
                    }
                }
            }

            cnt++;

            if (isAllRipe()) {
                return;
            }
        }
    }

    public static boolean isAllRipe() {//모두 익었다면 true, 익지 않은 것이 있다면 false 반환
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (map[j][k][i] == 0)
                        return false;
                }
            }
        }

        return true;
    }
}

class Pair {
    int x;
    int y;
    int z;

    public Pair(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }
}