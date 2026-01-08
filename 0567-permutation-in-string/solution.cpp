class Solution {
public:

    bool isSameFreq(int freq1[], int freq2[]) {
        for(int i=0; i<26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0; i<s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windowSize = s1.length();
        for(int i=0; i<s2.length(); i++) {
            int windowIndex = 0;
            int index = i;
            int windowFreq[26] = {0};

            while(windowIndex < windowSize && index < s2.length()) {
                windowFreq[s2[index] - 'a']++;
                windowIndex++;
                index++;
            }

            if(isSameFreq(freq, windowFreq)) {
                return true;
            }
        }
        return false;
    }
};