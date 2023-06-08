#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode

    
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    if(root==nullptr)
      return {};
    // Write your code here.
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        
    }
    return ans;
}