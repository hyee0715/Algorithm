import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static String s;
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
        s = br.readLine();
    }

    private static void solution() throws IOException {
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        if (isOdd(map)) {
            bw.write("1");
            return;
        }

        if (isEven(map)) {
            bw.write("0");
            return;
        }

        bw.write("0/1");
    }

    private static boolean isOdd(Map<Character, Integer> map) {
        for (Character key : map.keySet()) {
            if (map.get(key) % 2 == 0) {
                return false;
            }
        }

        return true;
    }

    private static boolean isEven(Map<Character, Integer> map) {
        for (Character key : map.keySet()) {
            if (map.get(key) % 2 != 0) {
                return false;
            }
        }

        return true;
    }
}