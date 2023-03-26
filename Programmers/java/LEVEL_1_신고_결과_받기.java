import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String, Set<String>> userReportedList = new HashMap<>(); //해당 유저를 신고한 유저 목록
        Map<String, Set<String>> userReportingList = new HashMap<>(); //각 유저가 신고한 목록
        Set<String> reportList = new HashSet<>(); //k번 이상 신고되어 정지될 유저

        for (String rep : report) {
            String[] s = rep.split(" ");
            String userId = s[0];
            String reportedId = s[1];

            if (!userReportedList.containsKey(reportedId)) {
                userReportedList.put(reportedId, new HashSet<>());
            }

            userReportedList.get(reportedId).add(userId);

            if (!userReportingList.containsKey(userId)) {
                userReportingList.put(userId, new HashSet<>());
            }

            userReportingList.get(userId).add(reportedId);
        }

        for (String key : userReportedList.keySet()) {
            if (userReportedList.get(key).size() >= k) {
                reportList.add(key);
            }
        }

        int idx = 0;
        for (String name : id_list) {
            Set<String> reportSet = new HashSet<>(userReportingList.getOrDefault(name, new HashSet<>()));
            int cnt = 0;

            for (String rp : reportSet) {
                if (reportList.contains(rp)) {
                    cnt++;
                }
            }

            answer[idx] = cnt;
            idx++;
        }

        return answer;
    }
}