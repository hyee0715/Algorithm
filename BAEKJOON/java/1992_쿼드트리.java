import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int n;
    public static String answer = "";
    public static String[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        map = new String[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            String[] str = br.readLine().split("");

            for (int j = 1; j <= n; j++) {
                map[i][j] = str[j - 1];
            }
        }

        check(1, 1, n);

        System.out.println(answer);
    }

    public static void check(int x, int y, int size) {
        if (is_filled(x, y, size)) {
            if (map[x][y].equals("0"))
                answer += '0';
            else
                answer += '1';

            return;
        }
        else {
            answer += "(";

            check(x, y, size / 2);
            check(x, y + (size / 2), size / 2);
            check(x + (size / 2), y, size / 2);
            check(x + (size / 2), y + (size / 2), size / 2);
        }

        answer += ")";
    }

    public static boolean is_filled(int x, int y, int size) {
        String color = map[x][y];

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (!map[i][j].equals(color))
                    return false;
            }
        }

        return true;
    }
}