class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    
        int netGain = 0;
        int n = gain.size();
        int highGain = 0;

        for(int i=0; i<n; i++) { 
            
            netGain += gain[i];
           highGain = max(highGain, netGain);
        }

        return highGain;
    }
};