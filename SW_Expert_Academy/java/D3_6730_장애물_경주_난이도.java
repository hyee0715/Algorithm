import java.io.*;
import java.util.*;

class Solution {
    static int n;
    static List<Integer> blocks;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 1; i <= tc; i++) {
            initialize();
            input();

            bw.write("#" + i + " ");

            solution();

            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() {
        blocks = new ArrayList<>();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());

            blocks.add(a);
        }
    }

    private static void solution() throws IOException {
        int up = 0, down = 0;

        for (int i = 0; i < blocks.size() - 1; i++) {
            if (blocks.get(i) < blocks.get(i + 1)) {
                up = Math.max(up, blocks.get(i + 1) - blocks.get(i));
            } else {
                down = Math.max(down, blocks.get(i) - blocks.get(i + 1));
            }
        }

        bw.write(up + " " + down);
    }
}