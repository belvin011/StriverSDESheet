#include <bits/stdc++.h> 
bool findpath(TreeNode<int> *root,int x, vector<int>&ans){
	if(root==nullptr) return false;
	ans.push_back(root->data);
	if(root->data==x) return true;
	//findpath(root->left,x,ans);
	//findpath(root->right,x,ans);
	if(findpath(root->left,x,ans)==false and  findpath(root->right,x,ans)==false ){
		ans.pop_back();
	}
	else{
		return true;
	}
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
   vector<int>ans;
   findpath(root,x,ans);
   return ans;
}
