import java.io.*;
import java.util.*;

public class Main {
    public static int n, l, r, x, answer = 0;
    public static List<Integer> nums = new ArrayList<>();
    public static List<Integer> v = new ArrayList<>();
    public static boolean[] visit;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            nums.add(Integer.parseInt(st.nextToken()));
        }
    }

    private static void dfs(int idx, int cnt, int target) {
        if (cnt == target) {
            List<Integer> temp = new ArrayList<>();

            for (int i = 0; i < v.size(); i++) {
                temp.add(v.get(i));
            }

            Collections.sort(temp);

            if (temp.get(temp.size() - 1) - temp.get(0) < x) {
                return;
            }

            int sum = 0;

            for (int i = 0; i < temp.size(); i++) {
                sum += temp.get(i);
            }

            if (sum >= l && sum <= r) {
                answer++;
            }

            return;
        } else {
            for (int i = idx; i < n; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                v.add(nums.get(i));
                dfs(i, cnt + 1, target);
                visit[i] = false;
                v.remove(v.size() - 1);
            }
        }
    }

    private static void solution() throws IOException {
        visit = new boolean[n];
        Arrays.fill(visit, false);

        for (int i = 2; i <= n; i++) {
            dfs(0, 0, i);
        }

        bw.write(String.valueOf(answer));
    }
}