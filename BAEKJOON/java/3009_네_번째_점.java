import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static Map<Integer, Integer> map1 = new HashMap<>();
    public static Map<Integer, Integer> map2 = new HashMap<>();
    public static int a, b, ans1, ans2;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        solution();

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        StringTokenizer st;

        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            map1.put(a, map1.getOrDefault(a, 0) + 1);
            map2.put(b, map2.getOrDefault(b, 0) + 1);
        }

        for (int key : map1.keySet()) {
            if (map1.get(key) != 2) {
                ans1 = key;
            }
        }

        for (int key : map2.keySet()) {
            if (map2.get(key) != 2) {
                ans2 = key;
            }
        }

        bw.write(ans1 + " " + ans2);
    }
}