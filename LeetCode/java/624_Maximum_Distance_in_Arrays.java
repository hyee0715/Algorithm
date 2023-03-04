import java.util.List;

class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int answer = -1;
        int minNum = arrays.get(0).get(0);
        int maxNum = arrays.get(0).get(arrays.get(0).size() - 1);

        for (int i = 1; i < arrays.size(); i++) {
            int newDistance = Math.abs(minNum - arrays.get(i).get(arrays.get(i).size() - 1));

            if (answer < newDistance) {
                answer = newDistance;
            }

            newDistance = Math.abs(arrays.get(i).get(0) - maxNum);

            if (answer < newDistance) {
                answer = newDistance;
            }

            if (minNum > arrays.get(i).get(0)) {
                minNum = arrays.get(i).get(0);
            }

            if (maxNum < arrays.get(i).get(arrays.get(i).size() - 1)) {
                maxNum = arrays.get(i).get(arrays.get(i).size() - 1);
            }
        }

        return answer;
    }
}