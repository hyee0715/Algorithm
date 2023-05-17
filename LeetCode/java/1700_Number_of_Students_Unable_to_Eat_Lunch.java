import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int answer = 0;
        Queue<Integer> studentsQ = new LinkedList<>();
        Queue<Integer> sandwichesQ = new LinkedList<>();

        for (int student : students) {
            studentsQ.add(student);
        }

        for (int sandwich : sandwiches) {
            sandwichesQ.add(sandwich);
        }

        int cnt = 0;
        while (!studentsQ.isEmpty() && !sandwichesQ.isEmpty()) {
            if (studentsQ.peek() == sandwichesQ.peek()) {
                studentsQ.poll();
                sandwichesQ.poll();
                cnt = 0;
            } else {
                int n = studentsQ.poll();
                studentsQ.add(n);
                cnt++;

                if (cnt > students.length) {
                    break;
                }
            }
        }

        if (!studentsQ.isEmpty()) {
            answer = studentsQ.size();
        }

        return answer;
    }
}