import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static List<Integer> slimes = new ArrayList<>();
    public static int answer = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            slimes.add(a);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(slimes);

        while (slimes.size() > 1) {
            int a = slimes.remove(slimes.size() - 1);
            int b = slimes.remove(slimes.size() - 1);

            answer += (a * b);
            slimes.add(a + b);
        }

        bw.write(String.valueOf(answer));
    }
}