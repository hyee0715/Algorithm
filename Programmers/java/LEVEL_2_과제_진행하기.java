import java.util.*;

class Solution {
    private int changeTime(String s) {
        int ret = 0;
        StringBuilder time = new StringBuilder();
        time.append(s.charAt(0));
        time.append(s.charAt(1));

        ret += (Integer.parseInt(time.toString()) * 60);

        time.setLength(0);
        time.append(s.charAt(3));
        time.append(s.charAt(4));

        ret += Integer.parseInt(time.toString());
        return ret;
    }

    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        List<PlanArr> arr = new ArrayList<>();
        Stack<StackPlan> stack = new Stack<>();

        int idx = 0;

        for (String[] plan : plans) {
            int time = changeTime(plan[1]);

            arr.add(new PlanArr(time, plan[0], Integer.parseInt(plan[2])));
        }

        Collections.sort(arr);

        PlanArr cur = arr.get(0);

        int curStartTime = cur.getStartTime();
        String curName = cur.getName();
        int curPlayTime = cur.getPlayTime();
        int curEndTime = curStartTime + curPlayTime;

        for (int i = 1; i < arr.size(); i++) {
            PlanArr next = arr.get(i);
            int nextStartTime = next.getStartTime();
            String nextName = next.getName();
            int nextPlayTime = next.getPlayTime();

            if (curEndTime < nextStartTime) {
                answer[idx++] = curName;

                //스택이 비어있으면
                if (stack.isEmpty()) {
                    curStartTime = nextStartTime;
                    curName = nextName;
                    curPlayTime = nextPlayTime;
                    curEndTime = curStartTime + curPlayTime;
                    continue;
                }

                //스택이 안비어있으면 스택에서 꺼낸다
                curStartTime = curEndTime;
                curName = stack.peek().getName();
                curPlayTime = stack.peek().getPlayTime();
                curEndTime = curStartTime + curPlayTime;

                stack.pop();
                i--; //해당 반복문 다시 돌기
                continue;
            }

            if (curEndTime > nextStartTime) {
                int time = curPlayTime - (nextStartTime - curStartTime);
                stack.push(new StackPlan(curName, time));

                curStartTime = nextStartTime;
                curName = nextName;
                curPlayTime = nextPlayTime;
                curEndTime = curStartTime + curPlayTime;
                continue;
            }

            if (curEndTime == nextStartTime) {
                answer[idx++] = curName;

                curStartTime = nextStartTime;
                curName = nextName;
                curPlayTime = nextPlayTime;
                curEndTime = curStartTime + curPlayTime;
            }
        }

        answer[idx++] = curName;

        while (!stack.isEmpty()) {
            answer[idx++] = stack.pop().getName();
        }

        return answer;
    }
}

class PlanArr implements Comparable<PlanArr>{
    int startTime; //시작 시간
    String name; //과목 이름
    int playTime; //플레이 시간

    PlanArr(int startTime, String name, int playTime) {
        this.startTime = startTime;
        this.name = name;
        this.playTime = playTime;
    }

    int getStartTime() {
        return startTime;
    }

    String getName() {
        return name;
    }

    int getPlayTime() {
        return playTime;
    }

    @Override
    public int compareTo(PlanArr o) {
        if (this.startTime < o.startTime) {
            return -1;
        }

        if (this.startTime > o.startTime) {
            return 1;
        }

        return 0;
    }
}

class StackPlan {
    String name; //과목 이름
    int playTime; //남은 시간

    StackPlan(String name, int playTime) {
        this.name = name;
        this.playTime = playTime;
    }

    String getName() {
        return name;
    }

    int getPlayTime() {
        return playTime;
    }
}