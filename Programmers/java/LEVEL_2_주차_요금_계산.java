import java.util.*;

class Solution {
    private int getTime(String timeStr) {
        int time = 0;
        String[] times = timeStr.split(":");

        time += Integer.parseInt(times[0]) * 60;
        time += Integer.parseInt(times[1]);

        return time;
    }

    private int getFee(int time, int basicTime, int basicFee, int unitTime, int unitFee) {
        //기본 시간 이하면 기본 요금 청구
        if (time <= basicTime) {
            return basicFee;
        }

        int finalFee = basicFee;

        int n = 0;
        if ((time - basicTime) % unitTime != 0) {
            n = (((time - basicTime) / unitTime) + 1) * unitFee;
        } else {
            n = ((time - basicTime) / unitTime) * unitFee;
        }

        return finalFee + n;
    }

    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        List<Integer> answerList = new ArrayList<>();

        int basicTime = fees[0]; //기본 시간
        int basicFee = fees[1]; //기본 요금
        int unitTime = fees[2]; //단위 시간
        int unitFee = fees[3]; //단위 요금

        Map<Integer, List<Integer>> inMap = new HashMap<>(); //입차 기록 (차량 번호, 시간/분)
        Map<Integer, List<Integer>> outMap = new HashMap<>(); //출차 기록 (차량 번호, 시간/분)
        Map<Integer, Integer> parkingTime = new TreeMap<>(); //각 차 누적 주차시간

        for (String record : records) {
            String[] splitRecord = record.split(" ");

            int carNumber = Integer.parseInt(splitRecord[1]); //차량 번호

            int time = getTime(splitRecord[0]); //각 차의 시간 정보

            if (splitRecord[2].equals("IN")) {

                if (!inMap.containsKey(carNumber)) {
                    inMap.put(carNumber, new ArrayList<>());
                }

                inMap.get(carNumber).add(time);
            } else {
                if (!outMap.containsKey(carNumber)) {
                    outMap.put(carNumber, new ArrayList<>());
                }

                outMap.get(carNumber).add(time);
            }
        }

        //각 차 누적 주차시간 구하기
        for (int key : inMap.keySet()) {
            List<Integer> parkInTimes = inMap.get(key);
            int outNightTime = 23 * 60 + 59;

            if (!outMap.containsKey(key)) {
                //입차는 있는데 출차가 없는 경우
                int totalParkingTime = outNightTime - parkInTimes.get(0);
                parkingTime.put(key, totalParkingTime);
            } else if (outMap.get(key).size() != parkInTimes.size()) {
                //입 출차 여러 번, 마지막에 입차하고 출차가 없는 경우
                List<Integer> parkOutTimes = outMap.get(key);
                int totalParkingTime = 0;

                for (int i = 0; i < parkInTimes.size() - 1; i++) {
                    totalParkingTime += (parkOutTimes.get(i) - parkInTimes.get(i));
                }

                totalParkingTime += outNightTime - parkInTimes.get(parkInTimes.size() - 1);

                parkingTime.put(key, totalParkingTime);
            } else {
                //입차도 있고 출차 기록도 있는 경우
                List<Integer> parkOutTimes = outMap.get(key);
                int totalParkingTime = 0;

                for (int i = 0; i < parkInTimes.size(); i++) {
                    totalParkingTime += (parkOutTimes.get(i) - parkInTimes.get(i));
                }

                parkingTime.put(key, totalParkingTime);
            }
        }

        //최종 주차요금 구하기
        for (int key : parkingTime.keySet()) {
            int finalTime = parkingTime.get(key);
            answerList.add(getFee(finalTime, basicTime, basicFee, unitTime, unitFee));
        }

        answer = new int[answerList.size()];

        for (int i = 0; i < answerList.size(); i++) {
            answer[i] = answerList.get(i);
        }

        return answer;
    }
}