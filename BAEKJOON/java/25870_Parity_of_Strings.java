import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
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

        List<Integer> temp = new ArrayList<>();

        for (char key : map.keySet()) {
            temp.add(map.get(key));
        }

        for (int i = 0; i < temp.size(); i++) {
            temp.set(i, temp.get(i) % 2);
        }

        Map<Integer, Integer> map2 = new HashMap<>();

        for (int i = 0; i < temp.size(); i++) {
            map2.put(temp.get(i), map2.getOrDefault(temp.get(i), 0) + 1);
        }

        if (map2.size() == 1) {
            for (int key : map2.keySet()) {
                if (key == 0) {
                    bw.write(String.valueOf(0));
                    return;
                }

                bw.write(String.valueOf(1));
                return;
            }
        }

        bw.write(String.valueOf(2));
    }
}