import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static char digit;
    public static Map<Character, Integer> map = new HashMap<>();

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
        digit = st.nextToken().charAt(0);
    }

    private static void solution() throws IOException {
        for (int i = 1; i <= n; i++) {
            String s = String.valueOf(i);

            for (int j = 0; j < s.length(); j++) {
                map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);
            }
        }

        bw.write(String.valueOf(map.get(digit)));
    }
}