import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int a, b, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if (a == 0 && b == 0 && c == 0)
                break;

            if (a > b && a > c) {
                if (a * a == (b * b + c * c))
                    System.out.println("right");
                else
                    System.out.println("wrong");
            }
            else if (b > a && b > c) {
                if (b * b == (a * a + c * c))
                    System.out.println("right");
                else
                    System.out.println("wrong");
            }
            else if (c > a && c > b) {
                if (c * c == (a * a + b * b))
                    System.out.println("right");
                else
                    System.out.println("wrong");
            }
        }
    }
}
