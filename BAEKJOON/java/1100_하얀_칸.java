import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int answer = 0;
    public static String s;
    public static String[][] map = new String[8][8];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

       for (int i = 0; i < 8; i++) {
           String[] str = br.readLine().split("");
           for (int j = 0; j < 8; j++) {
               map[i][j] = str[j];
           }
       }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
                    if (map[i][j].equals("F"))
                        answer++;
                }
            }
        }

        System.out.println(answer);
    }
}