import java.io.*;
import java.util.*;

public class Main {
    public static List<Integer> science = new ArrayList<>();
    public static List<Integer> social = new ArrayList<>();
    public static int n, sum = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        for (int i = 0; i < 4; i++) {
            n = Integer.parseInt(br.readLine());
            science.add(n);
        }

        for (int i = 0; i < 2; i++) {
            n = Integer.parseInt(br.readLine());
            social.add(n);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(science, Collections.reverseOrder());
        Collections.sort(social, Collections.reverseOrder());

        for (int i = 0; i < 3; i++) {
            sum += science.get(i);
        }

        sum += social.get(0);

        bw.write(String.valueOf(sum));
    }
}