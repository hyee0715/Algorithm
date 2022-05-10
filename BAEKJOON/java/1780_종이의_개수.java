import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[][] map = new int[2200][2200];
    public static int minusOneCnt = 0, zeroCnt = 0, oneCnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        check(1, 1, n);

        System.out.println(minusOneCnt);
        System.out.println(zeroCnt);
        System.out.println(oneCnt);
    }

    public static void check(int x, int y, int size) {
        if (all_same(x, y, size)) {
            if (map[x][y] == -1)
                minusOneCnt++;
            else if (map[x][y] == 0)
                zeroCnt++;
            else //map[x][y] == 1
                oneCnt++;
        }
        else {
            check(x, y, size / 3);
            check(x, y + size / 3, size / 3);
            check(x, y + 2 * (size / 3), size / 3);

            check(x + size / 3, y, size / 3);
            check(x + size / 3, y + size / 3, size / 3);
            check(x + size / 3, y + 2 * (size / 3), size / 3);

            check(x + 2 * (size / 3), y, size / 3);
            check(x + 2 * (size / 3), y + size / 3, size / 3);
            check(x + 2 * (size / 3), y + 2 * (size / 3), size / 3);
        }
    }

    public static boolean all_same(int x, int y, int size) {
        int num = map[x][y];

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (map[i][j] != num)
                    return false;
            }
        }

        return true;
    }
}

