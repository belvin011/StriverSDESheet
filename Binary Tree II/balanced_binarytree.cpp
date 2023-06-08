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
int find(BinaryTreeNode<int>* root){
    if(root==nullptr) return 0;
    int left=find(root->left);
    int right=find(root->right);
    if(abs(left-right)>1 ||left==-1 || right==-1) return -1;
    return 1+max(left,right);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
         if(find(root)==-1) return false;
         else return true;
}
