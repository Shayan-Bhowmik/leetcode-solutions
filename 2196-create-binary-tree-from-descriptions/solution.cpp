/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d){

        int root;

        unordered_map<int,pair<int,int>>mp;
        unordered_set<int>st;
        
        for(auto ele:d){

            int parent=ele[0];
            int child=ele[1];
            int lr=ele[2];

            st.insert(child);

            if(mp.find(parent)==mp.end()) mp[parent]={0,0};
            if(mp.find(child)==mp.end()) mp[child]={0,0};

            if(lr==1) mp[parent].first=child;
            else mp[parent].second=child;

        }

        for(auto ele:d){
            if(st.find(ele[0])==st.end()){
                root=ele[0];
                break;
            }
        }

        TreeNode* r=new TreeNode(root);

        queue<TreeNode*>q;
        q.push(r);

        while(q.size()){

            TreeNode* m=q.front();
            q.pop();

            if(mp[m->val].first!=0){
                TreeNode* lef=new TreeNode(mp[m->val].first);
                m->left=lef;
                q.push(lef);
            }

            if(mp[m->val].second!=0){
                TreeNode* rgh=new TreeNode(mp[m->val].second);
                m->right=rgh;
                q.push(rgh);
            }
        }

        return r;

    }
};