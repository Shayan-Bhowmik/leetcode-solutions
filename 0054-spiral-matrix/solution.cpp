class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sRow = 0;
        int sCol = 0;
        int eRow = m-1;
        int eCol = n-1;

        vector<int> ans;

        while((sRow <= eRow) && (sCol <= eCol)) {
            for(int i=sCol; i<=eCol; i++) {
                ans.push_back(matrix[sRow][i]);
            }
            for(int j=sRow+1; j<=eRow; j++) {
                ans.push_back(matrix[j][eCol]);
            }
            for(int i=eCol-1; i>=sCol; i--) {
                if(sRow == eRow) {
                    break;
                }
                ans.push_back(matrix[eRow][i]);
            }
            for(int j=eRow-1; j>=sRow+1; j--) {
                if(sCol == eCol) {
                    break;
                }
                ans.push_back(matrix[j][sCol]);
            }
            sRow++;
            sCol++;
            eRow--;
            eCol--;
        }
        return ans;
    }
};