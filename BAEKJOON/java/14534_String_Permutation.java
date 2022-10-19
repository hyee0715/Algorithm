import java.io.*;
import java.util.*;

public class Main {
    public static String s;
    public static List<Character> list = new ArrayList<>();
    public static boolean[] visit = new boolean[5];

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            initialize();
            input();

            bw.write("Case # " + (i + 1) + ":\n");
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() {
        list.clear();
        Arrays.fill(visit, false);
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        dfs(0);
    }

    private static void dfs(int cnt) throws IOException {
        if (cnt == s.length()) {
            for (int i = 0; i < list.size(); i++) {
                bw.write(list.get(i));
            }
            bw.write("\n");
        } else {
            for (int i = 0; i < s.length(); i++) {
                if (visit[i]) continue;
                visit[i] = true;
                list.add(s.charAt(i));
                dfs(cnt + 1);
                list.remove(list.size() - 1);
                visit[i] = false;
            }
        }
    }
}