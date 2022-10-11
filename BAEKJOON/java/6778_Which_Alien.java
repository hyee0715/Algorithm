import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    public static int antenna, eyes;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        antenna = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        eyes = Integer.parseInt(st.nextToken());

        if (antenna >= 3 && eyes <= 4) {
            System.out.println("TroyMartian");
        }

        if (antenna <= 6 && eyes >= 2) {
            System.out.println("VladSaturnian");
        }

        if (antenna <= 2 && eyes <= 3) {
            System.out.println("GraemeMercurian");
        }
    }
}