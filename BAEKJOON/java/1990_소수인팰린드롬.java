import java.io.*;
import java.util.*;

public class Main {
    public static int a, b;

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

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
    }

    private static boolean isPalindrome(int n) {
        String s = String.valueOf(n);
        StringBuilder rev_s = new StringBuilder(s);
        rev_s.reverse();

        if (s.equals(rev_s.toString()))
            return true;

        return false;
    }

    private static boolean isPrime(int n) {
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    private static void solution() throws IOException {
        for (int i = a; i <= 10000000; i++) {
            if (i > b)
                break;

            if (!isPalindrome(i))
                continue;

            if (isPrime(i)) {
                bw.write(i + "\n");
            }
        }

        bw.write(String.valueOf(-1));
    }
}