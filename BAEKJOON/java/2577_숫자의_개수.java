import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int a, b, c;
    public static int[] num = new int[10];
    public static long result;
    public static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
        c = Integer.parseInt(br.readLine());

        Arrays.fill(num, 0);

        result = a * b * c;

        s = Long.toString(result);

        for (int i = 0; i < s.length(); i++) {
            num[s.charAt(i) - '0']++;
        }

        for (int i = 0; i < 10; i++) {
            System.out.println(num[i]);
        }
    }
}