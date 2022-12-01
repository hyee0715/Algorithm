import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static List<Person> list = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            String name = st.nextToken();
            int day = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int year = Integer.parseInt(st.nextToken());

            Person person = new Person(name, day, month, year);
            list.add(person);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(list);

        bw.write(list.get(list.size() - 1).name + "\n");
        bw.write(list.get(0).name);
    }
}

class Person implements Comparable<Person> {
    String name;
    int day;
    int month;
    int year;

    public Person(String name, int day, int month, int year) {
        this.name = name;
        this.day = day;
        this.month = month;
        this.year = year;
    }

    @Override
    public int compareTo(Person o) {
        if (this.year < o.year) {
            return -1;
        }

        if (this.year == o.year) {
            if (this.month < o.month) {
                return -1;
            }

            if (this.month == o.month) {
                if (this.day < o.day) {
                    return -1;
                }

                if (this.day == o.day) {
                    return this.name.compareTo(o.name);
                }
                return 1;
            }
            return 1;
        }
        return 1;
    }
}