class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);
        vector<int> ans(m);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        bool used = false;
        j = 0;

        for (i = 0; i < n; i++) {
            if (j == m)
                break;

            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            else if (!used && (j == m - 1 || i < last[j + 1])) {
                ans[j] = i;
                j++;
                used = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};