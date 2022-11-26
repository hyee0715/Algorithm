import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static List<Integer> score = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        score.clear();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 5; i++) {
            int a = Integer.parseInt(st.nextToken());
            score.add(a);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(score);

        if (score.get(score.size() - 2) - score.get(1) >= 4) {
            bw.write("KIN\n");
            return;
        }

        int sum = 0;
        for (int i = 1; i < score.size() - 1; i++) {
            sum += score.get(i);
        }

        bw.write(sum + "\n");
    }
}