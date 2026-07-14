class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int, int> rank;
        sort(ans.begin(), ans.end());

        int currentRank = 1;


        for(int i=0; i<ans.size(); i++) {
            if(i==0) {
                rank.insert({ans[i], currentRank});
            }
            else{
                if(ans[i] != ans[i-1]) {
                    currentRank++;
                    rank.insert({ans[i], currentRank});
                }
                else{
                    continue;
                }
            }
            
        }
        for(int i=0; i<arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};