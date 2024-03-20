import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n;
    public static Map<Integer, HashSet<Integer>> info = new HashMap<>();
    public static int[][] board;
    public static List<Integer> seq = new ArrayList<>();

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        board = new int[n][n];

        for (int i = 0; i < n * n; i++) {
            String[] str = br.readLine().split(" ");

            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            int c = Integer.parseInt(str[2]);
            int d = Integer.parseInt(str[3]);
            int e = Integer.parseInt(str[4]);

            if (!info.containsKey(a)) {
                info.put(a, new HashSet<>());
            }

            info.get(a).add(b);
            info.get(a).add(c);
            info.get(a).add(d);
            info.get(a).add(e);

            seq.add(a);
        }
    }
    private static void solution() throws IOException {
        int answer = 0;

        for (int student : seq) {
            int[] sp = search(student);

            board[sp[0]][sp[1]] = student;
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                answer += getSatisfaction(i, j);
            }
        }

        bw.write(String.valueOf(answer));
    }

    private static int[] search(int studentNum) {
        List<int[]> spaces = new ArrayList<>();  //인접한 칸의 좋아하는 학생 수, 비어있는 칸, 행, 열

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 0) {
                    int[] spaceInfo = check(i, j, studentNum);

                    spaces.add(new int[]{spaceInfo[0], spaceInfo[1], i, j});
                }
            }
        }

        Collections.sort(spaces, (x, y) -> {
            if (x[0] < y[0]) {
                return 1;
            }

            if (x[0] > y[0]) {
                return -1;
            }

            if (x[1] < y[1]) {
                return 1;
            }

            if (x[1] > y[1]) {
                return -1;
            }

            if (x[2] < y[2]) {
                return -1;
            }

            if (x[2] > y[2]) {
                return 1;
            }

            if (x[3] < y[3]) {
                return -1;
            }

            if (x[3] > y[3]) {
                return 1;
            }

            return 0;
        });

        return new int[]{spaces.get(0)[2], spaces.get(0)[3]};
    }

    private static int[] check(int x, int y, int studentNum) {
        int fav = 0;
        int empty = 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                continue;
            }

            if (board[nx][ny] == 0) {
                empty++;
            } else if (info.get(studentNum).contains(board[nx][ny])) {
                fav++;
            }
        }

        return new int[]{fav, empty};
    }

    static int getSatisfaction(int x, int y) {
        int satisfaction = 0;
        int studentNum = board[x][y];
        Set<Integer> fav = info.get(studentNum);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                continue;
            }

            if (fav.contains(board[nx][ny])) {
                satisfaction++;
            }
        }

        if (satisfaction == 2) {
            return 10;
        } else if (satisfaction == 3) {
            return 100;
        } else if (satisfaction == 4) {
            return 1000;
        }

        return satisfaction;
    }
}