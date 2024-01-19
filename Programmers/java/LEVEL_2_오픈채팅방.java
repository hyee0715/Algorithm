import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        List<String> tempAnswer = new ArrayList<>();

        Map<String, String> map = new HashMap<>(); //uid, 닉네임
        List<String[]> list = new ArrayList<>(); // {출입, uid};

        for (String rec : record) {
            String[] str = rec.split(" ");

            if (str[0].equals("Enter")) {
                map.put(str[1], str[2]);
                list.add(new String[]{str[0], str[1]});
            } else if (str[0].equals("Leave")) {
                list.add(new String[]{str[0], str[1]});
            } else {
                map.put(str[1], str[2]);
            }
        }

        for (String[] rec : list) {
            if (rec[0].equals("Enter")) {
                String nickName = map.get(rec[1]);
                String s = nickName + "님이 들어왔습니다.";
                tempAnswer.add(s);
            } else {
                String nickName = map.get(rec[1]);
                String s = nickName + "님이 나갔습니다.";
                tempAnswer.add(s);
            }
        }

        answer = new String[tempAnswer.size()];

        int idx = 0;
        for (String ans : tempAnswer) {
            answer[idx++] = ans;
        }

        return answer;
    }
}