class Solution {
public:
        long long mod = 1e9 + 7;
        vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
            int n = A.size();

            vector<vector<long long>> C(n, vector<long long>(n, 0));

            for(int i=0; i<n; i++) {
                for(int k=0; k<n; k++) {
                    if(A[i][k] == 0) {
                        continue;
                    }
                    for(int j=0; j<n; j++) {
                        if(B[k][j] == 0) {
                            continue;
                        }

                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                    }
                }
            }
            return C;
        }

        vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
            int n = base.size();

            vector<vector<long long>> ans(n, vector<long long>(n,0));

            for(int i=0; i<n; i++) {
                ans[i][i] = 1;
            }

            while(exp) {
                if(exp&1) {
                    ans=multiply(ans, base);
                }
                base = multiply(base, base);
                exp>>=1;
            }
            return ans;
        }

        int zigZagArrays(int n, int l, int r) {
            int m = r-l+1;

            if(n==1) {
                return m;
            }

            int states=2*m;

            auto downId = [&](int x) {
                return x-1;
            };
            auto upId = [&](int x) {
                return m+x-1;
            };

            vector<vector<long long>> T(states, vector<long long>(states, 0));

            for(int x=1; x<=m; x++) {
                for(int y=1; y<x; y++) {
                    T[upId(y)][downId(x)] = 1;
                }

                for(int y=x+1; y<=m; y++) {
                    T[downId(y)][upId(x)] = 1;
                }
            }

            vector<long long> base(states, 0);
            for(int x=1; x<=m; x++) {
                base[downId(x)] = x-1;
                base[upId(x)] = m-x;
            }

            vector<vector<long long>> P = power(T, n-2);

            vector<long long> finalState(states, 0);

            for(int i=0; i<states; i++) {
                for(int j=0; j<states; j++) {
                    finalState[i] = (finalState[i] + P[i][j] * base[j]) % mod;
                }
            }

            long long ans=0;

            for(int i=0; i<states; i++) {
                ans=(ans+finalState[i])%mod;
            }

            return (int)ans;
        }
};