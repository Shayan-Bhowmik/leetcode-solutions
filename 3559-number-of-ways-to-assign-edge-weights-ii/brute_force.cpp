class Solution {
public:
    vector<int>per;
   const int MOD=1e9+7;

int power(long long a,long long b){
    long long ans=1;
    a%=MOD;
    while(b>0){
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }

    return (int)ans;
}
    int countWays(int d){
        if(d==0)return 0;
        return power(2,d-1);
    }

    void dfs(int node,int p,vector<vector<int>>&adj){
        for(auto&it:adj[node]){
            if(it!=p){
                per[it]=node;
                dfs(it,node,adj);
                }
        }
    }

    int dist(int a,int b){
    vector<int>x,y;
    while(true){
        x.push_back(a);
        if(per[a]==a)break;
        a=per[a];
    }
    while(true){
        y.push_back(b);
        if(per[b]==b)break;
        b=per[b];
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int i=0,j=0;
    while(i<x.size() && j<y.size() && x[i]==y[j]){
        i++;
        j++;
    }
    int calc=(x.size()-i)+(y.size()-j);
    return countWays(calc);
}

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        per.resize(n,0);
        for(int i=0;i<n;i++)per[i]=i;
        dfs(1,-1,adj);
        per[1]=1;
        vector<int>ans;
        for(auto& q:queries){
            int u=q[0],v=q[1];
            ans.push_back(dist(u,v));
        }
        return ans;
    }
};