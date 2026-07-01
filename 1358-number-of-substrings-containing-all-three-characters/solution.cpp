class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left = 0; 
        int count=0;
        
        vector<int> ans(3,0);
        
        for(int i=0; i<s.size(); i++) {
            ans[s[i] - 'a']++;
            
            while(ans[0] && ans[1] && ans[2]) {
                count = count + (n-i);
                ans[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};