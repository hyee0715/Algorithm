import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int n, h, answer = 0;
    public static List<Integer> list = new ArrayList<>();

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

        for (int i = 0; i < n; i++) {
            h = Integer.parseInt(br.readLine());
            list.add(h);
        }
    }

    private static void solution() throws IOException {
       int max_num = -1;

       for (int i = list.size() - 1; i >= 0; i--) {
           if (list.get(i) > max_num) {
               max_num = Math.max(max_num, list.get(i));
               answer++;
           }
       }

       bw.write(String.valueOf(answer));
    }
}