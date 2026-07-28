
struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        int lg = std::bit_width((unsigned)n);
        st.assign(lg, vector<int>(n));
        st[0] = nums;
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j],
                               st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        int k = std::bit_width((unsigned)(r - l + 1)) - 1;
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int ones = ranges::count(s, '1');

        auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        SparseTable st(getZeroMergeLengths(zeroGroups));

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int left = zeroGroupIndex[l] == -1
                           ? -1
                           : zeroGroups[zeroGroupIndex[l]].length -
                                 (l - zeroGroups[zeroGroupIndex[l]].start);

            int right = zeroGroupIndex[r] == -1
                            ? -1
                            : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            auto [L, R] = mapToAdjacentGroupIndices(
                zeroGroupIndex[l] + 1,
                s[r] == '1' ? zeroGroupIndex[r]
                            : zeroGroupIndex[r] - 1);

            int cur = ones;

            if (s[l] == '0' && s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                cur = max(cur, ones + left + right);
            } else if (L <= R) {
                cur = max(cur, ones + st.query(L, R));
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <=
                    (s[r] == '1' ? zeroGroupIndex[r]
                                 : zeroGroupIndex[r] - 1)) {
                cur = max(cur,
                          ones + left +
                              zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
                cur = max(cur,
                          ones + right +
                              zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(cur);
        }

        return ans;
    }

private:
    pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
        vector<Group> groups;
        vector<int> idx;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    groups.back().length++;
                else
                    groups.push_back({i, 1});
            }
            idx.push_back((int)groups.size() - 1);
        }

        return {groups, idx};
    }

    vector<int> getZeroMergeLengths(const vector<Group>& groups) {
        vector<int> res;
        for (int i = 0; i + 1 < groups.size(); i++)
            res.push_back(groups[i].length + groups[i + 1].length);
        return res;
    }

    pair<int, int> mapToAdjacentGroupIndices(int l, int r) {
        return {l, r - 1};
    }
};