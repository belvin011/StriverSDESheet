#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(root==nullptr)
      return {};
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int even=0;
    while(!q.empty()){
        int n=q.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            BinaryTreeNode<int>*node=q.front();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            q.pop();
            v.push_back(node->data);
        }
        if(even%2==0){
            for(auto it:v) ans.push_back(it);
        }
        else{
            for(int i=v.size()-1;i>=0;i--){
                ans.push_back(v[i]);
            }
        }
        even++;
    }
    return ans;
}
