class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> rowCount(rows, 0);
        vector<int> colsCount(cols, 0);

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colsCount[j]++;
                }
            }
        }

        int count = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 1 && rowCount[i] == 1 && colsCount[j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};