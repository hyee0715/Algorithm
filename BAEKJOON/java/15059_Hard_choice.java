import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static List<Integer> food = new ArrayList<>();
    public static List<Integer> passenger = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st;

        for (int i = 0; i < 2; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 3; j++) {
                int n = Integer.parseInt(st.nextToken());

                if (i == 0) {
                    food.add(n);
                    continue;
                }

                if (i == 1) {
                    passenger.add(n);
                }
            }
        }
    }

    private static void solution() throws IOException {
        int answer = 0;

        for (int i = 0; i < 3; i++) {
            if (food.get(i) > passenger.get(i)) {
                continue;
            }

            answer += (passenger.get(i) - food.get(i));
        }

        bw.write(String.valueOf(answer));
    }
}