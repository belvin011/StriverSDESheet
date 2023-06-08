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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    
    if(root==nullptr)
      return {};
    vector<int>ans;
    stack<TreeNode*>st;
    while(!st.empty() || root!=nullptr){
        if(root!=nullptr){
            st.push(root);
            root=root->left;
        }
        else{
            TreeNode* temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && st.top()->right==temp){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);

                }

            }
            else{
                root=temp;
            }
        }

    }
    return ans;

}