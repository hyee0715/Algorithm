import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n, k;
    public static List<Integer> nums = new ArrayList<>();

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
        k = Integer.parseInt(st.nextToken());
    }

    private static void solution() throws IOException {
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= k; i++) {
            sb.setLength(0);
            sb.append(n * i);
            sb.reverse();
            nums.add(Integer.parseInt(sb.toString()));
        }

        Collections.sort(nums);

        bw.write(String.valueOf(nums.get(nums.size() - 1)));
    }
}