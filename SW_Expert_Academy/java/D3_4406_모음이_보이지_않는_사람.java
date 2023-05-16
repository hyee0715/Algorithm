import java.io.*;
import java.util.HashSet;
import java.util.Set;

class Solution {
    static String s;
    static Set<Character> set = new HashSet<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 1; i <= tc; i++) {
            input();

            bw.write("#" + i + " ");

            solution();

            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');

        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (!set.contains(s.charAt(i))) {
                answer.append(s.charAt(i));
            }
        }

        bw.write(answer.toString());
    }
}