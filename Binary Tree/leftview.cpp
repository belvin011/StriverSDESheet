#include <bits/stdc++.h> 
void find(int i, vector<int>&ans,TreeNode<int> *root){
    if(root==nullptr) return;
    if(ans.size()==i){
        ans.push_back(root->data);
    }
    if(root->left) find(i+1,ans,root->left);
     if(root->right) find(i+1,ans,root->right);
    
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root==nullptr)
      return {};
    int i=0;
    vector<int>ans;
    find(i,ans,root);
    return ans;
}