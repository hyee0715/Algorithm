import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static List<Integer> list1= new ArrayList<>(),
                                list2 = new ArrayList<>();
    public static Integer n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 5; i++) {
            n = Integer.parseInt(st.nextToken());
            list1.add(n);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 5; i++) {
            n = Integer.parseInt(st.nextToken());
            list2.add(n);
        }

        for (int i = 0; i < 5; i++) {
            if (list1.get(i).equals(1)) {
                if (list2.get(i).equals(1)) {
                    System.out.println("N");
                    return;
                }
            }
            else {
                if (list2.get(i).equals(0)) {
                    System.out.println("N");
                    return;
                }
            }
        }

        System.out.println("Y");
    }
}