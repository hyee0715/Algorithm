import java.io.IOException;
import java.util.*;

public class Main {
    public static int cnt;
    public static String s;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        while(true) {
            s = sc.nextLine();

            if (s.equals("#"))
                break;

            cnt = 0;

            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || s.charAt(i) == 'O' || s.charAt(i) == 'U') {
                    cnt++;
                }
            }

            System.out.println(cnt);
        }
    }
}