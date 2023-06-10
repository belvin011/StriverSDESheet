#include <bits/stdc++.h> 
//condition for the leaf nodes...
bool leaf(TreeNode<int>* root){
    if(root!=nullptr && root->left==nullptr && root->right==nullptr) return true;
    else return false;
}


//traversing throught the left nodes...
void leftnodes(TreeNode<int>* root, vector<int>&ans){
    TreeNode<int>* cur=root;
    while(cur){
        if(!leaf(cur)){
            ans.push_back(cur->data);
        }  
        cur=(cur->left) ? cur->left :cur->right;
    }
}

//traversing through the righnodes...
void rightnodes(TreeNode<int>* root, vector<int>&ans){
    vector<int>v;
    TreeNode<int>* cur=root;
    while(cur){
      if (!leaf(cur)) {
        v.push_back(cur->data);
      }
      cur = (cur->right) ? cur->right : cur->left;
    }
    for(int i=v.size()-1;i>=0;i--){
        ans.push_back(v[i]);
    }
}
//traversing through leafnodes...
void leafnodes(TreeNode<int>* root, vector<int>&ans){
    if(leaf(root)){
        ans.push_back(root->data);   
    }
    if(root->left) leafnodes(root->left,ans);
    if(root->right) leafnodes(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!leaf(root)) ans.push_back(root->data);
    leftnodes(root->left,ans);
    leafnodes(root,ans);
    rightnodes(root->right,ans);
    return ans;
}