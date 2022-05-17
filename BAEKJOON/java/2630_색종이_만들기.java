import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int n, white = 0, blue = 0;
    public static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        map = new int[n + 1][n + 2];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        check(1, 1, n);

        System.out.println(white);
        System.out.println(blue);
    }

    public static void check(int x, int y, int size) {
        if (isFilled(x, y, size)) {
            if (map[x][y] == 0) //하얀색
                white++;
            else
                blue++;
            return;
        } else {
            check(x, y, size / 2);
            check(x, y + (size / 2), size / 2);
            check(x + (size / 2), y, size / 2);
            check(x + (size / 2), y + (size / 2), size / 2);
        }
    }

    public static boolean isFilled(int x, int y, int size) {
        int paper = map[x][y];

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (map[i][j] != paper)
                    return false;
            }
        }

        return true;
    }
}