import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n, m, k;
    public static int[][] map;
    public static int[] dx = new int[]{0, 1, 0, -1};
    public static int[] dy = new int[]{1, 0, -1, 0}; //동남서북

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        k = Integer.parseInt(s[2]);

        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            s = br.readLine().split(" ");

            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(s[j]);
            }
        }
    }

    private static void solution() throws IOException {
        int answer = 0;

        int curDir = 0; //초기 방향 동쪽
        int x = 0;
        int y = 0;

        int[][] dice = settingInitialDice();

        for (int cnt = 0; cnt < k; cnt++) {
            int nx = x + dx[curDir];
            int ny = y + dy[curDir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                //이동할 칸이 범위 밖이면
                //반대 방향으로 이동
                curDir = (curDir + 2) % 4;

                nx = x + dx[curDir];
                ny = y + dy[curDir];
            }

            moveDice(dice, curDir);

            int score = map[nx][ny];

            int availbleMovingCnt = bfs(nx, ny, map[nx][ny]);
            score *= availbleMovingCnt;

            answer += score;

            //다음 이동방향 결정
            int curMap = map[nx][ny]; //현재 칸 정수 값
            int curDice = dice[3][1]; //현재 주사위 아랫면

            if (curDice > curMap) {
                //90도 시계 방향
                curDir++;
                curDir %= 4;
            }
            else if (curDice < curMap) {
                //90도 반시계 방향
                curDir--;

                if (curDir < 0) {
                    curDir = 3;
                }
            }

            x = nx;
            y = ny;
        }

        bw.write(String.valueOf(answer));
    }

    private static int[][] settingInitialDice() {
        int[][] dice = new int[4][3];

        dice[0][1] = 2;
        dice[1][0] = 4;
        dice[1][1] = 1;
        dice[1][2] = 3;
        dice[2][1] = 5;
        dice[3][1] = 6;

        return dice;
    }

    private static void moveDice(int[][] dice, int direction) {
        if (direction == 0) { //동쪽
            int temp = dice[3][1];
            dice[3][1] = dice[1][2];
            dice[1][2] = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = temp;
        }
        else if (direction == 1) { //남쪽
            int temp = dice[3][1];
            dice[3][1] = dice[2][1];
            dice[2][1] = dice[1][1];
            dice[1][1] = dice[0][1];
            dice[0][1] = temp;
        }
        else if (direction == 2) { //서쪽
            int temp = dice[3][1];
            dice[3][1] = dice[1][0];
            dice[1][0] = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = temp;
        }
        else { //북쪽
            int temp = dice[3][1];
            dice[3][1] = dice[0][1];
            dice[0][1] = dice[1][1];
            dice[1][1] = dice[2][1];
            dice[2][1] = temp;
        }
    }

    private static int bfs(int a, int b, int num) {
        boolean[][] visit = new boolean[map.length][map[0].length];

        Queue<int[]> q = new LinkedList<>();

        int cnt = 0; //(a,b)로부터 같은 num을 가지고 있는 칸 개수

        q.add(new int[]{a, b});
        visit[a][b] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            cnt++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (map[nx][ny] == num && visit[nx][ny] == false) {
                    q.add(new int[]{nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }

        return cnt;
    }
}