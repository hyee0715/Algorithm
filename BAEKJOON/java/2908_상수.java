import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static int a, b;
    public static String s1, s2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        s1 = st.nextToken();
        s2 = st.nextToken();

        StringBuffer sb = new StringBuffer(s1);
        s1 = sb.reverse().toString();

        sb = new StringBuffer(s2);
        s2 = sb.reverse().toString();

        a = Integer.parseInt(s1);
        b = Integer.parseInt(s2);

        if (a > b)
            System.out.println(a);
        else
            System.out.println(b);
    }
}