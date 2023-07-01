#include <bits/stdc++.h> 
 bool findpath(TreeNode<int> *root, int x,vector<int>&ans){
     if(root==nullptr) return false;
     ans.push_back(root->data);
     if(root->data==x) return true;

     if(findpath(root->left,x,ans)==false && findpath(root->right,x,ans)==false) ans.pop_back();
     else return true;
 }

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    vector<int>ans1;
    vector<int>ans2;
    findpath(root,x,ans1);
    findpath(root,y,ans2);
    int i=0,j=0;
    
    while(i <ans1.size() && j<ans2.size()){
        if(ans1[i]!=ans2[j]){
            break;
        }
        else{
            i++;
            j++;
        }
    }
    return ans1[--i];
}




//optimal code..!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==nullptr && right==nullptr) return nullptr;
        if(left==nullptr && right!=nullptr) return right;
        else if(left!=nullptr && right==nullptr) return left;
        else return root;
    }
};