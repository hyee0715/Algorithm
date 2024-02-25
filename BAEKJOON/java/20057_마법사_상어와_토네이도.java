import java.io.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n;
    public static int[][] map;
    public static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");

            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(str[j]);
            }
        }
    }

    private static void solution() throws IOException {
        int[] dx = new int[]{0, 1, 0, -1};
        int[] dy = new int[]{-1, 0, 1, 0};

        double[] rate = new double[]{0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01};

        int[] westDx = new int[]{0, 1, -1, 2, 1, -1, -2, 1, -1, 0};
        int[] westDy = new int[]{-2, -1, -1, 0, 0, 0, 0, 1, 1, -1};

        int[] eastDx = new int[]{0, -1, 1, -2, -1, 1, 2, -1, 1, 0};
        int[] eastDy = new int[]{2, 1, 1, 0, 0, 0, 0, -1, -1, 1};

        int[] northDx = new int[]{-2, -1, -1, 0, 0, 0, 0, 1, 1, -1};
        int[] northDy = new int[]{0, -1, 1, -2, -1, 1, 2, -1, 1, 0};

        int[] southDx = new int[]{2, 1, 1, 0, 0, 0, 0, -1, -1, 1};
        int[] southDy = new int[]{0, 1, -1, 2, 1, -1, -2, 1, -1, 0};

        int curDx = n / 2, curDy = n / 2;

        int cnt = 1; //움직일 칸 개수 (1부터 1씩 늘어남)
        int dirCnt = 0; //2방향씩 진행 (서남 - 동북)
        int dir = 0; //진행 방향

        while (true) {
            if (curDx == 0 && curDy == 0) {
                break;
            }

            for (int i = 0; i < cnt; i++) {
                curDx = curDx + dx[dir];
                curDy = curDy + dy[dir];
                int amount = map[curDx][curDy];
                int amountCopy = amount;

                if (dir == 0) {
                    calculate(curDx, curDy, westDx, westDy, amount, amountCopy, rate);
                } else if (dir == 1) {
                    calculate(curDx, curDy, southDx, southDy, amount, amountCopy, rate);
                } else if (dir == 2) {
                    calculate(curDx, curDy, eastDx, eastDy, amount, amountCopy, rate);
                } else {
                    calculate(curDx, curDy, northDx, northDy, amount, amountCopy, rate);
                }

                if (curDx == 0 && curDy == 0) {
                    break;
                }
            }

            dir++;
            dir = dir % 4;

            dirCnt++;

            if (dirCnt == 2) {
                dirCnt = 0;

                cnt++;
            }
        }

        bw.write(String.valueOf(answer));
    }

    private static void calculate(int curDx, int curDy, int[] dx, int[] dy, int amount, int amountCopy, double[] rate) {
        for (int i = 0; i < 9; i++) {
            int nx = curDx + dx[i];
            int ny = curDy + dy[i];
            int nextAmount = (int)(amount * rate[i]);
            amountCopy -= nextAmount;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                answer += nextAmount;
            } else {
                map[nx][ny] += nextAmount;
            }
        }

        int nx = curDx + dx[9];
        int ny = curDy + dy[9];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
            answer += amountCopy;
        } else {
            map[nx][ny] += amountCopy;
        }
        map[curDx][curDy] = 0;
    }
}