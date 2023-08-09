class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> answer(grid.size(), vector<int>(grid[0].size()));

        vector<int> onesRow(grid.size());
        vector<int> zerosRow(grid.size());
        vector<int> onesCol(grid[0].size());
        vector<int> zerosCol(grid[0].size());

        for (int i = 0; i < grid.size(); i++) {
            int oneCnt = 0, zeroCnt = 0;

            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }
            }

            onesRow[i] = oneCnt;
            zerosRow[i] = zeroCnt;
        }

        for (int i = 0; i < grid[0].size(); i++) {
            int oneCnt = 0, zeroCnt = 0;
            
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == 0) {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }
            }

            onesCol[i] = oneCnt;
            zerosCol[i] = zeroCnt;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                answer[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return answer;
    }
};