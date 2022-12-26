import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static String original, matching;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int cnt = 1;

        while (true) {
            original = br.readLine();
            matching = br.readLine();

            if (original.equals("END") && matching.equals("END"))
                break;

            bw.write("Case " + cnt + ": ");

            cnt++;

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        if (original.length() != matching.length()) {
            bw.write("different\n");

            return;
        }

        Map<Character, Integer> map = new HashMap<>();

        char[] originals = original.toCharArray();
        for (char c : originals) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        char[] matchings = matching.toCharArray();
        for (char c : matchings) {
            map.put(c, map.getOrDefault(c, 0) - 1);
        }

        for (char key : map.keySet()) {
            if (map.get(key) != 0) {
                bw.write("different\n");

                return;
            }
        }

        bw.write("same\n");
    }
}