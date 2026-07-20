class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        for (char c : s)
            freq[c - 'a']++;

        string st;

        for (char c : s) {
            freq[c - 'a']--;

            if (visited[c - 'a'])
                continue;

            while (!st.empty() &&
                   c < st.back() &&
                   freq[st.back() - 'a'] > 0) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }

        return st;
    }
};