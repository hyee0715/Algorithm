import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n, answer = 0;
    public static List<Integer> students = new ArrayList<>();
    public static List<Integer> apples = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int student = Integer.parseInt(st.nextToken());
            students.add(student);

            int apple = Integer.parseInt(st.nextToken());
            apples.add(apple);
        }
    }

    private static void solution() throws IOException {
        for (int i = 0; i < n; i++) {
            answer += (apples.get(i) % students.get(i));
        }

        bw.write(String.valueOf(answer));
    }
}