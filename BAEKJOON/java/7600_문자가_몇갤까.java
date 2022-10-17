import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s;
        int[] alphabet = new int[26];
        int cnt;

        while (true) {
            cnt = 0;

            s = br.readLine();

            if (s.equals("#"))
                break;

            Arrays.fill(alphabet, 0);

            s = s.toLowerCase();

            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                    alphabet[s.charAt(i) - 'a']++;
                }
            }

            for (int i = 0; i < 26; i++) {
                if (alphabet[i] > 0) {
                    cnt++;
                }
            }

            bw.write(cnt + "\n");
        }

        bw.flush();
        bw.close();
    }
}