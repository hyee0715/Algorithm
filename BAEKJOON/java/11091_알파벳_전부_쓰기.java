import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static String s;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        int[] alphabet = new int[26];

        Arrays.fill(alphabet, 0);

        s = s.toLowerCase();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < 'a' || s.charAt(i) > 'z') {
                continue;
            }

            alphabet[s.charAt(i) - 'a']++;
        }

        String pangram = "pangram";
        StringBuilder missing = new StringBuilder("missing ");
        boolean isMissing = false;

        for (int i = 0; i < alphabet.length; i++) {
            if (alphabet[i] == 0) {
                isMissing = true;

                missing.append((char)(i + 'a'));
            }
        }

        if (isMissing) {
            bw.write(missing.toString() + "\n");
            return;
        }

        bw.write(pangram + "\n");
    }
}