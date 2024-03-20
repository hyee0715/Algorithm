import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int[] dx = {0, -1, 0, 1}; //동 북 서 남
    public static int[] dy = {1, 0, -1, 0};

    public static int n, m;
    public static int[][] board;
    public static Robot robot;
    public static int answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);

        str = br.readLine().split(" ");
        int a = Integer.parseInt(str[0]);
        int b = Integer.parseInt(str[1]);
        int c = Integer.parseInt(str[2]);

        c = changeDirection(c);

        robot = new Robot(a, b, c);

        board = new int[n][m];

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");

            for (int j = 0; j < m; j++) {
                int n = Integer.parseInt(str[j]);

                if (n == 1) {
                    n = 2;
                }

                board[i][j] = n;
            }
        }
    }
    private static void solution() throws IOException {
        //로봇 첫 칸 세팅
        settingRobot();

        while (true) {
            //현재 칸이 청소되지 않았으면 현재 칸 청소
            cleanCurrentSpace();

            if (checkNeighborSpace()) {
                //청소되지 않은 빈 칸이 있는 경우
                int x = robot.getX();
                int y = robot.getY();
                int dir = robot.getDir();

                for (int i = 1; i <= 4; i++) {
                    int ndir = (dir + i) % 4;
                    int nx = x + dx[ndir];
                    int ny = y + dy[ndir];

                    if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length || board[nx][ny] == 2) {
                        continue;
                    }

                    if (board[nx][ny] == 0) {
                        robot.setX(nx);
                        robot.setY(ny);
                        robot.setDir(ndir);
                        break;
                    }
                }
            } else {
                //청소되지 않은 빈 칸이 없는 경우
                int x = robot.getX();
                int y = robot.getY();
                int dir = robot.getDir();

                //후진하기
                int nx = x + dx[((dir + 2) % 4)];
                int ny = y + dy[((dir + 2) % 4)];

                if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length || board[nx][ny] == 2) {
                    break;
                }

                robot.setX(nx);
                robot.setY(ny);
            }
        }

        bw.write(String.valueOf(answer));
    }

    static boolean checkNeighborSpace() {
        //주변 4칸 중에 청소되지 않은 빈칸이 있으면 true 리턴, 없으면 false 리턴
        int x = robot.getX();
        int y = robot.getY();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length || board[nx][ny] == 2) {
                continue;
            }

            if (board[nx][ny] == 0) {
                return true;
            }
        }

        return false;
    }

    static void cleanCurrentSpace() {
        int x = robot.getX();
        int y = robot.getY();

        if (board[x][y] == 0) {
            board[x][y] = 1;
            answer++;
        }
    }

    static void settingRobot() {
        int x = robot.getX();
        int y = robot.getY();

        board[x][y] = 1;
        answer++;
    }

    private static int changeDirection(int dir) {
        if (dir == 0) {
            return 1;
        } else if (dir == 1) {
            return 0;
        } else if (dir == 2) {
            return 3;
        }
        return 2;
    }

    static class Robot {
        int x;
        int y;
        int dir;

        Robot() {

        }
        Robot(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getDir() {
            return dir;
        }

        public void setX(int x) {
            this.x = x;
        }

        public void setY(int y) {
            this.y = y;
        }

        public void setDir(int dir) {
            this.dir = dir;
        }
    }
}