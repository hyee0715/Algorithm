import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int k;
    public static List<Character> op = new ArrayList<>();
    public static int[] nums = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    public static List<String> results = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        k = Integer.parseInt(br.readLine());

        String[] str = br.readLine().split(" ");

        for (String s : str) {
            op.add(s.charAt(0));
        }
    }
    private static void solution() throws IOException {
        boolean[] visit = new boolean[nums.length];
        List<Integer> list = new ArrayList<>();

        dfs(0, list, visit);

        Collections.sort(results);
        bw.write(results.get(results.size() - 1) + "\n" + results.get(0));
    }

    private static void dfs(int cnt, List<Integer> list, boolean[] visit) {
        if (cnt == k + 1) {
            if (check(list)) {
                StringBuilder sb = new StringBuilder();

                for (int i = 0; i < list.size(); i++) {
                    sb.append((char)(list.get(i) + '0'));
                }

                results.add(sb.toString());
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                list.add(nums[i]);
                dfs(cnt + 1, list, visit);
                list.remove(list.size() - 1);
                visit[i] = false;
            }
        }
    }

    private static boolean check(List<Integer> list) {
        for (int i = 0; i < op.size(); i++) {
            if (op.get(i) == '<') {
                if (list.get(i) > list.get(i + 1)) {
                    return false;
                }
            } else {
                if (list.get(i) < list.get(i + 1)) {
                    return false;
                }
            }
        }

        return true;
    }
}