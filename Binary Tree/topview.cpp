#include <bits/stdc++.h> 


vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==nullptr)
      return {};
    vector<int>ans;
    queue<pair<TreeNode<int>*,int>>q;
    int vertical=0;
    q.push({root,vertical});
    map<int,int>mpp;
    while(!q.empty()){
        auto it =q.front();
        q.pop();
        TreeNode<int> *node=it.first;
        int vertical=it.second;
        if(mpp.find(vertical)==mpp.end()){
            mpp[vertical]=node->val;
        }
        if(node->left) q.push({node->left,vertical-1});
        if(node->right) q.push({node->right,vertical+1});
        
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
    
}